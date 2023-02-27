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

size_t search(std::string const& buf, std::string const& pat)
{
    size_t found = 0;
    char const* pos = buf.c_str();
    while ((pos = strstr(pos, pat.c_str())) != nullptr)
    {
        ++found;
        ++pos;
    }
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

    std::cout << "fname: " << fname << ", bufSize: " << bufSize << ", patterns: " << toFind.size() << std::endl;

    int fd = open(fname.c_str(), O_RDONLY);
    if (fd < 0)
    {
        std::cerr << "Failed to open file: " << fname << ", error: " << strerror(errno) << std::endl;
        return -1;
    }

    struct stat st;
    fstat(fd, &st);

    size_t patSize = psize - 1;
    std::string buffer(bufSize, 0);
    ssize_t rd, total = 0;
    while ((rd = read(fd, buffer.data(), bufSize)) > 0)
    {
        //std::cout << "rd: " << rd << std::endl;
        buffer.resize(rd);
        //std::cout << "buffer:\n" << buffer << std::endl;
        searchAll(buffer, toFind);

        // Calculate total read size to know when to stop reading
        total += rd;
        if (total >= st.st_size) { break; }

        // Rewind back to include potential pattern that straddles buf reads
        lseek(fd, -patSize, SEEK_CUR);
        total -= patSize;
    }
    close(fd);
    for (auto const& e : toFind) { std::cout << e.first << ": " << e.second << std::endl; }
}

