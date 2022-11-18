#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    //int arr[] = { 1,2,3,4 };
    std::vector<int> vect{1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto i : vect) std::cout << i << ',';
    std::cout << std::endl;

    int y = 3;
    std::vector<int>::const_iterator it = std::find_if(vect.cbegin(), vect.cend(), [y](auto x) { return x == y; });
    std::cout << std::distance(vect.cbegin(), it) << ": " << *it << std::endl;

    auto it2 = std::find_if(vect.crbegin(), vect.crend(), [y](auto x) { return x == y; });
    std::cout << std::distance(vect.crbegin(), it2) << ": " << *it2 << std::endl;

    auto it3 = it2.base();
    std::cout << std::distance(vect.cbegin(), it3) << ": " << *it3 << std::endl;

    std::copy(vect.cbegin(), vect.cend(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::copy(vect.crbegin(), vect.crend(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    return 0;
}

