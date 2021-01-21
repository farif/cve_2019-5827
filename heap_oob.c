#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

void memory_oob(int nStat) {

// Allocate Memory.
// a = sqlite3_malloc( (sizeof(u32)+10)*nStat );
    u32 a_size = (sizeof(u32) + 10)*nStat;
    printf("Malloc Size:%u", a_size);

    int *a = malloc(a_size); 

    u32 b_size = (sizeof(u32))*(nStat);
    printf("\nMemset Size:%u\n", b_size);

// Condition: (sizeof(u32))*nSta >= (sizeof(u32) + 10)*nStat
    if(b_size >= a_size) {
        printf("Boom!!!");
    } else {
        memset(a, 0, b_size);
        printf("Memory Initialized.\n");
    }

}


int main()
{
    memory_oob(2);

    return 0;
}
