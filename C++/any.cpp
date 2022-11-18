#include <iostream>
#include <any>

std::ostream& operator<<(std::ostream& os, std::pair<int, int> const& p)
{
    os << p.first << ',' << p.second << std::endl;
    return os;
}

int main(int /*argc*/, char** /*argv*/)
{
    try
    {
        std::any a = 123;
        std::cout << "int: " << std::any_cast<int>(a) << std::endl;
        a = 123.456;
        std::cout << "double: " << std::any_cast<double>(a) << std::endl;
        a = "Hello, world!";
        std::cout << "char const*: " << std::any_cast<char const*>(a) << std::endl;
        a = std::string("Bye, World!");
        std::cout << "std::string: " << std::any_cast<std::string>(a) << std::endl;
        a = std::pair<int, int>{1, 2};
        std::cout << "std::pair<int, int>: " << std::any_cast<std::pair<int, int>>(a) << std::endl;
        return 0;
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
    return -1;
}

