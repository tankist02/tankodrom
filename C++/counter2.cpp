#include <atomic>
#include <iostream>
#include <thread>
#include <unistd.h>

inline long millis(struct timespec const& start, struct timespec const& stop)
{
    return (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_nsec - start.tv_nsec) / 1000000;
}

std::string prettyPrint(long value)
{
    std::string res = std::to_string(value);
    for (int i = res.size() - 3; i > 0; i -= 3) { res.insert(i, ","); }
    return res;
}

//bool cont = true;
std::atomic_bool cont = true;

void sleeper()
{
    usleep(1000000);
    //usleep(1000);
    cont = false;
}

void counter(long& count)
{
    while (cont) { ++count; }
}

int main(int argc, char* argv[])
{
    //auto start = clock();
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);

    long count = 0;
    
    auto thr1 = std::thread(sleeper);
    auto thr2 = std::thread(counter, std::ref(count));
    thr1.join();
    thr2.join();

    clock_gettime(CLOCK_REALTIME, &stop);
    std::cout << "Elapsed: " << millis(start, stop) << std::endl;
    std::cout << "count: " << prettyPrint(count) << std::endl;
    return 0;
}

