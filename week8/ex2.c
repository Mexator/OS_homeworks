#include <malloc.h>
#include <string.h>
#include <unistd.h>
#define AllocSize (size_t)4000 * 1024 * 1024
//was tuned manually to make system use swap
int main()
{
    void *mem1 = malloc(AllocSize);
    void *mem2 = malloc(AllocSize);
    // void *mem3 = malloc(AllocSize);
    // memset(mem3, 0, AllocSize);
    memset(mem1, 0, AllocSize);
    memset(mem2, 0, AllocSize / 2);
    free(mem1);
    free(mem2);
    sleep(1);
}
/*
The output shows that when operating system runs out of memory, it can use swapfile 
on the disk, to enlarge virtual memory. SI and SO fields stand for 'swapped in'
and 'swapped out' that is amount of processes memory that was moved from disk 
and to disk respectively   
The output of ./ex2 & vmstat 1                       [1] 2029
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 4682024 102880 1474568    0    0   523    32  277  787  8  4 67 21  0
 1  0      0 2092448 102880 1474496    0    0     0     0  862 1230  4  9 86  0  0
 2  0  16140 175912  99808 1168664    0 15648     0 16432 1656 5217  5 11 82  3  0
 0  5  53248 105980  33560 899964 8092 43684  8092 43804 1495 2065  1  9 55 35  0
 1  2  37888 157504   8948 855776 15248  136 18984   136 1919 2183  0 11 54 35  0
 1  9  64512 129084   4012 503604 8856 36248 12888 36248 1896 3069  1  9 44 47  0
 1  8  93696 107548    884 433248 3732 32400  8392 32568 1676 2171  1  4 37 58  0
 0 17 104192 112892    952 406296  128 11132  3420 11268 1063 1523  0  3  6 91  0
 0 19 116992 108660    964 392192   80 12572  4900 12800  747  881  0  2  4 94  0
 0 20 147968 115708   1044 362600   32 30804  4696 30844  665 1039  0  3  7 90  0
 2 20 176384 116296    808 338012   48 29168  4948 29236 1386 1544  0  2  6 92  0
 1 24 218680 132704    728 300144   12 41996  2492 41996 1399 1804  0  3  6 91  0*/