#include <stdio.h>
#include <unistd.h>
int main()
{
    int pipe_desc[2];
    //0-read, 1-write
    int status = pipe(pipe_desc);
    if (status == -1)
        fprintf(stderr, "Error during pipe creation\n");

    if (fork() != 0)
    {
        //Copying
        char source[] = "Some sample string";
        fprintf(stdout, "Sent via pipe:\n %s\n", source);
        write(pipe_desc[1], source, sizeof(source) + sizeof(char));
        close(pipe_desc[1]);
    }
    else
    {
        char dest[100] = {0};
        read(pipe_desc[0], dest, 100);
        close(pipe_desc[0]);
        fprintf(stdout, "Received via pipe:\n %s\n", dest);
    }

    return 0;
}