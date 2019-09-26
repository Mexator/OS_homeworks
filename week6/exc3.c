#include <signal.h>
#include <stdio.h>
void sigint_handler()
{
    fprintf(stdout, "  Ha-ha You can not kill me\n");
}
int main()
{
    signal(SIGINT, sigint_handler);
    fprintf(stdout, "try to Ctr+C this. You have 3 seconds\n");
    for (int i = 0; i < 3; i++)
    {
        fprintf(stdout, "%d\n", 3 - i);
        sleep(1);
    }

    fprintf(stdout, "Ok, i will terminate voluntary\n");
}