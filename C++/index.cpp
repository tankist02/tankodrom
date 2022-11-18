#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, std::pair<K, V> const& e)
// does not work std::ostream& operator<<(std::ostream& os, typename std::map<K, V>::value_type const& e)
{
    os << e.first << "=" << e.second;
    return os;
}

template <typename Cont>
void printCont(Cont const& cont)
{
    for (size_t index = 0; auto const& n : cont) 
    {
        if (index++ > 0) { std::cout << ", "; }
        std::cout << n;
    }
    std::cout << std::endl;
}

int main()
{
    using Numbers = std::vector<int>;
    Numbers nums(20);
    std::iota(begin(nums), end(nums), 1);

    // Does not work for std::map and set
    for (size_t index = 0; index < nums.size(); ++index) 
    {
        if (index > 0) { std::cout << ", "; }
        std::cout << nums[index];
    }
    std::cout << std::endl;

    for (auto it = begin(nums); it != end(nums); ++it) 
    {
        size_t index = std::distance(it, begin(nums));
        if (index > 0) { std::cout << ", "; }
        std::cout << *it;
    }
    std::cout << std::endl;

    printCont(nums);

    std::set<int> s {4, 2, 3, 1};
    printCont(s);

    std::map<int, std::string> m { {1, "one"}, {2, "two"}, {3, "three"} };
    printCont(m);

    return 0;
}

