#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid == 0)
    {
        // Child Process
        printf("Child Process:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else if (pid > 0)
    {
        // Parent Process
        printf("Parent Process:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else
    {
        // Fork failed
        printf("Fork failed\n");
    }

    return 0;
}
