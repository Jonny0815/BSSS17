#include <cstdio>
#include <iostream>
#include <unistd.h>



int main()
{
	char input[20];
	int a;

    printf("hello from ConsoleApplication over 9000!\n");
	scanf("%19[0-9a-zA-Z ]", input);
	printf(input);

	fork();


	printf("\n after fork\n");


    return 0;
}