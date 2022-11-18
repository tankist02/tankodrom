#include <iostream>
#include <vector>
#include <functional>
#include <string_view>

using FilterVec = std::vector<std::function<bool(int)>>;

void addFilter(FilterVec& fv)
{
    auto divisor = 2;
    // Capture local by ref is bad 
    //fv.emplace_back([&](int value) { std::cout << "lambda: value: " << value << ", divisor: " << divisor << std::endl; return value % divisor == 0; });
    // Capture by copying is good here
    fv.emplace_back([=](int value) { std::cout << "lambda: value: " << value << ", divisor: " << divisor << std::endl; return value % divisor == 0; });
}

int main(int argc, char* argv[])
{
    int x = 0;
    if (argv[1])
    {
        x = atoi(argv[1]);
    }
    std::cout << "x: " << x << std::endl;

    auto c1 = [x](int y) { return x * y > 55; };

    bool res = c1(100);
    std::cout << "res: " << res << std::endl;

    FilterVec fv;
    addFilter(fv);

    for (auto f : fv)
    {
        std::cout << f(10) << std::endl;
        std::cout << f(11) << std::endl;
    }

    std::array<std::string_view, 4> strs {"apple", "banana", "walnut", "pear"};
    std::string_view nut = "nut";
    auto found = std::find_if(begin(strs), end(strs), [nut](std::string_view str) { return str.find(nut) != std::string_view::npos; });
    if (found)
    {
        std::cout << "Found nut: " << *found << std::endl;
    }
    else
    {
        std::cout << "No nut found" << std::endl;
    }

    // Regular lambda vs template one
    auto mult1 = [](auto const v1, auto const v2) { return v1 * v2; };
    auto mult2 = []<typename T>(T const v1, T const v2) { return v1 * v2; };

    auto res1 = mult1(10, true);
    std::cout << res1 << std::endl;

    auto res2 = mult2(10, 20);
    std::cout << res2 << std::endl;

    // Won't compile because of conflicting types 'int' and 'bool'
    //auto res3 = mult2(10, true);
    //std::cout << res3 << std::endl;

    auto lambda_example = [](auto x) { return x; };
    auto s = lambda_example("5");
    std::cout << "s: " << s << std::endl;

    auto n = lambda_example(5);
    std::cout << "n: " << n << std::endl;

    return 0;
}

