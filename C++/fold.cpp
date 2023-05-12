#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

// Fold expression since C++17
template <typename... Values>
auto sum(Values const&... value)
{
    return (value + ...);
}

template <typename... Values>
auto right_sub(Values const&... value)
{
    return (value - ...);
}

template <typename... Values>
auto left_sub(Values const&... value)
{
    return (... - value);
}

int main()
{
    std::vector<int> v {1, 2, 3};
    auto res = std::accumulate(begin(v), end(v), 0, [](int const v1, int const v2) { return v1 - v2; });
    std::cout << res << std::endl;

    res = std::accumulate(rbegin(v), rend(v), 0, [](int const v1, int const v2) { return v1 - v2; });
    std::cout << res << std::endl;

    std::vector<std::string> s {"one", "two", "three"};
    auto res2 = std::accumulate(begin(s), end(s), std::string(), [](std::string const& v1, std::string const& v2) { return v1 + v2; });
    std::cout << res2 << std::endl;

    auto res3 = std::accumulate(rbegin(s), rend(s), std::string(), [](std::string const& v1, std::string const& v2) { return v1 + v2; });
    std::cout << res3 << std::endl;

    auto add = sum(1, 2, 3);
    std::cout << add << std::endl;

    auto add2 = sum(1.1, 2.2, 3.3);
    std::cout << add2 << std::endl;

    auto add3 = sum(std::string("one"), std::string("two"), std::string("three"));
    std::cout << add3 << std::endl;

    auto subr = right_sub(1, 2, 3);
    std::cout << subr << std::endl;

    auto subl = left_sub(1, 2, 3);
    std::cout << subl << std::endl;

    return 0;
}

