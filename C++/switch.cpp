#include <iostream>
#include <string_view>

int foo(std::string_view s, int pos)
{
    auto len = s.length();
    /* C++ does not have pattern matching
    switch (pos)
    {
        case 0: return -1;
        case len - 1: return 0;
        case default: return 1;
    }*/
    if (pos == 0) { return -1; }
    if (pos == (int)len - 1) { return 0; }
    return 1;
}

int main()
{
    std::cout << foo("Hello, world!", 0) << std::endl;
}

