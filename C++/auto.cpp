#include <array>
#include <iostream>
#include <iterator>
#include <vector>

// auto func(int x)
//std::initializer_list<int> func(int x)
//std::vector<int> func(int x)
std::array<int, 3> func(int x)
{
    return {x, x + 1, x + 2};
}

int main()
{
    auto a = func(0);
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::uint8_t x = 0;
    std::uint8_t y = 1;
    auto z = x & y;
    std::cout << sizeof(x) << std::endl;
    std::cout << z << " " << sizeof(z) << std::endl;
}

