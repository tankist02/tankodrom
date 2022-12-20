#include <iostream>
#include <variant>

struct Visitor
{
    void operator()(char ch) const { std::cout << "char: " << ch << std::endl; }
    void operator()(int i) const { std::cout << "int: " << i << std::endl; }
    void operator()(double d) const { std::cout << "double: " << d << std::endl; }
};

int main(int, char**)
{
    try
    {
        std::variant<char, int, double> vc{'a'};
        std::variant<char, int, double> vi{1};
        std::variant<char, int, double> vd{2.2};
        std::cout << "char: " << std::get<char>(vc) << std::endl;
        std::cout << "char: " << std::get<0>(vc) << std::endl;
        std::cout << "int: " << std::get<int>(vi) << std::endl;
        std::cout << "double: " << std::get<double>(vd) << std::endl;
        vd = 123.456;
        std::cout << "double: " << std::get<double>(vd) << std::endl;

        std::visit(Visitor(), vc);
        std::visit(Visitor(), vi);
        std::visit(Visitor(), vd);

        auto print = [](auto val) { std::cout << "val: " << val << std::endl; };
        std::visit(print, vc);

        auto change = [](auto& val) { val = val + val; };
        std::visit(change, vi);
        std::visit(print, vi);

        std::visit([](auto& val) { val = std::remove_reference_t<decltype(val)>{}; }, vd);
        std::visit(Visitor(), vd);

        std::visit(change, vc);
        std::visit(Visitor(), vc);

        return 0;
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
    return -1;
}

