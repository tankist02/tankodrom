#include <cstdlib>
#include <iostream>

void* safe_ptr(void* p) { if (!p) exit(1); return p; }

#define INIT(TYPE) safe_ptr(malloc(sizeof (TYPE)))

int* get_intbuffer()
{
    enum { N = 3 };
    int* const intbuffer = (int*)INIT(int[N]);
    int i = N;
    while (i--) intbuffer[i] = i;
    return intbuffer;
}

int main()
{
    int* intbuffer = get_intbuffer();
    for (int i = 0; i < 3; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    free(intbuffer);
    return 0;
}

