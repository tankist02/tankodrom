#include <iostream>

#include <boost/multiprecision/cpp_int.hpp> 

using namespace boost::multiprecision;

cpp_int fib(int place)
{
    cpp_int a = 0;
    cpp_int b = 1;
    while (place-- > 1)
    {
        cpp_int t = b;
        b = a + b;
        a = t;
    }
    return b;
}

int main(int argc, char* argv[])
{
    int num = 250000;
    if (argv[1]) { num = std::stoi(argv[1]); }
    std::cout << "num: " << num << std::endl;

    /*cpp_int bn = 1;
    for (int i = 0; i < num; ++i)
    {
        bn += i;
    }
    std::cout << "bn: " << bn << std::endl;*/
    clock_t t = clock();
    cpp_int b = fib(num);
    std::cout << num << "th fib # is: " << b << std::endl;
    t = clock() - t;
    std::cout << "Time to compute: " << (double)t / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

