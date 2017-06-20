#include <cstdio>
#include <time.h>

#include "processing_unit.h"

int main()
{
	//problems with srand(time(NULL)) on linux !!!
	srand(4);

	processing_unit pu;

	for (size_t i = 0; i < 200; i++)
	{
		pu.work();
	}

	pu.report();

    return 0;
}