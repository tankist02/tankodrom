#include <iostream>
#include <string>

template <typename T>
T adder(T v) { return v; }

template <typename T, typename... Args>
T adder(T first, Args... args)
{
    return first + adder(args...);
}

int main()
{
    auto sum = adder(1, 2, 3);
    std::cout << sum << std::endl;

    std::string s1("one");
    std::string s2("two");
    std::string s3("three");

    auto res = adder(s1, s2, s3);
    std::cout << res << std::endl;

    return 0;
}

