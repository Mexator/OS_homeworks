#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define INPUT "ex1.txt"
#define OUTPUT "ex1.memcpy.txt"
int main()
{
    int in_des = open(INPUT, O_RDONLY);

    char command[80] = "touch ";
    strcat(command, OUTPUT);
    system(command);
    int out_des = open(OUTPUT, O_RDWR);

    struct stat *file_stat = malloc(sizeof(struct stat));
    stat(INPUT, file_stat);
    size_t in_size = file_stat->st_size;

    ftruncate(out_des, in_size);

    char *input = mmap(0, in_size, PROT_READ, MAP_SHARED, in_des, 0);
    char *output = mmap(0, in_size, PROT_WRITE, MAP_SHARED, out_des, 0);

    memcpy(output, input, in_size);

    munmap(input, in_size);
    munmap(output, in_size);
    close(in_des);
    close(out_des);
}