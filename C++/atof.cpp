#include <iostream>

int main(int argc, char* argv[])
{
    std::cout.precision(16);
    std::cout.setf(std::ios_base::scientific);
    for (int i = 1; i < argc; ++i)
    {
        double res = atof(argv[i]);
        std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
    }

    for (int i = 1; i < argc; ++i)
    {
        double res = std::stod(argv[i]);
        std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
    }

    for (int i = 1; i < argc; ++i)
    {
        auto res = std::stold(argv[i]);
        std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
    }
}

