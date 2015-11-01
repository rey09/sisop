#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_callback_handler(int signum)
{
	if(signum == SIGINT)
	{
	
		printf("Caught signal Interupt\n");	
		//Cleanup and close up stuff here
		//Terminate program
		exit(SIGINT);
	}
	else if(signum == SIGTSTP)
	{
		printf("Caught signal Stop\n");	
		//Cleanup and close up stuff here
		//Terminate program
		exit(SIGTSTP);
	}
}

int main()
{
	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);
	
	while(1)
	{
		printf("Program processing stuff here.\n");
		sleep(1);
	}
	return EXIT_SUCCESS;
}
