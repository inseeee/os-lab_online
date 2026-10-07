#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    pid_t pid1,pid2;
    clock_t start,end;
    double time;

    pid1=fork();

    if(pid1==0)
    {
        //time starts after fork
        start=clock();
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC*1000;

        printf("Child 1: PID=%d, PPID=%d, time=%.3f ms\n",getpid(),getppid(),time);
        return 0;
    }

    pid2=fork();

    if(pid2==0)
    {
        //tme starts after fork
        start=clock();
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC*1000;

        printf("Child 2: PID=%d, PPID=%d, time=%.3f ms\n",getpid(),getppid(),time);
        return 0;
    }

    start=clock();
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC*1000;

    printf("Parent: PID=%d, PPID=%d, time=%.3f ms\n",getpid(),getppid(),time);

    wait(NULL);
    wait(NULL);

    return 0;
}
