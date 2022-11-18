#include <cmath>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<double> xs = {1.0, 2.0, 3.0, 4.0};
    //auto result = std::sum(xs | std::views::transform(sqrt));
    //auto result = std::accumulate(xs | std::views::transform(sqrt));
    auto result = std::accumulate(xs.begin(), xs.end(), 0);
    std::cout << "sum result: " << result << std::endl;

    result = std::accumulate(xs.begin(), xs.end(), 1, std::multiplies<double>());
    std::cout << "prod result: " << result << std::endl;

    return 0;
}

