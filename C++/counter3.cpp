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

//volatile bool cont = true;
std::atomic<bool> cont = true;
//std::atomic_bool cont = true;
//std::atomic_flag cont = ATOMIC_FLAG_INIT;

void sleeper()
{
    usleep(1'000'000);
    //usleep(1000);
    cont = false;
    //cont.store(false, std::memory_order_relaxed);
    //cont.clear();
}

void counter(long& count)
{
    while (cont) { ++count; }
    //while (cont.load(std::memory_order_relaxed)) { ++count; }
    //while (cont.test_and_set()) { ++count; }
}

int main(int argc, char* argv[])
{
    //cont.store(true, std::memory_order_relaxed);
    //cont.test_and_set();
    //auto start = clock();
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);

    long count = 0;
    
    auto thr = std::jthread(sleeper);
    counter(count);

    clock_gettime(CLOCK_REALTIME, &stop);
    std::cout << "Elapsed: " << millis(start, stop) << std::endl;
    std::cout << "count: " << prettyPrint(count) << std::endl;
    return 0;
}

