#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

#define MAX_COUNT 9999
#define BUF_SIZE 100

void main(void)
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];
	
	fork();
	pid = getpid();
	for(i=1;i<=MAX_COUNT;i++)
	{
		sprintf(buf,"this line is fomr pid %d ,value =%d\n",pid,i);
		write(1,buf,strlen(buf));
	}
}

