#include <cstdio>
#include <iostream>
#include <fmt/format.h>

double getPrint(int repeats)
{
    clock_t s = clock();
    for (int i = 0; i < repeats; ++i)
    {
        printf("Hello, World!\n");
    }
    s = clock() - s;

    return (double)s / CLOCKS_PER_SEC;
}

double getCout(int repeats)
{
    clock_t s = clock();
    for (int i = 0; i < repeats; ++i)
    {
        std::cout << "Hello, World!\n";
    }
    s = clock() - s;
    return (double)s / CLOCKS_PER_SEC;
}

double getFwrite(int repeats)
{
    clock_t s = clock();
    for (int i = 0; i < repeats; ++i)
    {
        fwrite("Hello, World!\n", 14, 1, stdout);
    }
    s = clock() - s;
    return (double)s / CLOCKS_PER_SEC;
}

double getFmt(int repeats)
{
    clock_t s = clock();
    for (int i = 0; i < repeats; ++i)
    {
        fmt::print("Hello, World!\n");
    }
    s = clock() - s;
    return (double)s / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[])
{
    int repeats = 100;

    if (argv[1])
    {
        repeats = atoi(argv[1]);
    }

    double tw = getFwrite(repeats);
    double tp = getPrint(repeats);
    double tf = getFmt(repeats);
    double tc = getCout(repeats);

    std::cout << "fwrite time: " << tw << std::endl;
    std::cout << "printf time: " << tp << std::endl;
    std::cout << "fmt::print time: " << tf << std::endl;
    std::cout << "std::cout time: " << tc << std::endl;
}

