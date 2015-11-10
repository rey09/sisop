#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;


int main()
{
	string input;
	//char *const coba[] = {"ps", "-aux", 0};
	printf("Masukkan string : ");
	scanf("%[^\n]", input);
	
	printf("%s\n", input);
	//printf("%s\n", coba);
	char *substr = strstr(input, " ");

	printf("Hasil strstr() : %s\n", substr);
	// char *token = strtok(input, " ");
	// while(token!=NULL){	
	// 	printf("Hasil strtok() : %s\n", *simpen[i]);
	// 	token = strtok(NULL, " ");
	// }
	
	return 0;
}
