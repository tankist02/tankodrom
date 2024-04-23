#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>

//#define CLOCK_TYPE CLOCK_REALTIME
//#define CLOCK_TYPE CLOCK_REALTIME_COARSE

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

void process(int clock_type, char const* msg)
{
    long count = 0;
    struct timespec start, stop;

    clock_gettime(clock_type, &start);
    long ms = 0;

    while (ms < 1000)
    {
        ++count;
        clock_gettime(clock_type, &stop);
        ms = millis(start, stop);
    }

    std::cout << msg << ": " << prettyPrint(count) << std::endl;
}

int main(int argc, char* argv[])
{
    process(CLOCK_REALTIME, "realtime");
    process(CLOCK_REALTIME_COARSE, "realtimecoarse");
}

