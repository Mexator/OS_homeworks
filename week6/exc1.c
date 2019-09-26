#include <stdio.h>
#include <unistd.h>
int main()
{
    char source[] = "Some sample string";
    char dest[100] = {0};
    int pipe_desc[2];
    //0-read, 1-write
    int status = pipe(pipe_desc);
    if (status == -1)
        fprintf(stderr, "Error during pipe creation\n");

    fprintf(stdout, "Before copying via pipe:\n Source: %s\n Dest: %s\n", source, dest);
    //Copying
    write(pipe_desc[1], source, sizeof(source) + sizeof(char));
    read(pipe_desc[0], dest, 100);

    fprintf(stdout, "After copying via pipe:\n Source: %s\n Dest: %s\n", source, dest);
    return 0;
}