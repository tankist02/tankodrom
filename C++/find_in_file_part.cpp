#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using Found = std::pair<std::string, size_t>;
using Patterns = std::vector<std::pair<std::string, size_t>>;

size_t loadPatterns(std::string const& fname, Patterns& toFind)
{
    std::ifstream ifs(fname);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << fname << " for reading, error: " << strerror(errno) << std::endl;
        exit(-1);
    }
    std::string line;
    size_t maxlen = 0;
    while (std::getline(ifs, line))
    {
        toFind.push_back({line, 0});
        if (line.size() > maxlen) { maxlen = line.size(); }
    }
    return maxlen;
}

int index(const char* text, const char* pattern) {
    if (!text || !*text) { return -1; }
    unsigned long state = 0;
    unsigned long mask [256] = {0};
    int patlen = strlen(pattern);
    // Pattern is too short or too long
    if (patlen == 0 || patlen > 63) {
        return -1;
    }
    // Initialize mask table for each letter in the pattern
    for (int i = 0; i < patlen; i++) {
	    unsigned int ind = pattern[i] & 0xff;
        mask[ind] = mask[ind] | (1 << i);
    }
    int textlen = strlen(text);
    for (int i = 0; i < textlen; i++) {
        // Update state by shifting it and masking with the record from table
	    unsigned int ind = text[i] & 0xff; 
        state = (state << 1) + 1;
        state = state & mask[ind];
        if ((state & (1 << (patlen - 1))) != 0) {
            // It's a match!
            return (i - patlen + 1);
        }
    }
    // No match found
    return -1;
}

size_t search(std::string const& buf, std::string const& pat)
{
    size_t found = 0;
    // C standard search
    /* About 2 times slower than std::string::find
    char const* pos = buf.c_str();
    while ((pos = strstr(pos, pat.c_str())) != nullptr)
    {
        ++found;
        ++pos;
    }
    */
    // C++ standard search - the fastest for not very long patterns
    size_t pos = 0;
    while ((pos = buf.find(pat, pos)) != std::string::npos)
    {
        ++found;
        ++pos;
    }
    // ShiftOr search found and implemented by Kolya
    /* Very slow
    int ind;
    char const* p = buf.c_str();
    while ((ind = index(p, pat.c_str())) != -1)
    {
        ++found;
        p += (ind + 1);
    }
    */
    return found;
}

void searchAll(std::string const& buf, Patterns& patterns)
{
    for (auto& e : patterns)
    {
        size_t found = search(buf, e.first);
        e.second += found;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <file> <bufsize> <patterns_file>" << std::endl;
        return -1;
    }

    std::string fname = argv[1];
    size_t bufSize = atoi(argv[2]);
    std::string pname = argv[3];

    Patterns toFind;
    size_t psize = loadPatterns(pname, toFind);

    if (bufSize < psize)
    {
        std::cerr << "bufSize (" << bufSize << ") must be greater than longest pattern length (" << psize << ")\n";
        return -1;
    }

    std::cout << "fname: " << fname << ", bufSize: " << bufSize << ", patterns: " << toFind.size() << ", psize: " << psize << std::endl;

    int fd = open(fname.c_str(), O_RDONLY);
    if (fd < 0)
    {
        std::cerr << "Failed to open file: " << fname << ", error: " << strerror(errno) << std::endl;
        return -1;
    }

    struct stat st;
    fstat(fd, &st);

    size_t patSize = psize - 1; // Overlap size to ensure to find patterns that straddle buf boundary
    std::string buffer(bufSize, 0);
    ssize_t rd, total = 0;
    /* Rewind file back a little to handle pattern potentially straddling buffer border
    while ((rd = read(fd, buffer.data(), bufSize)) > 0)
    {
        //std::cout << "rd: " << rd << std::endl;
        buffer.resize(rd);
        std::cout << "rd: " << rd << ", buffer: " << buffer << std::endl;
        searchAll(buffer, toFind);

        // Calculate total read size to know when to stop reading
        total += rd;
        if (total >= st.st_size) { break; }

        // Rewind back a bit to include potential pattern that straddles buf reads boundary
        lseek(fd, -patSize, SEEK_CUR);
        total -= patSize;
    }*/

    // Copy part of buffer end to begin to handle pattern potentially straddling buffer border
    size_t offset = 0;
    while ((rd = read(fd, buffer.data() + offset, bufSize - offset)) > 0)
    {
        buffer.resize(rd + offset);
        //std::cout << "rd: " << rd << ", offset: " << offset << ", buf: " << buffer << std::endl;
        searchAll(buffer, toFind);

        // Move buffer boundary
        memcpy(buffer.data(), buffer.data() + rd - patSize + offset, patSize);
        //std::cout << "buf: " << buffer << std::endl;
        offset = patSize;
        total += rd;
    }
    std::cout << "total: " << total << std::endl;

    close(fd);
    for (auto const& e : toFind) { std::cout << e.first << ": " << e.second << std::endl; }
}

