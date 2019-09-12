#include <stdio.h>
#include <sys/syscall.h>
int main()
{
    int n;
    if (n = fork())
        printf("Hello from parent [PID - %d]\n", getpid());
    else
    {
        printf("Hello from child [PID - %d]\n", getpid());
    }
}