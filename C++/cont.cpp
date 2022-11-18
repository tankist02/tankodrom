#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

std::ostream& operator<<(std::ostream& os, std::pair<int, std::string> const& p)
{
    os << p.first << " " << p.second << std::endl;
    return os;
}

int main(int argc, char* argv[])
{
    std::map<int, std::string> ois = {{1, "one"}, {2, "two"}};
    //std::copy(ois.cbegin(), ois.cend(), std::ostream_iterator<std::pair<int, std::string>>(std::cout, " "));
    for (auto const& i : ois)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    std::unordered_map<int, std::string> mis = {{1, "one"}, {2, "two"}};
    //std::copy(mis.cbegin(), mis.cend(), std::ostream_iterator<int, std::string>(std::cout, " "));
    for (auto const& i : mis)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    return 0;
}

