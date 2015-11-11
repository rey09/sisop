#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define LSH_TOK_BUFSIZE 70
#define LSH_TOK_DELIM " \t\r\n\a"

void signal_callback_handler(int signum);

int main()
{

	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);	

	while(1)
	{
		printf("tekan ctrl+D untuk keluar, tekan enter untuk lanjut");
		if(getchar()==EOF)
		{
			break;
		}
		else
		{
			char command[150], *token;
			int bufsize = LSH_TOK_BUFSIZE, position = 0, flag = 0;
			char **tokens = malloc(bufsize * sizeof(char*));
			pid_t pid;

			printf("insert command here : ");
			scanf("%[^\n]", command);
			getchar();
			token = strtok(command, LSH_TOK_DELIM);
			while (token != NULL)
			{
				if(strcmp(token,"&")!=0)
				{
					tokens[position] = token;
					position++;
				}
				else
				{
					flag = 1;
					printf("%s\n", token);
				}	
				if (position >= bufsize) 
				{
				    bufsize += LSH_TOK_BUFSIZE;
					tokens = realloc(tokens, bufsize * sizeof(char*));
			   	}
				token = strtok(NULL, LSH_TOK_DELIM);
			}

			pid = fork();
			if(pid == 0)
			{
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
				if (flag == 1)
				{
					continue;
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
	}
	exit(SIGKILL);
	return EXIT_SUCCESS;
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