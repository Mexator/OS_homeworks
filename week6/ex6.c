#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    // signal(SIGTERM, sigterm_handler);

    int ch1_pid, ch2_pid;
    int child1_pipe[2], child2_pipe[2];
    //pipe with 1st child
    pipe(child1_pipe);
    //pipe with 2nd child
    pipe(child2_pipe);

    if ((ch1_pid = fork()) != 0)
    {
        if ((ch2_pid = fork()) != 0)
        {
            //PARENT CODE
            fprintf(stdout, "Parent: Children created\n");
            write(child2_pipe[1], &ch1_pid, sizeof(ch1_pid));
            close(child2_pipe[1]);
            write(child1_pipe[1], &ch2_pid, sizeof(ch2_pid));
            close(child1_pipe[1]);
            fprintf(stdout, "Parent: Children know each other PIDs\n");
            int status;
            fprintf(stdout, "Parent: Waiting for Child 2 to change state...\n");
            waitpid(ch2_pid, &status, 0);
            fprintf(stdout, "Parent: Child 2 Changed state to %d\n", status);
        }
        else
        {
            //CHILD 2 CODE 'Abel'
            int recv_id = 0;
            read(child2_pipe[0], &recv_id, sizeof(ch1_pid));
            close(child2_pipe[0]);
            fprintf(stdout, "Child 2: Received PID of Child 1: %d\n", recv_id);
            while (1)
            {
                fprintf(stdout, "Child 2: I\'m alive!\n");
                sleep(1);
            }
        }
    }
    else
    {
        //CHILD 1 CODE 'Kain'
        int recv_id = 0;
        read(child1_pipe[0], &recv_id, sizeof(ch1_pid));
        close(child1_pipe[0]);
        fprintf(stdout, "Child 1: Received PID of Child 2: %d\n", recv_id);
        fprintf(stdout, "Child 1: Waiting 2 sec...\n");
        sleep(2);
        fprintf(stdout, "Child 1: Stopping Child 2\n");
        kill(recv_id, SIGSTOP);
        fprintf(stdout, "Child 1: Resuming Child 2\n");
        kill(recv_id, SIGCONT);
        fprintf(stdout, "Child 1: Killing Child 2\n");
        kill(recv_id, SIGKILL);
    }
}