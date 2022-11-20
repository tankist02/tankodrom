#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Shoe {
    int size;
    std::string style;
    std::ostream& save(std::ostream& os) const {
        os << size << ", " << style << "\n";
        return os;
    }
};

typedef std::vector<Shoe> Shoes;

void shoes_in_size(Shoes& shoes, int size) {
    shoes.erase(std::remove_if(begin(shoes), end(shoes), [size](Shoe const& s) { return s.size != size; }), end(shoes));
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
        shoes_in_size(shoes, 10);
        if (l == 0) {
            for (auto const& shoe : shoes) {
                //std::cout << shoe.size << ", " << shoe.style << "\n";
                shoe.save(std::cout);
            }
            std::cout << shoes.back().style << "\n";
        }
        ++counter;
    }
    std::cout << "counter: " << counter << std::endl;
}

