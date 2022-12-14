#include <cstring>
#include <iostream>
#include <variant>

// slow using Value = std::variant<char const*, std::string>;

//Value fizzbuzz(int i)
std::string fizzbuzz(int i)
{
    if (i % 15 == 0) return "FizzBuzz";
    if (i % 5 == 0) return "Buzz";
    if (i % 3 == 0) return "Fizz";
    return std::to_string(i);
}

int main(int argc, char* argv[])
{
    int loops = 1000;
    if (argv[1]) loops = std::atoi(argv[1]);
    int sumlen = 0;
    for (int i = 0; i < loops; ++i)
    {
        std::string res = fizzbuzz(i);
        sumlen += res.size();
        //Value res = fizzbuzz(i);
        //sumlen += (res.index() == 0 ? strlen(std::get<0>(res)) : std::get<1>(res).size());
    }
    std::cout << "loops: " << loops << ", sumlen: " << sumlen << std::endl;
}

