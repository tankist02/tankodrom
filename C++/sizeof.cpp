#include <iostream>
#include <string>

class A
{
    int i;
    double d;
    std::string s;
    int* p;
};

class B
{
    virtual ~B() { delete p; }
    int i;
    double d;
    std::string s;
    int* p;
};

int main()
{
    std::cout << "sizeof(A): " << sizeof(A) << std::endl;
    std::cout << "sizeof(B): " << sizeof(B) << std::endl;
}

