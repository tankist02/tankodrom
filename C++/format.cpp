#include <fmt/core.h>

int main(int argc, char* argv[])
{
    fmt::print("Hello, world!\n");

    auto s = fmt::format("The answer is {}", 42);
    fmt::print("s: {}", s);
}

