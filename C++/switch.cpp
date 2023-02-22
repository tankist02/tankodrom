#include <string_view>

int foo(std::string_view s, int pos)
{
    auto len = s.length();
    switch (pos)
    {
        case 0: return -1;
        case len - 1: return 0;
        case default: return 1;
    }
}

int main()
{
}

