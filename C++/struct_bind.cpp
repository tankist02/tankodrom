#include <iostream>
#include <tuple>

int main()
{
    auto p = std::pair<int, std::string>{1, "one"};
    auto [a, b] = p;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    auto t = std::make_tuple(1, "three");
    auto& [i, s] = t;
    std::cout << "i: " << i << ", s: " << s << std::endl;

    auto t2 = std::tuple<int, double, std::string>{1, 2.0, "three"};
    auto& [i2, d2, s2] = t2;
    std::cout << "i2: " << i2 << ", d2: " << d2 << ", s2: " << s2 << std::endl;

    s2 = "four";
    std::cout << "s2: " << s2 << ", t2.get<2>: " << std::get<2>(t2) << std::endl;
}
