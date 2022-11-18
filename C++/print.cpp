#include <array>
#include <iostream>
#include <iterator>
#include <vector>

struct Man
{
    std::string name_;
    int age_;
    double weight_;
    std::ostream& save(std::ostream& os) const
    {
        os << name_ << "," << age_ << "," << weight_;
        return os;
    }
};

std::ostream& operator<<(std::ostream& os, Man const& m) { return m.save(os); }
std::ostream& operator<<(std::ostream& os, std::pair<int, int> const& p) { os << p.first << "," << p.second; return os; }

int main()
{
    //std::vector<Man> men = {
    std::array<Man, 3> men {{
        {"Ivan", 33, 100.0},
        {"Pete", 26, 85.0},
        {"Serge", 44, 77.0}}};

    std::copy(men.begin(), men.end(), std::ostream_iterator<Man>(std::cout, "\n"));

    std::array<int, 3> is = {1, 2, 3};
    std::copy(is.begin(), is.end(), std::ostream_iterator<int>(std::cout, "\n"));

    //std::array<std::pair<int, int>, 3> ps = {{{1, 1}, {2, 2}, {3, 3}}};
    std::vector<std::pair<int, int>> ps = {{{1, 1}, {2, 2}, {3, 3}}};
    std::copy(ps.begin(), ps.end(), std::ostream_iterator<std::pair<int, int>>(std::cout, "\n"));
    //std::cout << ps[0] << std::endl;
    //for (auto const& el : ps) { std::cout << el.first << "," << el.second << std::endl; }
}

