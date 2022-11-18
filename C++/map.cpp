#include <map>
#include <iostream>

int main()
{
    std::map<int, std::string> m1 =
    {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    for (auto const& el : m1)
    {
        std::cout << el.first << " -> " << el.second << std::endl;
    }

    return 0;
}

