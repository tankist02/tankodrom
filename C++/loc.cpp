#include <iostream>
#include <source_location>

int main(int argc, char* argv[])
{
    auto const& loc = std::source_location::current();
    std::cout <<
        "File: " << loc.file_name() <<
        ", functions: " << loc.function_name() <<
        ", line: " << loc.line() <<
        ", column: " << loc.column() << std::endl;
    return 0;
}

