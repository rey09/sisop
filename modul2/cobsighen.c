#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_callback_handler(int signum)
{
	if(signum == SIGINT)
	{
	
		printf("Caught signal Interupt\n");
		//exit(SIGINT);
		return;
	}
	else if(signum == SIGTSTP)
	{
		printf("Caught signal Stop\n");
		return;
	}
}




int main()
{
	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);	
	
	
	{
		//char command[10];
		//char suffix[50];
		//scanf("%s", command);
		//scanf("%s", suffix);
		//char *const ps_argv[] = {command, suffix, 0};
		//execvp(command, ps_argv);
		printf("Program processing stuff here.\n");
		sleep(1);
	}
	
	aaaaaaaaa
	while(getchar()!=EOF)
	{
	}

	return EXIT_SUCCESS;
}
