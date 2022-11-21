#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char* argv[])
{
    std::ifstream ifs("test.csv");
    if (!ifs)
    {
        std::cerr << "Failed to open file: test.csv for reading, error: " << strerror(errno) << std::endl;
        return -1;
    }

    std::string line;

    size_t tokens = 0;
    //std::list<std::string> list;
    std::vector<std::string> list;

    /*size_t lines = 0;
    while (std::getline(ifs, line))
    {
        ++lines;
        list.push_back(line);

        for (char const* p = line.c_str(); p; p = strchr(p, ','))
        {
            ++p;
            ++tokens;
        }
    }

    std::cout << "lines: " << lines << ", tokens: " << tokens << std::endl;*/

    size_t lines = 0;
    while (std::getline(ifs, line))
    {
        ++lines;
        list.push_back(line);
    }
    std::cout << "lines: " << lines << std::endl;

    for (auto const& l : list)
    {
        for (char const* p = l.c_str(); *p; ++p) //p = strchr(p, ','))
        {
            //++p;
            //++tokens;
            if (*p == ',')
            {
                ++tokens;
            }
        }
        ++tokens;
    }

    std::cout << "tokens: " << tokens << std::endl;

    return 0;
}

