#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <tuple>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    auto p = std::pair<int, std::string>{1, "one"};
    auto [a, b] = p;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    auto t = std::make_tuple(1, "three");
    auto& [i, s] = t;
    std::cout << "i: " << i << ", s: " << s << std::endl;

    auto t2 = std::tuple<int, double, std::string>{1, 2.0, "three"};
    auto& [i2, d2, s2] = t2;
    std::cout << "i2: " << i2 << ", d2: " << d2 << ", s2: " << s2 << std::endl;

    s2 = "four";
    std::cout << "s2: " << s2 << ", t2.get<2>: " << std::get<2>(t2) << std::endl;

    std::map<int, std::string> m{{1, "one"}, {2, "two"}};
    if (auto [pos, ok] = m.insert({1, "one"}); !ok) {
        auto const& [key, val] = *pos;
        std::cout << "Already exists: " << key << "\n";
    }

    std::string fname = argv[1] ? argv[1] : "test.txt";
    std::cout << "fname: " << fname << std::endl;

    switch (fs::path p{fname}; status(p).type()) {
        case fs::file_type::not_found:
            std::cout << p << " not found\n";
            break;

        case fs::file_type::directory:
            for (auto const& e : fs::directory_iterator{p}) {
                std::cout << ": " << e.path() << '\n';
            }
            break;

        default:
            std::cout << "File contents:\n";
            std::ifstream ifs(fname);
            std::cout << ifs.rdbuf() << '\n';
            break;
    }
}
