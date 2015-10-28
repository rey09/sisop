#include<stdio.h>

int main(void)
{
	char *argv[3] = {"Comman-line", ".", NULL};
	int pid = fork();

	if( pid == 0 )
	{
		execvp("find", argv);
	}
	
	wait(2);
	printf( "selesai eksekusi proses parent\n - child gak bakal ke sini\n");

	return 0;
}
