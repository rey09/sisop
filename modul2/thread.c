#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

void *run(void *args){
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

void *run2(void *args){
	int i;
	
	for(i=1; i<=30; i++)
	{
		printf("Thread 2 : %d\n", i);
	}
}

int main(){
	pthread_t t1, t2;
	void *thread_result;
	//pthread_create(&t1, NULL, run, NULL);
	pthread_create(&t2, NULL, run2, NULL);
	pthread_create(&t1, NULL, run2, NULL);
	int i;
	pthread_join(t2, &thread_result);
	for(i=1; i<=30; i++)
	{
		printf("Main : %d\n", i);
	}

	return 0;
}	
