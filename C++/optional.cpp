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
}

