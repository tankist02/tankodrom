#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 0, 3, 4, 5, 0, 6, 0};
    for (auto const& e : v) std::cout << e << ' ';
    std::cout << '\n';
    auto pos = v.begin();
    while (pos != v.end()) {
        std::cout << "*pos: " << *pos << std::endl;
        if (*pos == 0) {
            pos = v.erase(pos);
        }
        else
        {
            ++pos;
        }
    }
    for (auto const& e : v) std::cout << e << ' ';
    std::cout << '\n';
}
