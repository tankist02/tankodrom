#include <iostream>

template<int N>
struct Fact
{
    static constexpr size_t value = N * Fact<N - 1>::value;
};

template<>
struct Fact<1>
{
    static constexpr size_t value = 1;
};

constexpr size_t fact(size_t n)
{
    return n == 1 ? 1 : n * fact(n - 1);
}

int main()
{
    std::cout << Fact<3>::value << std::endl;
    std::cout << Fact<10>::value << std::endl;
    constexpr size_t res = fact(10);
    std::cout << res << std::endl;
}

