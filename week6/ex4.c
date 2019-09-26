#include <signal.h>
#include <stdio.h>
void sigkill_handler()
{
    fprintf(stdout, "SigKill Signal received\n");
}
void sigstop_handler()
{
    fprintf(stdout, "SigStop Signal received\n");
}
void sigusr1_handler()
{
    fprintf(stdout, "SigUsr1 Signal received\n");
}
int main()
{
    signal(SIGKILL, sigkill_handler);
    signal(SIGSTOP, sigstop_handler);
    signal(SIGUSR1, sigusr1_handler);

    fprintf(stdout, "PID=%d\n", getpid());
    sleep(60);
}