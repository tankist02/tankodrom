#include <iostream>
#include <vector>
#include <jemalloc/jemalloc.h>

void show_jemalloc_stats(char const* msg = nullptr)
{
	double const MB = 1024.0 * 1024.0;
	if (msg != nullptr) { std::cout << msg << std::endl; }
	uint64_t epoch = 1;
    size_t sz = sizeof(epoch);
    mallctl("epoch", &epoch, &sz, &epoch, sz);

	// Get basic allocation statistics.  Take care to check for
	// errors, since --enable-stats must have been specified at
	// build time for these statistics to be available.
	size_t allocated, active, metadata, resident, mapped;
	sz = sizeof(size_t);
	if (mallctl("stats.allocated", &allocated, &sz, NULL, 0) == 0
		&& mallctl("stats.active", &active, &sz, NULL, 0) == 0
		&& mallctl("stats.metadata", &metadata, &sz, NULL, 0) == 0
		&& mallctl("stats.resident", &resident, &sz, NULL, 0) == 0
		&& mallctl("stats.mapped", &mapped, &sz, NULL, 0) == 0) 
	{
		fprintf(stderr,
			"allocated: %zu (%.2f MB)\nactive: %zu (%.2f MB)\nmetadata: %zu (%.2f MB)\nresident: %zu (%.2f MB)\nmapped: %zu (%.2f MB)\n\n",
			allocated, allocated / MB, active, active / MB, metadata, metadata / MB, resident, resident / MB, mapped, mapped /MB);
	}
}

int main(int argc, char* argv[])
{
    size_t size = 1000 * 1000;
    if (argv[1] ) { size = atoi(argv[1]); }
    std::cout << "size: " << size << std::endl;

	show_jemalloc_stats("Before malloc");

    int* buf = static_cast<int*>(malloc(size * sizeof(int)));
    //memset(buf, 0, size);
    for (size_t i = 0; i < size; ++i)
    {
        buf[i] = i;
    }
	show_jemalloc_stats("After malloc");
    free(buf);
	show_jemalloc_stats("After free");

    //malloc_stats_print(NULL, NULL, NULL);

	show_jemalloc_stats("Before vector");
	{
        std::vector<int> v(size);
        for (size_t i = 0; i < size; ++i) { v[i] = i; }
	    show_jemalloc_stats("After vector");
	}
    show_jemalloc_stats("After vector dtor");

    return 0;
}

