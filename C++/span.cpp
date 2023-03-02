#include <iostream>
#include <span>
#include <string>
#include <thread>
#include <vector>

using Strings = std::vector<std::string>;
using Ints = std::vector<int>;
using Threads = std::vector<std::jthread>;

template<typename T>
void print(T const& c)
{
    for (auto const& e : c) { std::cout << e << " "; }
    std::cout << std::endl;
}

void printSpan(std::span<const int> s)
{
    //std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    for (auto const& e : s) { std::cout << e << " "; }
    std::cout << std::endl;
}

template<typename T>
void split(std::vector<T> const& v, int parts)
{
    Threads threads;
    auto size = std::max(v.size() / parts, size_t(1));
    for (auto beg = v.begin(); beg < v.end(); beg += size)
    {
        std::span sp{beg, size};
        threads.push_back(std::jthread(printSpan, sp));
        //printSpan(sp);
    }
    for (auto& e : threads) { e.join(); }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    Strings strings{"one", "two", "three"};

    for (int i = 1; i < argc; ++i) { strings.push_back(argv[i]); }

    print(strings);

    std::span sp{strings.begin(), 2};
    print(sp);

    Ints ints;
    for (int i = 1; i <= 24; ++i) { ints.push_back(i); }
    print(ints);
    std::cout << std::endl;

    for (int p = 1; p < 12; ++p) { 
        std::cout << "parts: " << p << std::endl; 
        split(ints, p);
    }
}

