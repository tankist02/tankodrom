#include <iostream>
#include <type_traits>

class MyClass {};

struct Conv
{
    double operator()() { return 0.0; }
};

int func_signed(int i) { std::cout << "func_signed: i: " << i << std::endl; return i; }
unsigned func_unsigned(unsigned i) { std::cout << "func_unsigned: i: " << i << std::endl; return i; }

template <typename T>
void func(T t)
{
    if constexpr (std::is_signed<T>::value)
    {
        func_signed(t);
    }
    else if constexpr (std::is_unsigned<T>::value)
    {
        func_unsigned(t);
    }
    else
    {
        static_assert(std::is_signed_v<T> || std::is_unsigned_v<T>, "Type must be either signed or unsigned");
    }
}

int main()
{
    std::cout << std::is_floating_point_v<MyClass> << std::endl;
    std::cout << std::is_floating_point_v<int> << std::endl;
    std::cout << std::is_floating_point_v<float> << std::endl;
    std::cout << std::is_floating_point_v<double> << std::endl;
    std::cout << std::is_floating_point_v<Conv> << std::endl;

    std::cout << "is_signed<int>: " << std::is_signed_v<int> << std::endl;
    std::cout << "is_signed<size_t>: " << std::is_signed_v<size_t> << std::endl;

    int i = 1;
    func(i);

    unsigned j = 0;
    func(j);

    //func("dummy");
}
