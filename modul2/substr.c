#include<string.h>
#include<stdio.h>

int main()
{
	char input[50];
	//char *const coba[] = {"ps", "-aux", 0};
	printf("Masukkan string : ");
	scanf("%[^\n]", input);
	
	//printf("%s\n", input);
	//printf("%s\n", coba);
	char *substr = strstr(input, " ");
	substr = substr+1;
	char simpen[10] = {"NULL"};
	int i = 0;
	printf("Hasil strstr() : %s\n", substr);
	char *token = strtok(input, " ");
	simpen[i] = *token;
	while(token!=NULL){	
		printf("Hasil strtok() : %s\n", *simpen[i]);
		i++;	
		token = strtok(NULL, " ");
		simpen[i] = *token;
	}
	
	return 0;
}
