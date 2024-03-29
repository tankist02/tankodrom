#include <algorithm>
#include <execution>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <cstring>

using Strings = std::vector<std::string>;

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

int loadFile(std::string const& fname, std::string& content)
{
    clock_t s = clock();
    std::ifstream ifs(fname, ifs.binary);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << fname << " for reading, error: " << strerror(errno) << std::endl;
        return -1;
    }

    // Load input file into buffer
    ifs.seekg(0, ifs.end);
    content.resize(ifs.tellg(), 0);
    ifs.seekg(0);
    ifs.read(content.data(), content.size());
    s = clock() - s;
    std::cout << "File to search size: " << content.size() << ", time to load: " << double(s) / CLOCKS_PER_SEC << std::endl;
    return 0;
}

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string_view const& content, Strings& found)
{
    for (auto const& s : sstf)
    {
        if (content.find(s) != std::string::npos)
        //if (std::search(content.begin(), content.end(), 
          //  std::default_searcher{s.begin(), s.end()}) != content.end())
            //std::boyer_moore_searcher{s.begin(), s.end()}) != content.end())
        //if (std::search(std::execution::par, content.begin(), content.end(), s.begin(), s.end()) != content.end())
        {
            found.push_back(s);
        }
    }
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
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file_to_search> <strings_to_find>\n";
        exit(-1);
    }
    std::string fname = argv[1];
    std::string to_find = argv[2];
    std::cout << "File to search: " << fname << ", strings to find: " << to_find << std::endl;

    Strings sstf;
    loadStrings(to_find, sstf);

    std::string content;
    if (loadFile(fname, content) != 0) { return -1; }

    clock_t s = clock();
    Strings found;
    find(sstf, content, found);
    //findC(sstf, content.c_str(), found);
    s = clock() - s;
    std::cout << "Number of found strings: " << found.size() << ", time to find: " << double(s) / CLOCKS_PER_SEC << std::endl;

    return 0;
}

