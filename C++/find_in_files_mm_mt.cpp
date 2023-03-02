#include <algorithm>
#include <execution>
#include <functional>
#include <iostream>
#include <fstream>
#include <span>
#include <sstream>
#include <string>
#include <mutex>
#include <thread>
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

using Strings = std::vector<std::string>;
using StrSpan = std::span<std::string const>;
using Threads = std::vector<std::jthread>;
std::mutex my_mutex;

void loadStrings(std::string const& fname, Strings& toFind)
{
    std::ifstream ifs(fname);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << fname << " for reading, error: " << strerror(errno) << std::endl;
        exit(-1);
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        toFind.push_back(line);
    }
    std::cout << "Number of strings to find: " << toFind.size() << std::endl;
}

char* loadFile(char const* fname, size_t& size)
{
    int fd = open(fname, O_RDONLY);
    if (fd < 0)
    {
        std::cerr << "Failed to open file: " << fname << ", error: " << strerror(errno) << std::endl;
        return nullptr;
    }
    struct stat st;
    if (fstat(fd, &st) < 0)
    {
        std::cerr << "Failed to stat file: " << fname << ", error: " << strerror(errno) << std::endl;
        return nullptr;
    }
    char* buf = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED)
    {
        std::cerr << "mmap failed, error: " << strerror(errno) << std::endl;
        close(fd);
        return nullptr;
    }
    close(fd);
    size = st.st_size;
    return buf;
}

// Find strings in sstf as substrings in content
// Put found strings into found
void findStrings(Strings const& sstf, std::string_view const& content, Strings& found)
{
    for (auto const& s : sstf)
    {
        if (content.find(s) != std::string::npos)
        //if (std::search(content.begin(), content.end(), 
          //  std::default_searcher{s.begin(), s.end()}) != content.end())
            //std::boyer_moore_searcher{s.begin(), s.end()}) != content.end())
        //if (std::search(std::execution::par, content.begin(), content.end(), s.begin(), s.end()) != content.end())
        {
            std::lock_guard<std::mutex> lock(my_mutex);
            found.push_back(s);
        }
    }
}

void findStringsSpan(StrSpan sstf, std::string_view const& content, Strings& found)
{
    for (auto const& s : sstf)
    {
        if (content.find(s) != std::string::npos)
        //if (std::search(content.begin(), content.end(), 
          //  std::default_searcher{s.begin(), s.end()}) != content.end())
            //std::boyer_moore_searcher{s.begin(), s.end()}) != content.end())
        //if (std::search(std::execution::par, content.begin(), content.end(), s.begin(), s.end()) != content.end())
        {
            std::lock_guard<std::mutex> lock(my_mutex);
            found.push_back(s);
        }
    }
}

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string_view const& content, int threads, Strings& found)
{
    //Threads ts;
    //ts.push_back(std::jthread(findStrings, std::ref(sstf1), std::ref(content), std::ref(found)));
    //ts.push_back(std::jthread(findStrings, std::ref(sstf2), std::ref(content), std::ref(found)));
    //std::for_each(ts.begin(), ts.end(), [](auto& t) { t.join(); });
    //auto middle = sstf.begin() + sstf.size() / 2;
    //Strings sstf1(sstf.begin(), middle);
    //Strings sstf2(middle, sstf.end());
    //std::jthread t1(findStrings, std::cref(sstf1), std::cref(content), std::ref(found));
    //std::jthread t2(findStrings, std::cref(sstf2), std::cref(content), std::ref(found));
    /*auto size = sstf.size() / 2;
    StrSpan ss1{sstf.begin(), size};
    StrSpan ss2{sstf.begin() + size, size};
    std::jthread t1(findStringsSpan, ss1, std::cref(content), std::ref(found));
    std::jthread t2(findStringsSpan, ss2, std::cref(content), std::ref(found));
    t1.join();
    t2.join();*/

    auto size = std::max(sstf.size() / threads, 1lu);
    Threads ts;
    for (auto beg = sstf.begin(); beg < sstf.end(); beg += size)
    {
        StrSpan sp{beg, size};
        ts.push_back(std::jthread(findStringsSpan, sp, std::cref(content), std::ref(found)));
    }
    for (auto& t : ts) { t.join(); }
}

void findC(Strings const& sstf, char const* content, Strings& found)
{
    for (auto const& s : sstf)
    {
        if (strstr(content, s.c_str()))
        {
            found.push_back(s);
        }
    }
}

// Takes optional input file name and strings to find
int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <file_to_search> <strings_to_find> <threads_num>\n";
        exit(-1);
    }
    std::string fname = argv[1];
    std::string to_find = argv[2];
    int threads = atoi(argv[3]);
    std::cout << "File to search: " << fname << ", strings to find: " << to_find << std::endl;

    Strings sstf;
    loadStrings(to_find, sstf);

    size_t size;
    char* content = loadFile(fname.c_str(), size);
    if (content == nullptr) { return -1; }
    std::cout << "File to search size: " << size << std::endl;

    Strings found;
    find(sstf, std::string_view(content, size), threads, found);
    //findC(sstf, content, found);
    if (munmap(content, size) != 0)
    {
        std::cerr << "Failed to munmap, error: " << strerror(errno) << std::endl;
    }
    std::cout << "Number of found strings: " << found.size() << std::endl;

    return 0;
}

