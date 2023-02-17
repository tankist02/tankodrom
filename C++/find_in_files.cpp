#include <algorithm>
#include <execution>
#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <sstream>
#include <set>
#include <string>
#include <cerrno>
#include <cstring>

using Strings = std::set<std::string>;
using Threads = std::vector<std::thread>;
std::mutex my_mutex;

// Find string in content
void findString(std::string const& stf, std::string const& content, Strings& found)
{
    if (content.find(stf) != std::string::npos)
    {
        //std::lock_guard<std::mutex> lock(my_mutex);
        found.insert(stf);
    }
}

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string const& content, Strings& found)
{
    //Threads ts;
    for (auto const& s : sstf)
    {
        //ts.push_back(std::thread(findString, std::ref(s), std::ref(content), std::ref(found)));
        if (content.find(s) != std::string::npos)
        {
            found.insert(s);
        }
    }
    //std::for_each(ts.begin(), ts.end(), [](auto& t) { t.join(); });
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
        // Create strings that won't be found
        std::string temp(argv[i]);
        if (!temp.empty()) { temp[0] = std::toupper(temp[0]); }
        sstf.insert(temp);
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

