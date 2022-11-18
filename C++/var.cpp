#include <iostream>
#include <variant>

int main(int, char**)
{
    try
    {
        std::variant<char, int, double> v{'a'};
        std::cout << "char: " << std::get<char>(v) << std::endl;
        std::cout << "char: " << std::get<0>(v) << std::endl;
        //std::cout << "char: " << std::get<int>(v) << std::endl;
        v = 123.456;
        std::cout << "int: " << std::get<double>(v) << std::endl;
        //std::cout << "int: " << std::get<int>(v) << std::endl;
        return 0;
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
    return -1;
}

