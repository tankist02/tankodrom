#include <algorithm>
#include <execution>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include <sstream>
#include <string>
#include <vector>
#include <cerrno>
#include <cstring>

using Strings = std::vector<std::string>;
using Threads = std::vector<std::thread>;
std::mutex my_mutex;

// Find string in content
void findString(std::string const& stf, std::string const& content, Strings& found)
{
    if (content.find(stf) != std::string::npos)
    {
        std::lock_guard<std::mutex> lock(my_mutex);
        found.push_back(stf);
    }
}

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string const& content, Strings& found)
{
    Threads ts;
    for (auto const& s : sstf)
    {
        ts.push_back(std::thread(findString, std::ref(s), std::ref(content), std::ref(found)));
        if (content.find(s) != std::string::npos)
        {
            found.push_back(s);
        }
    }
    std::for_each(ts.begin(), ts.end(), [](auto& t) { t.join(); });
}

// Takes optional input file name and strings to find
int main(int argc, char* argv[])
{
    std::string fname = "test.text";
    if (argv[1]) { fname = argv[1]; }
    std::cout << "fname: " << fname << std::endl;

    // Default strings to find
    Strings sstf;
    for (int i = 2; i < argc; ++i)
    {
        sstf.push_back(argv[i]);
    }

    clock_t s = clock();
    std::ifstream ifs(fname);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << fname << " for reading, error: " << strerror(errno) << std::endl;
        return -1;
    }

    // Load input file into buffer
    ifs.seekg(0, ifs.end);
    std::string content(ifs.tellg(), 0);
    ifs.seekg(0);
    ifs.read(content.data(), content.size());
    s = clock() - s;
    std::cout << "Content length: " << content.size() << ", time to load: " << double(s) / CLOCKS_PER_SEC << std::endl;

    s = clock();
    Strings found;
    find(sstf, content, found);
    /*std::for_each(
        std::execution::par,
        //std::execution::par_unseq,
        sstf.begin(), 
        sstf.end(), 
        [&](auto const& s) {if (content.find(s) != std::string::npos) { found.insert(s); }});*/
    s = clock() - s;
    for (auto const& e : found) { std::cout << e << " "; }
    std::cout << "\nTime to find: " << double(s) / CLOCKS_PER_SEC << std::endl;

    return 0;
}

