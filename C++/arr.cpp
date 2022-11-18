#include <iostream>
#include <array>
#include <iterator>
#include <vector>

int main()
{
    //std::vector arr1 = {1, 2, 3};
    std::array arr1 = {1, 2, 3};
    //std::copy(arr1.begin(), arr1.end(), std::ostream_iterator<int>(std::cout, ","));
    std::copy(arr1.rbegin(), arr1.rend(), std::ostream_iterator<int>(std::cout, ","));
    //for (auto el : arr1) std::cout << (el != arr1.front() ? "," : "") << el;
    std::cout << std::endl;
}

