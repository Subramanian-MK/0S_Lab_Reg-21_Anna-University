#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int i, pid;
    pid = fork();
    if (pid == -1)
    {
        printf("fork failed\n");
        exit(0);
    }
    else if (pid == 0)
    {
        printf("\nChild process starts\n");
        for (i = 0; i < 5; i++)
        {
            printf("Child process %d is called\n", i);
        }
        printf("Child process ends\n");
    }
    else
    {
        wait(NULL);
        printf("\nParent process ends\n");
    }
    exit(0);
}
