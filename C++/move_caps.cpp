#include <cstring>
#include <iostream>
#include <string>

std::string move_caps(char const* input)
{
    if (!input || !*input) { return ""; }

    std::string caps, smalls;
    for (char const* p = input; *p; ++p)
    {
        if (std::isupper(*p)) { caps.push_back(*p); }
        else { smalls.push_back(*p); }
    }
    std::string res;
    res += caps;
    res += smalls;
    return res;
}

int main(int argc, char* argv[])
{
    char const* input = "AaBbCc";
    auto res = move_caps(input);
    std::cout << "input: " << input << ", res: " << res << std::endl;

    return 0;
}

