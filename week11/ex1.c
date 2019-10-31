#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#define FILENAME "ex1.txt"
int main()
{
    char command[80] = "touch ";
    strcat(command, FILENAME);
    system(command);

    int filedes = open(FILENAME, O_RDWR);
    system("echo random_str >> ex1.txt");
    const char *str = "This is a nice day";

    ftruncate(filedes, strlen(str));
    char *mapped_file = mmap(0, strlen(str) + 1, PROT_READ | PROT_WRITE, MAP_SHARED, filedes, 0);

    strcpy(mapped_file, str);
    munmap(mapped_file, strlen(str));
    close(filedes);
}