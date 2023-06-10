#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid;
    pid=fork();
    //fork meaning process or calling of process and it creates child and parent processes.
    //negative id then no process created so fork failed.
    if(pid<0){
        printf("fork failed");
        exit(1);
        
    }
    //id=0, child process created and execlp used to stop all other processes and replace it with the child process ie no parent process
    if(pid==0){            
        execlp("/bin/date","date",NULL);
        exit(0);
    }
    //here positive id means the id is of parent process.
    else{
       printf("process id is %d\n",getpid());
       wait(NULL);
       exit(0);
    }
    return 0;
}
