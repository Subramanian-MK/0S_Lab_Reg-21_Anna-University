#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
    int size = 0, n, pgno, pagetable[3] = {5, 6, 7}, i, frameno;
    unsigned int ra = 0, ofs = 0;
    double m1;
    
    printf("Enter process size (in KB of max 12KB): ");
    scanf("%d", &size);
    
    m1 = (double)size / 4.0;
    n = ceil(m1);
    printf("Total No. of pages: %d\n", n);
    
    printf("Enter relative address (in hexa):\n");
    scanf("%x", &ra);
    
    pgno = ra / 1000;
    ofs = ra % 1000;
    
    printf("Page no: %d\n", pgno);
    printf("Page table:\n");
    for (i = 0; i < n; i++)
        printf("%d:%d ", i, pagetable[i]);
    
    if (pgno >= n) {
        printf("\nInvalid page number!\n");
        return 0;
    }
    
    frameno = pagetable[pgno];
    printf("\nPhysical address: %d %u\n", frameno, ofs);
    return 0;
}