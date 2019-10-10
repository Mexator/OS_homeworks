#include <malloc.h>
#include <string.h>
#include <sys/resource.h>
int main()
{
    int count = 10;
    const size_t AllocSize = 10 * 1024 * 1024;
    void *mem[count];
    for (int i = 0; i < count; i++)
    {
        mem[i] = malloc(AllocSize);
        memset(mem[i], 0, AllocSize);
        struct rusage tmp;
        getrusage(RUSAGE_SELF, &tmp);
        printf("Resident set size(memory in RAM): %d\n", tmp.ru_maxrss);
        sleep(1);
    }
    for (int i = 0; i < count; i++)
    {
        free(mem[i]);
    }
}