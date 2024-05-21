#include <iostream>
#include <string>

// Function to create a string of size len filled with symbols from charset looping around
static std::string gen_str(size_t len)
{
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string res;
    res.resize(len);
    for (size_t i = 0; i < len; ++i)
    {
        res += charset[i % sizeof(charset)];
    }
    return res;
}

int main(int argc, char* argv[])
{
    size_t loops = 100'000;

    if (argv[1])
    {
        loops = atoi(argv[1]);
    }
    
    std::string const strings[] = { gen_str(6), gen_str(25), gen_str(14), gen_str(235) , gen_str(155) };
    size_t count = 0;
    std::string str;
    str.reserve(1024);

    for (size_t i = 0; i < loops; ++i)
    {
        str.resize(0);
        for (size_t j = 1; j < i; ++j)
        {
            str += strings[j % sizeof(strings) / sizeof(strings[0])];
        }

        /*if (i == loops - 1)
        {
            std::cout << "str len: " << str.size() << std::endl;
        }*/

        std::size_t found = str.find("A");
        if (found != std::string::npos)
        {
            count += found;
        }
        found = str.rfind("z");
        if (found != std::string::npos)
        {
            count += found;
        }
    }
    std::cout << count << std::endl;
}

