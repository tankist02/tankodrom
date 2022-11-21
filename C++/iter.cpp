#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Shoe {
    Shoe(int s, std::string const& st) : size(s), style(st) {}
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
    int shoes_num = 200;
    for (int l = 0; l < loops; ++l) {
        Shoes shoes;
        for (int i = 0; i < shoes_num; ++i) {
            int size = i % 12;
            shoes.push_back(Shoe(size, "boot" + std::to_string(size)));
        }
        shoes_in_size(shoes, 10);
        if (l == 0) {
            for (auto const& shoe : shoes) {
                //std::cout << shoe.size << ", " << shoe.style << "\n";
                shoe.save(std::cout);
            }
            std::cout << shoes.back().style << "\n";
        }
        counter += shoes.size();
    }
    std::cout << "counter: " << counter << std::endl;
}

