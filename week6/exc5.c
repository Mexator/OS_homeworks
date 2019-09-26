#include <signal.h>
#include <stdio.h>
// void sigterm_handler()
// {
//     fprintf(stdout, "SIGTERM received");
// }
int main()
{
    // signal(SIGTERM, sigterm_handler);

    int ch_pid;
    if ((ch_pid = fork()) != 0)
    {
        sleep(10);
        kill(ch_pid, SIGTERM);
    }
    else
    {
        while (1)
        {
            fprintf(stdout, "I\'m alive, %d\n", getpid());
            sleep(1);
        }
    }
}