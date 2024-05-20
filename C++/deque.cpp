#include <ctime>
#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[])
{
    int const size = 500'000;

    clock_t c = clock();
    std::vector<int> v(size, 1);
    for (int i = 0; i < size; ++i)
    {
        v.erase(v.begin());
    }
    std::cout << "Elapsed: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;

    c = clock();
    std::deque<int> d(size, 1);
    std::cout << "deque size: " << d.size() << "\n";
    for (int i = 0; i < size; ++i)
    {
        //d.erase(d.begin());
        d.pop_front();
    }
    std::cout << "deque size: " << d.size() << "\n";
    std::cout << "Elapsed: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;
    return 0;
}

