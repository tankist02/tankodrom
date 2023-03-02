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

// Find string in content
void findStrings(Strings const& sstf, std::string const& content, Strings& found)
{
    //std::cout << "thread id: " << std::this_thread::get_id() << ", sstf size: " << sstf.size() << std::endl;
    for (auto const& e : sstf)
    {
        if (content.find(e) != std::string::npos)
        {
            std::lock_guard<std::mutex> lock(my_mutex);
            found.push_back(e);
            //std::cout  << "thread id: " << std::this_thread::get_id() << ", found: " << e << '\n';
        }
    }
}

// Find strings in sstf as substrings in content
// Put found strings into found
void find(Strings const& sstf, std::string const& content, Strings& found)
{
    //Threads ts;
    //ts.push_back(std::jthread(findStrings, std::ref(sstf1), std::ref(content), std::ref(found)));
    //ts.push_back(std::jthread(findStrings, std::ref(sstf2), std::ref(content), std::ref(found)));
    //std::for_each(ts.begin(), ts.end(), [](auto& t) { t.join(); });
    auto middle = sstf.begin() + sstf.size() / 2;
    Strings sstf1(sstf.begin(), middle);
    Strings sstf2(middle, sstf.end());
    std::jthread t1(findStrings, std::ref(sstf1), std::ref(content), std::ref(found));
    std::jthread t2(findStrings, std::ref(sstf2), std::ref(content), std::ref(found));
    t1.join();
    t2.join();
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
    std::cout << "Number of found strings: " << found.size() << ", time to find: " << double(s) / CLOCKS_PER_SEC << std::endl;

    return 0;
}

