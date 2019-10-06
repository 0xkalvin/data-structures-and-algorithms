#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int main()
{

    int pid = fork();

    if (pid == 0)
    {
        printf("Running child process!\n");

        execl("/bin/ls", "ls");

    }
    else if(pid > 0)
    {
        printf("Running parent process!\n");

        int pidChild, status;

        pidChild = wait(&status);

        printf("Ending parent process!\n");
    }


    return 0;
}