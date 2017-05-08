#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main()
{
	//char input[20];
	int childPid;
	int pfd[2];
	char buffer[20];
	char input[20];
	std::string sbuffer;
	
   
	
	std::cout << "bla" << std::endl;

	pipe(pfd);

	childPid = fork();

	if (childPid == 0)
	{

		//child code
		
		while (sbuffer != "Quit")
		{

			close(pfd[1]);
			int nbytes = read(pfd[0], buffer, 20);

			sbuffer = std::string(buffer);

			

				std::cout << "Manager: " <<sbuffer << std::endl;

			
		}
		

			


			
		
	}
	else
	{

		//parent code
		
		

		while (input != "Quit")
		{
			std::cout << "Command: ";
			std::cin >> input;


			close(pfd[0]);
			write(pfd[1], input, 20);

		


			sleep(1);

			

		}

			exit(0);

	}

	


    return 0;
}