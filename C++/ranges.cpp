#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

void printc(auto const& col)
{

    for (size_t i = 0; auto const& e : col)
    {
        if (i++ > 0) { std::cout << ", "; }
        std::cout << e;
    }
    std::cout << '\n';
}

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

    int arr[] = {9, 8, 2, 1};
    std::ranges::sort(arr);
    printc(arr);
    std::vector<std::string> cities{"Rio", "Tokyo", "New York", "Berlin"};
    std::ranges::sort(cities);
    printc(cities);
    std::ranges::sort(cities[0]);
    printc(cities);
    printc(cities[0]);
}

