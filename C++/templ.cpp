#include <iostream>
#include <vector>

int main()
{
    std::vector v1{1};
    for (auto const& v : v1) {
        std::cout << v << "\n";
    }

    std::vector v2{2};
    for (auto const& v : v2) {
        std::cout << v << "\n";
    }

    std::vector vii{v1, v2};
    for (auto const& v : vii) {
        for (auto const& u : v) {
            std::cout << u << "\n";
        }
    }
}

