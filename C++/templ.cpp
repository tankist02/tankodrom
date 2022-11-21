#include <algorithm>
#include <iostream>
#include <vector>

template<typename CB>
class CountCalls
{
public:
    CountCalls(CB cb) : callback(cb) {}
    template<typename... Args>
    decltype(auto) operator()(Args&&... args) {
        ++calls;
        return callback(std::forward<Args>(args)...);
    }

    long count() const { return calls; }

private:
    CB callback;
    long calls{0};
};

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

    CountCalls sc{[](auto x, auto y) { return x < y; }};
    std::vector v{5, 4, 3, 2, 1};
    for (auto const& i : v) { std::cout << i << "\n"; }
    std::sort(begin(v), end(v), std::ref(sc));
    std::cout << "calls: " << sc.count() << "\n";
    for (auto const& i : v) { std::cout << i << "\n"; }

    auto fo = std::for_each(begin(v), end(v), CountCalls([](auto i) { std::cout << i << "\n"; }));
    std::cout << "fo count: " << fo.count() << "\n";
}

