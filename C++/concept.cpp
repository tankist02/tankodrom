#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>

using Numbers = std::vector<int>;

template <std::integral T>
struct isOddNum
{
    constexpr bool operator()(T const value) const noexcept { return value % 2 != 0; }
};

int main()
{
    std::size_t const VECT_SIZE = 20;
    Numbers numbers(VECT_SIZE);
    std::iota(begin(numbers), end(numbers), 0);
    for (auto const& n : numbers) { std::cout << n << ", "; }
    std::cout << std::endl;

    std::erase_if(numbers, isOddNum<Numbers::value_type>());
    for (auto const& n : numbers) { std::cout << n << ", "; }
    std::cout << std::endl;

    return 0;
}

