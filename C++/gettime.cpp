#include <cstdio>
#include <ctime>

inline long millis(struct timespec const& start, struct timespec const& stop)
{
    return (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_nsec - start.tv_nsec) / 1000000;
}

int main(int argc, char* argv[])
{
    long count = 0;
    struct timespec start, stop;

    clock_gettime(CLOCK_REALTIME, &start);
    long ms = 0;

    while (ms < 1000)
    {
        ++count;
        clock_gettime(CLOCK_REALTIME, &stop);
        ms = millis(start, stop);
    }

    printf("count: %ld\n", count);
}

