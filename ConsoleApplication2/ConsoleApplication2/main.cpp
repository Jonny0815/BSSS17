#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

int main()
{
	//char input[20];
	int childPid;
	int pfd[2];
	char buffer[20];
	std::string input;

   
	
	

	pipe(pfd);

	childPid = fork();

	if (childPid == 0)
	{

		//child code
		
	

			close(pfd[1]);
			int nbytes = read(pfd[0], buffer , 20);

			std::cout << buffer << std::endl;
			

			exit(1);
		
	}
	else
	{

		//parent code
		
		

			
		do {
			std::cin >> input;


			close(pfd[0]);
			const char *cinput = input.c_str();
			write(pfd[1], cinput, sizeof(input));

		} while (input != "q");

			exit(1);

	}

	


    return 0;
}