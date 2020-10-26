#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


void childTask()
{
	char name[40];
	printf("Enter Name:\n");
	fgets(name, 40, stdin);
	printf("Name:%s\n", name);
	exit(0);
}

void parentTask()
{
	printf("Waiting for child process to finish.\n");
	wait(NULL);
	printf("Job is done.\n");
}

int main(void)
{
	for(int i=1; i<5; i++)
	{
		int pid = fork();

		if(pid ==0)
		{
			childTask();
		}

		else
		{
			parentTask();
		}
	}
	return 0;
}
