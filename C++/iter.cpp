#include <iostream>
#include <string>
#include <vector>

struct Shoe {
    int size;
    std::string style;
    std::ostream& print(std::ostream& os = std::cout) const {
        os << "size: " << size << ", style: " << style << "\n";
        return os;
    }
};

typedef std::vector<Shoe> Shoes;

Shoes shoes_in_size(Shoes const& shoes, int size) {
    Shoes res;
    for (auto const & shoe : shoes) {
        if (shoe.size == size) {
            res.push_back(shoe);
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    int loops = 1000;
    if (argv[1]) {
        loops = std::stoi(argv[1]);
    }
    
    int counter = 0;
    for (int l = 0; l < loops; ++l) {
        Shoes shoes { 
            {10, "sneaker"}, 
            {13, "sandal"}, 
            {10, "boot"}, 
            {10, "boot2"}, 
            {12, "boot"}, 
            {10, "boot3"}, 
            {11, "boot"}, 
            {10, "boot4"}, 
            {9, "boot"}, 
            {10, "boot5"} };
        Shoes res = shoes_in_size(shoes, 10);
        if (l == 0) {
            for (auto const& shoe : res) {
                shoe.print();
            }
            res.back().print();
        }
        ++counter;
    }
    std::cout << "counter: " << counter << std::endl;
}

