#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

#define LSH_TOK_BUFSIZE 25
#define LSH_TOK_DELIM " \t\r\n\a"

void signal_callback_handler(int signum);
void *run1(void* arg);

int main()
{
	//getchar();
	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);	
	void *res;
	pthread_t t1;
	pthread_create(&t1, NULL, &run1, NULL);

	//printf("Can't move this bug, just enter.");
	while(getchar()!=EOF)
	{
		printf("1\n");
		//printf("Can't move this bug, just enter.");
	}

	exit(SIGKILL);
	return EXIT_SUCCESS;
}

void *run1(void *arg)
{
	while(1)
	{

		char command[50], *token;
		int bufsize = LSH_TOK_BUFSIZE, position = 0;
		char **tokens = malloc(bufsize * sizeof(char*));
		pid_t pid;

		printf("Fork program starting\n");
		pid = fork();
		if(pid == 0)
		{
			printf("insert command here : ");
			scanf("%[^\n]", command);
			token = strtok(command, LSH_TOK_DELIM);
			while (token != NULL)
			{
				//printf("token : %s\n", token);
		//		if(strcmp(token, "&")!=0)
		//		{
					tokens[position] = token;
					position++;
					printf("%s\n", tokens[position-1]);	
		//		}
		//		else
		//		{
		//			flag = 1;
		//		}	
				// if (position >= bufsize) 
				// {
				//     bufsize += LSH_TOK_BUFSIZE;
				// 	tokens = realloc(tokens, bufsize * sizeof(char*));
			 //   	}
				token = strtok(NULL, LSH_TOK_DELIM);
				//printf("jalan A\n");
			}
			//printf("Jalan B\n");
			if(strcmp(tokens[0],"cd")==0)
			{
				chdir(tokens[1]);
			}
			else
			{
				execvp(tokens[0], tokens);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
				//printf("Jalan C\n");
				int childStatus;
				//printf("%d", childStatus);
				pid_t returnValue = waitpid(pid, &childStatus, 0);
				if(returnValue > 0)
				{
					if(WIFEXITED(childStatus))
						printf("Exit Code: %d\n", WEXITSTATUS(childStatus));
					else
						printf("Exit status: 0x%.4x\n", childStatus);
				}
		}
		
//		token = "NULL";
//		free(tokens);
	}
}

void signal_callback_handler(int signum)
{
	if(signum == SIGINT)
	{
	
		printf("Caught signal SIGINT\n");
		return;
	}
	else if(signum == SIGTSTP)
	{
		printf("Caught signal SIGTSTP\n");
		return;
	}
}