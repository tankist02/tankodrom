#include <iostream>
#include <string>

struct S
{
    S(char const* s = "") : s_(s) {}
    S(S&& s) { s_ = std::move(s.s_); }
    std::string s_;
};

int main()
{
    S s1("s1");
    std::cout << s1.s_ << std::endl;
    S s2 = std::move(s1);
    std::cout << s1.s_ << std::endl;
    std::cout << s2.s_ << std::endl;
}

