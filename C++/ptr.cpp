#include <cstdio>
#include <cstring>

int main()
{
    char const* s = "Hello, world!";
    auto size = strlen(s);
    for (auto i = 0u; i < size; ++i)
    {
        putchar(i[s]);
    }
    putchar('\n');
}

