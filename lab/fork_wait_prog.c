//
// Myron CJ Fernandes 1647215 3MCA
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COUNT 10
#define BUF_SIZE 1024

void childProcess(char []);

void main(void){
    pid_t pid1,pid2;
    int status,i;
    char buf[BUF_SIZE];

    printf("\nParent is about to fork process 1\n");
    if((pid1=fork())<0){
        printf("\nFailed to create a fork process\n ");
        exit(1);
    }
    else if(pid1==0)
        childProcess("\nFirst");

    printf("\nParent is about to fork process 2\n");
    if((pid2=fork())<0){
        printf("\nFailed to create a fork process\n ");
        exit(1);
    }
    else if(pid2==0)
        childProcess("\nSecond");

    sprintf(buf,"\nParent Entering waiting state");
    write(1,buf,strlen(buf));
    pid1=wait(&status);
    sprintf(buf,"\nParent detects a process %d is done",pid1);
    write(1,buf,strlen(buf));
    pid2=wait(&status);
    sprintf(buf,"\nParent detects a process %d is done",pid2);

    printf("\nParent exits");
    exit(0);
}

void childProcess(char *number){
    pid_t pid;
    int i;
    char buf[BUF_SIZE];

    pid = getpid();
    sprintf(buf,"\n%s child process starts (pid = %d)\n",number,pid);
    write(1,buf,strlen(buf));
    for(i=0;i<=MAX_COUNT;i++){
        sprintf(buf,"%s child's output value = %d \n",number,i);
        write(1,buf,strlen(buf));
    }
    sprintf(buf,"\n%s child pid = %d is about to exit",number,pid);
    write(1,buf,strlen(buf));
    exit(0);
}