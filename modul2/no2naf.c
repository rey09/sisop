#include <stdio.h>
#include <pthread.h>

void *banyakprima(void*);
void cekprima(int);
int count=0;

int main()
{
	int n, i, a[100000];
	printf("Masukkan N: ");
	scanf("%d",&n);

	void *pointer = &n;
	pthread_t thread[100000];
	
	for(i=0; i<n; i++)
	{
		a[i]=i;
		pthread_create(&thread[i],NULL,banyakprima,(void*)a[i]);
	}
	
	for(i=0; i<n; i++)
	{
		pthread_join(thread[i],NULL);
	}	
	
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
	if(number<=1)
	{
		printf("%d adalah bukan bilangan prima", number);
		return;
	}
	else if(number<=3)
	{
		count++;
		printf("%d adalah bilangan prima", number);
		return;
	}
	else if((number%2)==0 || (number%3)==0)
	{
		printf("%d adalah bukan bilangan prima", number);
		return;
	}
	int i = 5;
	while((i*i) <= number)
	{
		if((number%i)==0 || (number%(i+2))==0)
		{
			printf("%d adalah bukan bilangan prima", number);
			return;
		}
		i = i + 6;
	}
	count++;
	printf("%d adalah bilangan prima", number);
	return;
}
