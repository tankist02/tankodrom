#include <iostream>

template<typename T>
struct Point
{
    T x;
    T y;
    T f() const { return x; }
};

template<>
struct Point<int>
{
    int x;
    int y;
    int f() const { return y; }
};

int main()
{
    Point<int> p{1, 2};
    std::cout << p.f() << std::endl;
}

