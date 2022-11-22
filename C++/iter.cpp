#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fmt/format.h>

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

Shoes shoesFactory(int num)
{
    Shoes shoes;
    for (int i = 0; i < num; ++i) {
        static char const* const styles[] = {
            "boot",
            "sneaker",
            "sandal",
            "pump",
            "highheel"
        };
        int size = i % 12;
        char const* style = styles[i % 5];
        // very slow snprintf(buf, sizeof(buf), "%s%d", style, size);
        // slow shoes.push_back(Shoe(size, style + fmt::format("{}", size)));
        shoes.push_back(Shoe(size, style + std::to_string(i)));
    }
    return shoes;
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
        Shoes shoes = shoesFactory(shoes_num);
        shoes_in_size(shoes, 10);
        if (l == 0) {
            for (auto const& shoe : shoes) {
                //std::cout << shoe.size << ", " << shoe.style << "\n";
                shoe.save(std::cout);
            }
        }
        counter += shoes.size();
    }
    std::cout << "counter: " << counter << ", l: " << loops << std::endl;
}

