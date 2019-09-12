#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
int main()
{
    char command[1023] = {0};
    printf("Welcome to My Simplistic Shell.\nEnter exit to exit\n");
    while (strcmp(command, "exit\n"))
    {
        printf("Please, enter command:\n");
        fgets(command, 1022, stdin);
        system(command);
    }
}