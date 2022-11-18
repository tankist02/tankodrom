#include <iostream>
#include <vector>

int main()
{
    int* p = nullptr;
    {
        int i = 1;
        std::vector<double> v1 {1.0, 2.0};
        p = &i;
        std::vector<double> v2 = v1;
    }
    std::cout << *p << std::endl;
}

