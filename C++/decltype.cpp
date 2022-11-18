#include <iostream>

struct Widget
{
    int foo() { return i_; }
    int bar() const { return i_; }
    int i_{0};
};

decltype(auto) f1() { int x = 1; return x; }
//decltype(auto) f2() { int x = 1; return (x); }

int main()
{
    Widget w;
    std::cout << w.i_ << std::endl;

    Widget const& cw = w;
    auto w1 = cw; // type is Widget
    w1.foo();
    w1.bar();

    decltype(auto) w2 = cw; // type is Widget const&
    //does not compile w2.foo();
    w2.bar();
}

