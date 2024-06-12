#include <iostream>

int main(int argc, char* argv[])
{
    char const* text = "the quick brown fox jumps over the lazy dog";

    int constexpr size = 'z' - 'a' + 1;

    auto c = clock();

    size_t loops = 100'000'000;
    size_t sum = 0;

    for (size_t l = 0; l < loops; ++l)
    {
        int counts[size]{0};

        for (char const* p = text; *p; ++p)
        {
            if (*p != ' ') 
            {
                int index = *p - 'a';
                ++counts[index];
            }
        }
        sum += counts[size - 1];
    }
    c = clock() - c;
    std::cout << "sum: " << sum << ", elapsed: " << (double)c / CLOCKS_PER_SEC << std::endl;
//    for (int i = 0; i < size; ++i) { std::cout << char('a' + i) << ": " << counts[i] << std::endl; }
}

