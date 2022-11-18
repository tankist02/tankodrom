#include <iostream>
#include <numeric>

constexpr unsigned int gcd(unsigned int x, unsigned int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    constexpr auto result = std::gcd(40, 10);
    std::cout << result << std::endl;
    auto res = gcd(40, 10);
    std::cout << res << std::endl;
}

