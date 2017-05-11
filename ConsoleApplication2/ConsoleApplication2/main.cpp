#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "reporter.h"
#include "scheduler.h"
#include "processor.h"
#include "scheduler_algorythm_1.h"


int childPid;
int pfd[2];
char buffer[20];
char input[20];
std::string sbuffer;
bool automode = false;
reporter *Reporter = new reporter;
scheduler *Scheduler = new scheduler_algorythm_1; // chose scheduler here !!!



int main()
{
	
	
   
	
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


				// bad menu solution - rework TODO


				//report
				if (sbuffer == "Report")
				{
					
					Reporter->report();

				}

				//automode
				if (sbuffer == "Mode")
				{
					automode = true;

					Scheduler->set_automode(true);

					Scheduler->schedule();

					std::cout << "Changing to automode !" << std::endl;

				}


				//step
				if (sbuffer == "Step")
				{
					if (automode == false)
					{
						Scheduler->schedule();
					}
					else {

						std::cout << "Step can only be used in Debug Mode" << std::endl;

					}
				}

			
				//unblock
				if (sbuffer == "Unblock")
				{

					Scheduler->user_unblock_oldest();

				}


				//print
				if (sbuffer == "Print")
				{
					Reporter->report();
				}




		// menu ends here
		}
		

			


			
		
	}
	else
	{

		//parent code
		
		// TODO scheduler select !!!




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

	
	delete Reporter;


    return 0;
}