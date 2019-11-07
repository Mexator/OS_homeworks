#include <stdio.h>

#define SIZE 20
int main()
{
    FILE *file = 0;
    FILE *out = 0;
    if (!(file = fopen("/dev/random", "r")))
    {
        fprintf(stderr, "Error during opening device\n");
        return -1;
    }
    if (!(out = fopen("ex1.txt", "w+")))
    {
        fprintf(stderr, "Error during opening output file\n");
        return -1;
    }
    char string[SIZE] = "";
    if (fread(string, sizeof(char), SIZE, file) < SIZE)
    {
        fprintf(stderr, "Error during reading device\n");
        return -1;
    }
    fprintf(out, "%s", string);
    fclose(file);
    fclose(out);
}