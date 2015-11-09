#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

void signal_callback_handler(int signum)
{
	if(signum == SIGINT)
	{
	
		printf("Caught signal Interupt\n");
		return;
	}
	else if(signum == SIGTSTP)
	{
		printf("Caught signal Stop\n");
		return;
	}
}

void *run1(void *arg)
{
	while(1)
	{
		pid_t pid;

		printf("Fork program starting\n");
		pid = fork();
		if(pid == 0)
		{
			char command[10];
			char suffix[50];
			scanf("%s", command);
			scanf("%s", suffix);
			char *const ps_argv[] = {command, suffix, 0};
			execvp(command, ps_argv);
			exit(EXIT_FAILURE);
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
		}
	}
}

int main()
{
	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);	
	
	pthread_t t1;
	pthread_create(&t1, NULL, &run1, NULL);

	while(getchar()!=EOF)
	{
		printf("1\n");
	}
	exit(SIGKILL);
	return EXIT_SUCCESS;
}
