#include<stdio.h>
#include<pthread.h>


void *copy_1(void *args)
{
	int* flag=(int*)args;
	FILE *inp ,*out;

	inp= fopen("file1.txt","r");
	out= fopen("file2.txt","w");
	*flag=1;
	char temp;
	while(1)
	{
		temp= fgetc(inp);
		if(temp==EOF)break;
		else fputc (temp,out);
	}
	fclose(inp);
	fclose(out);
	*flag=3;
}

void *copy_2(void *args)
{
	int* flag=(int*)args;
	FILE *inp,*out;

	while(1)
	{
	if (*flag==0) continue;
	else 
		{
			inp=fopen("file2.txt","r");
			break;
		}
}
out= fopen("file3.txt","w");
char temp;

while (1)
{
temp=fgetc(inp);
	if (temp==EOF) 
	{
		if(*flag==1)continue;
		else break;
	}
	else fputc(temp,out);
}
	fclose(inp);
	fclose(out);
}

int main()
{
	pthread_t t1,t2;
	int flag=0;
	pthread_create(&t1,NULL,copy_1,&flag);
	pthread_create(&t2,NULL,copy_2,&flag);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
