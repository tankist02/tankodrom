#include <iostream>

int main(int argc, char* argv[])
{
    char const* text = "the quick brown fox jumps over the lazy dog";

    int constexpr size = 'z' - 'a' + 1;

    int counts[size]{0};

    for (char const* p = text; *p; ++p)
    {
        int index = *p - 'a';
        ++counts[index];
    }

    for (int i = 0; i < size; ++i) { std::cout << char('a' + i) << ": " << counts[i] << std::endl; }
}

