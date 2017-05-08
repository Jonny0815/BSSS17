#include "reporter.h"
#include <unistd.h>
#include <iostream>

reporter::reporter()
{
}


reporter::~reporter()
{
}

void reporter::report() {


	int reportPid = fork();

	if (reportPid == 0)
	{

		//report code

		std::cout << "Report: " << std::endl; //TODO


	}

}