#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    /*fs::path p(argv[1] ? argv[1] : "test.text");
    if (fs::exists(p))
    {
        std::cout << "path: " << p << " exists\n";
    }
    else
    {
        std::cout << "path: " << p << " does not exist\n";
    }
    if (fs::is_regular_file(p))
    {
        std::cout << p << " is file, size: " << fs::file_size(p) << "\n";
    }
    else if (fs::is_directory(p))
    {
        std::cout << p << " is directory containing:\n";
        for (auto const& e : fs::directory_iterator{p})
        {
            std::cout << '\t' << e.path() << '\n';
        }
    }*/
    
    switch (fs::path p{argv[1]}; status(p).type())
    {
        case fs::file_type::not_found:
                std::cout << "path: " << p.string() << " does not exist\n";
            break;

        case fs::file_type::regular:
                std::cout << "path: " << p.string() << " is regular file, size: " << file_size(p) << "\n";
            break;

        case fs::file_type::directory:
            std::cout << p.string() << " is directory containing:\n";
            for (auto const& e : fs::directory_iterator{p})
            {
                std::cout << '\t' << e.path().string() << '\n';
            }
            std::cout << p.string() << "lexically normal:\n";
            for (auto const& e : fs::directory_iterator{p})
            {
                std::cout << '\t' << e.path().lexically_normal().string() << '\n';
            }
            break;

        default:
            std::cout << p.string() << " is a special file\n";
    }
    return 0;
}

