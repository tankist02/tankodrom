#include <iostream>
#include <string>

struct Address
{
    std::string street;
    std::string city;
};

struct Person
{
    std::string name;
    int age;
    Address address;
};

Address createAddress(char const* street, char const* city)
{
    return Address{street, city};
}

Person createPerson(char const* name, int age, Address&& address)
{
    return Person{name, age, std::move(address)};
}

void printInfo(Person const& person)
{
    std::cout << person.name << " , " << person.age << " years old" <<
        " @ " << person.address.street << " , " << person.address.city << std::endl;
}

int main()
{
    Address address = createAddress("Street 1", "City 1");
    Person person = createPerson("Person 1", 20, std::move(address));
    printInfo(person);

    std::cout << address.street << " in " << address.city << std::endl;

    return 0;
}

