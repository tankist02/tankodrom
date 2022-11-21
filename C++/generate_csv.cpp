#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    size_t lines = 100 * 1000; // 100 thousand lines by default
    size_t tokens = 1000; // 1 thousand tokens per line by default

    if (argv[1])
    {
        lines = atol(argv[1]);

        if (argv[2])
        {
            tokens = atol(argv[2]);
        }
    }

    std::cout << "lines: " << lines << ", tokens per line: " << tokens << std::endl;

    std::ofstream ofs("test.csv");
    if (!ofs)
    {
        std::cerr << "Failed to open file: test.csv for writing, error: " << strerror(errno) << std::endl;
        return -1;
    }

    for (size_t l = 0; l < lines; ++l)
    {
        ofs << "line" << (l + 1);
        for (size_t t = 0; t < tokens; ++t)
        {
            ofs << ",token" << (t + 1);
        }
        ofs << "\n";
    }

    return 0;
}

