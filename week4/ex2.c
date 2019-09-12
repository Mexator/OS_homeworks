#include <stdio.h>
#include <sys/syscall.h>
int main()
{
    int n;
    for (int i = 0; i < 5; i++)
    {
        n = fork();
    }
    sleep(5);
}