#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
	pid_t pid;
	char *message;
	int n;


	printf("Fork program starting\n");
	pid = fork();
	if(pid == 0)
	{
		int i=0;
		// char command[10];
		// char suffix[50];
		// scanf("%s", command);
		// scanf("%s", suffix);
		// char *const ps_argv[] = {command, suffix, 0};
		// execvp(command, ps_argv);
		// exit(EXIT_FAILURE);
		for(; i<=100; i++)
		{
			printf("%d\n",i);
			sleep(1);
		}
	}
	else
	{
		int childStatus;
		pid_t returnValue = waitpid(pid, &childStatus, 0);
		if(returnValue > 0)
		{
			if(WIFEXITED(childStatus))
				printf("Exit Code: %d\n", WEXITSTATUS(childStatus));
			else
				printf("Exit status: 0x%.4x\n", childStatus);
		}
		else if(returnValue == 0)
			printf("Child process still running\n");
		else
		{
			if(errno == ECHILD)
		 	printf(" Error ECHILD!!!\n");
			else if(errno == EINTR)
			printf(" Error EINTR!!!\n");
			else
			printf(" Error EINVAL!!!\n");
		}
	}
	return 0;
}
