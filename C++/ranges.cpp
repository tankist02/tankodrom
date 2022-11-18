#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main(int argc, char* argv[])
{
    //constexpr int N = 10000000;
    int N = 1000;
    if (argv[1]) { N = atoi(argv[1]); }
    std::cout << "N: " << N << std::endl;

    auto isEven = [](auto const value) { return value % 2 == 0; };
    auto sum = [](auto const value) { return value + value; };
    auto tail = [&](auto const value) { return value > 2 * N - 100; };
    auto print = [](auto const value) { std::cout << value << ", "; };

    auto view = std::views::iota(0, N) | std::views::filter(isEven) | std::views::transform(sum) | std::views::filter(tail);
    std::ranges::for_each(view, print);
}

