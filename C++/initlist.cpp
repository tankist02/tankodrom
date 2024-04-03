#include <iostream>

enum Sex
{
    MALE,
    FEMALE
};

typedef bool (*CheckerPtr)(Sex s);

struct Person
{
    // default ctor is required Person() = delete;
    char const* name_;
    Sex sex_;
    int age_;
    bool b1_;
    CheckerPtr checker_;
};

int main(int argc, char* argv[])
{
    //Person p1{"John", MALE, 32, false, nullptr};

    Person persons[] = 
    {
        {"John", MALE, 32, false, nullptr},
        {"Bill", MALE, 35, false, nullptr}
    };

    for (auto const& p : persons)
    {
        std::cout << p.name_ << ", " << p.age_ << std::endl;
    }
    return 0;
}

