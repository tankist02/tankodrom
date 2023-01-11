#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    std::cout << "Hello, world!\n";

    try
    {
        std::vector<double> vd;
        vd.resize(-1);
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
        abort();
    }
}

