#include <stdio.h>
#include <pthread.h>

void *banyakprima(void*);
void cekprima(int);
int count=0;

int main()
{
	int n;
	printf("Masukkan N: ");
	scanf("%d",&n);
	
	int *pointer = &n;
	pthread_t thread;
	pthread_create(&thread,NULL,banyakprima,(void*) pointer);
	pthread_join(thread,NULL);	
	
	printf("Banyaknya bilangan prima sebelum n ada %d\n" ,count);
	return 0;
}

void *banyakprima (void* arg)
{
	int* n=(int*) arg;
	pthread_t thread;
	int angka= *n-1;
	if (*n>=1)
	{
		*n=*n-1;
		pthread_create(&thread, NULL , banyakprima , (void*)n);
		cekprima(angka);
		pthread_join(thread,NULL);
	}
}

void cekprima(int number)
{
	int i,counter=0;
	for(i=1;i<number;i++)
	{
		if (number%i==0) counter++;
	}
	if (counter==1) 
	{
		printf("%d adalah bilangan prima\n",number);
		count++;
	}
	else 
		printf("%d adalah bukan bilangan prima\n",number);
}
