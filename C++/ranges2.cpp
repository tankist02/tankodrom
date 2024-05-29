#include <algorithm>
#include <iostream>
#include <ranges>
#include <list>
#include <map>
#include <vector>

void print(auto const& col)
{
    for (auto const& e : col) { std::cout << e << ' '; }
    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    std::vector v {1, 2, 3, 4};
    std::list l {1, 2, 3, 4};

    print(v);
    print(l);

    print(std::views::take(v, 3));
    print(v | std::views::take(3));
    print(v | std::views::take(3) | std::views::transform([](auto v) {return std::to_string(v) + "s";}));

    std::map<std::string, int> numbers {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4}
    };

    for (auto const& e : numbers)
    {
        std::cout << e.first << " - " << e.second << '\n';
    }

    std::cout << '\n';

    namespace vws = std::views;
    for (auto const& e : numbers | vws::filter([](auto const& y) { return y.second < 3; }))
    {
        std::cout << e.first << " - " << e.second << '\n';
    }

    for (auto const& e : numbers | vws::filter([](auto const& y) { return y.second < 3; }) | vws::keys)
    {
        std::cout << e << '\n';
    }

    for (auto const& e : numbers | vws::filter([](auto const& y) { return y.second < 3; }) | vws::values)
    {
        std::cout << e << '\n';
    }

    auto v1 = vws::take(v, 2);
    for (auto const& e : v1) { std::cout << e << ' '; }
    std::cout << '\n';

    //for (int i = 0; i < 6; ++i) { std::cout << "i: " << i << ": " << v1[i] << ' '; }
    //std::cout << '\n';

    return 0;
}

