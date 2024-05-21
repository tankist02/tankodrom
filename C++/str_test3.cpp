#include <iostream>
#include <string>

// Function to create a string of size len filled with symbols from charset looping around
static std::string gen_str(size_t len)
{
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    //std::cout << "charset: " << charset << " (" << sizeof(charset) << ")" << std::endl;

    std::string res;
    res.reserve(len);
    for (size_t i = 0; i < len; ++i)
    {
        res += charset[i % (sizeof(charset) - 1)]; // -1 for the terminating null
    }
    return res;
}

int main(int argc, char* argv[])
{
    size_t loops = 100'000;

    if (argv[1]) { loops = atoi(argv[1]); }
    std::cout << "loops: " << loops << std::endl;
    
    std::string const strings[] = { gen_str(6), gen_str(25), gen_str(14), gen_str(235) , gen_str(155) };
    //for (auto const& e : strings) { std::cout << e << " (" << e.length() << ")\n"; }
    //std::cout << std::endl;

    size_t count = 0;
    std::string str;
    str.reserve(1024);

    for (size_t i = 0; i < loops; ++i)
    {
        str.resize(0);
        for (size_t j = 0; j < i; ++j)
        {
            str += strings[j % (sizeof(strings) / sizeof(strings[0]))];
        }

        //std::cout << "i: " << i << ", str: " << str << std::endl;
        //if (i == loops - 1) { std::cout << "str len: " << str.size() << std::endl; }

        std::size_t found = str.find("A");
        if (found != std::string::npos) { ++count; }

        found = str.rfind("z");
        if (found != std::string::npos) { ++count; }
    }
    std::cout << "str: " << str << std::endl;
    std::cout << "count: " << count << std::endl;
}

