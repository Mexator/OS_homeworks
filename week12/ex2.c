
//However it was included, it is used only to print errors
#include <stdio.h>

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>

//Size of block to read from stdin
#define READ_LEN 255
//File descriptors for stdin & stdout
#define STDIN_DESCRIPTOR 0
#define STDOUT_DESCRIPTOR 1
//Set to 1 to create output file if it not exists
#define CREATE_OUTPUTS 1

int main(int argc, char *argv[])
{
    //Checking for appeng flag
    int append = 0;
    if (argc > 1 && strcmp(argv[1], "-a") == 0)
        append = 1;

    //Opening files
    int files_in_total = argc - append;
    int output_des[files_in_total];
    output_des[0] = STDOUT_DESCRIPTOR;

    for (int i = 1; i < files_in_total; i++)
    {
        output_des[i] = open(argv[i + append], (O_APPEND * append) | (O_CREAT * CREATE_OUTPUTS) | O_RDWR,
                             S_IRWXG | S_IRWXO | S_IRWXU);
        if (output_des[i] == -1)
        {
            fprintf(stderr, "Error while opening file %s\n", argv[i + append]);
            return -1;
        }
    }
    //Starting read & write
    char str[READ_LEN] = "";
    int actually_read = 0;
    while ((actually_read = read(STDIN_DESCRIPTOR, str, sizeof(str))) > 0)
    {
        for (int i = 0; i < files_in_total; i++)
        {
            //Trying to write out
            if (write(output_des[i], str, actually_read) == -1)
            {
                fprintf(stderr, "Error while writing file with descriptor %d\n", output_des[i]);
                return -1;
            }
        }
    }

    for (int i = 0; i < files_in_total; i++)
    {
        close(output_des[i]);
    }
}