#include <cstring>
#include <malloc.h>
#include <iostream>
#include <vector>

void show_mallinfo2()
{
    struct mallinfo2 mi = mallinfo2();
    printf("Total non-mmapped bytes (arena):       %zu (%.1f MB)\n", mi.arena, mi.arena / 1024.0);
    printf("# of free chunks (ordblks):            %zu\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %zu\n", mi.smblks);
    printf("# of mapped regions (hblks):           %zu\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %zu (%.1f MB)\n", mi.hblkhd, mi.hblkhd / 1024.0);
    printf("Max. total allocated space (usmblks):  %zu\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %zu\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %zu (%.1f MB)\n", mi.uordblks, mi.uordblks / 1024.0);
    printf("Total free space (fordblks):           %zu (%.1f MB)\n", mi.fordblks, mi.fordblks / 1024.0);
    printf("Topmost releasable block (keepcost):   %zu (%.1f MB)\n", mi.keepcost, mi.keepcost / 1024.0);
}

int main(int argc, char* argv[])
{
    //void* p;
    {
        int num = 1000;
        if (argv[1]) { num = atoi(argv[1]); }
        std::cout << "num: " << num << std::endl;
        std::vector<char> vd(num * 1000);
        //p = malloc(num * 1000);
        //memset(p, 0, num * 1000);
        std::cout << "After alloc\n";
        show_mallinfo2();    
    }
    //free(p);
    std::cout << "\nAfter free\n";
    show_mallinfo2();    
    return 0;
}

