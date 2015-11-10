#include<stdio.h>
#include<string.h>
#include<string>


int main()
{
	char input[50];
	printf("Masukkan String : ");
	scanf("%[^\n]", input);

	printf("%s\n", input);
	char *substr = strstr(input, "o");

	printf("Hasil strstr() : %s\n", substr);
	return 0;
}
