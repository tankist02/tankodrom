#include <iostream>
#include <map>

int main()
{
    using Map = std::map<int, double>;
    Map m {{1, 1.0}, {2, 2.0}};

    // ADL allows to use begin and end without std::
    for (auto it = begin(m); it != end(m); ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
    return 0;
}

