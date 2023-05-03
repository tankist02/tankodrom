#include <iostream>
#include <functional>
#include <vector>

int add(int a, int b) { return a + b; }

bool equal_to_4(int i) { return i == 4; }

int main(int argc, char* argv[])
{
    auto fn = std::bind(&add, std::placeholders::_1, std::placeholders::_2);
    int res = fn(1, 2);
    std::cout << "res: " << res << std::endl;

    auto fn2 = std::bind(&add, 12, std::placeholders::_1);
    res = fn2(2);
    std::cout << "res: " << res << std::endl;

    std::vector v {1, 2, 3};

    std::cout << (std::find_if(v.begin(), v.end(), equal_to_4) != v.end()) << std::endl;

    v.push_back(4);
    std::cout << (std::find_if(v.begin(), v.end(), equal_to_4) != v.end()) << std::endl;

    std::cout << (std::find_if(v.begin(), v.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, 4)) != v.end()) << std::endl;

    std::cout << (std::find_if(v.begin(), v.end(), [](int i) { return i == 4; }) != v.end()) << std::endl;

    return 0;
}

