#include <iostream>
#include <boost/multiprecision/cpp_int.hpp> 

using namespace boost::multiprecision;

cpp_int fib(int place)
{
    cpp_int a = 0;
    cpp_int b = 1;
    while (place-- > 1)
    {
        cpp_int t {b + a};
        std::swap(a, b);
        std::swap(b, t);
    }
    return b;
}

int main(int argc, char* argv[])
{
    int num = 250000;
    if (argv[1]) { num = std::stoi(argv[1]); }

    clock_t t = clock();
    cpp_int b = fib(num);
    std::cout << num << "\n" << b << std::endl;
    t = clock() - t;
    std::cout << "Time to compute: " << (double)t / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

