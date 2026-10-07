#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char*argv[])
{
    int n=atoi(argv[1]);

    for(int i=0;i<n;i++)
    {
        //crreate a new process
        fork();
        sleep(5);
    }

    return 0;
}
