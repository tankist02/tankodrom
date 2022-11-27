#include <iostream>
#include <optional>

std::optional<int> asInt(std::string const& s)
{
    try
    {
        return std::stoi(s);
    }
    catch (...)
    {
        return std::nullopt;
    }
}

int main()
{
    for (auto s : {"1", "3.1415", "hello"})
    {
        auto oi = asInt(s);
        if (oi)
        {
            std::cout << "Got int: " << *oi << " from: " << s << "\n";
        }
        else
        {
            std::cerr << "Failed to parse int from: " << s << "\n";
        }
    }

    try
    {
        std::optional<int> oi;
        if (oi)
        {
            int i = oi.value();
            std::cout << "i: " << i << std::endl;
        }

        std::optional<std::string> os("hello");
        std::string s = std::move(os).value();
        std::cout << "s: " << s << std::endl;
        if (os) { std::cout << "os has value: " << os.value() << "\n"; }
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
}

