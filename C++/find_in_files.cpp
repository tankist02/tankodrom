#include <algorithm>
#include <execution>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <cerrno>
#include <cstring>

using Strings = std::set<std::string>;

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string const& content, Strings& found)
{
    for (auto const& s : sstf)
    {
        if (content.find(s) != std::string::npos)
        //if (std::search(content.begin(), content.end(), 
          //  std::default_searcher{s.begin(), s.end()}) != content.end())
            //std::boyer_moore_searcher{s.begin(), s.end()}) != content.end())
        //if (std::search(std::execution::par, content.begin(), content.end(), s.begin(), s.end()) != content.end())
        {
            found.insert(s);
        }
    }
}

// Takes optional input file name and strings to find
int main(int argc, char* argv[])
{
    std::string fname = "test.text";
    if (argv[1]) { fname = argv[1]; }
    std::cout << "fname: " << fname << std::endl;

    // Default strings to find
    Strings sstf {"line", "Line"};
    for (int i = 2; i < argc; ++i)
    {
        sstf.insert(argv[i]);
    }

    clock_t s = clock();
    std::ifstream ifs(fname);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << fname << " for reading, error: " << strerror(errno) << std::endl;
        return -1;
    }
    // Load input file into buffer
    std::stringstream ss;
    ss << ifs.rdbuf();
    std::string content = ss.str();
    auto size = content.size();
    s = clock() - s;
    std::cout << "Content length: " << size << ", time to load: " << double(s) / CLOCKS_PER_SEC << std::endl;

    s = clock();
    Strings found;
    find(sstf, content, found);
    s = clock() - s;
    std::cout << "Found: ";
    for (auto const& e : found) { std::cout << e << " "; }
    std::cout << "\nTime to find: " << double(s) / CLOCKS_PER_SEC << std::endl;

    return 0;
}

