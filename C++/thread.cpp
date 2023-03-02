#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

void hello(int i)
{
    std::cout << "Hello Concurrent World: " << i << std::endl;
}

struct widget_data
{
    int d_{0};
};

void update_data(widget_data& wd)
{
    wd.d_ = 1;
}

int main(int argc, char* argv[])
{
    std::cout << "std::jthread::hardware_concurrency: " << std::jthread::hardware_concurrency() << std::endl;

    std::vector<std::jthread> v;

    for (int i = 0; i < 10; ++i) { v.push_back(std::jthread(hello, i)); }
    for (auto& it : v) { it.join(); }
    //std::for_each(v.begin(), v.end(), [](auto& o) { o.join(); });

    widget_data wd;
    std::jthread t(update_data, std::ref(wd)); // Need std::ref when expecting ref
    t.join();

    std::cout << "wd.d_: " << wd.d_ << std::endl;

    return 0;
}

