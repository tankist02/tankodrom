#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    fs::path p("test.text");
    if (fs::exists(p))
    {
        std::cout << "path: " << p << " exists\n";
    }
    else
    {
        std::cout << "path: " << p << " does not exist\n";
    }
    return 0;
}

