#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char input[100];
    char*args[20];

    while(1)
    {
        printf("myshell> ");
        fgets(input,100,stdin);

        input[strcspn(input,"\n")]=0;

        if(strcmp(input,"exit")==0)
            break;

        int i=0;
        char*token=strtok(input," ");

        while(token!=NULL)
        {
            args[i]=token;
            i++;
            token=strtok(NULL," ");
        }

        args[i]=NULL;

        pid_t pid=fork();

        if(pid==0)
        {
            char path[100];

            if(args[0][0]=='/')
            {
                execve(args[0],args,NULL);//execute comm
            }
            else
            {
                snprintf(path,100,"/usr/bin/%s",args[0]);
                execve(path,args,NULL);
            }

            return 1;
        }
        else
        {
            printf("process startes in background: PID=%d\n", pid);
        }
    }

    return 0;
}
