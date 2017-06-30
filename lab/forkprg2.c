// C Program to implement LINUX fork() system call
// Parent process distinguished from the child process

#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>


#define MAX_COUNT 99
void ChildProcess(void); //Child process prototype
void ParentProcess(void); //Parent process prototype
void main(void)
{
	pid_t pid;
	pid=fork();
	printf("Process Id:%d\n",pid);
	if(pid==0)
	ChildProcess();
	else
	ParentProcess();
}
void ChildProcess(void)
{
	//ChildProcess();
	int i;
	for(i=1; i<=MAX_COUNT; i++)
	printf("This line is from child value=%d\n",i);
	printf("***Child process is done***\n");	
}

void ParentProcess(void)
{
	//ChildProcess();
	int i;
	for(i=1;i<MAX_COUNT;i++)
	printf("This line is from parent,value=%d\n",i);
	printf("***Parent is done***\n");
}
