#include <algorithm>
#include <iostream>
#include <vector>

class GreaterThan
{
public:
    GreaterThan(int n) : n_(n) {}
    template<typename T>
    bool operator()(T const& i) const { return i > n_; }

private:
    int n_;
};

int main(int argc, char* argv[])
{
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    std::cout << std::count_if(v.cbegin(), v.cend(), GreaterThan(3)) << std::endl;
    return 0;
}

