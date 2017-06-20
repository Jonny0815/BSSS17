// Win_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "processing_unit.h"

int main()
{
	srand(time(NULL));


	processing_unit pu;

	for (size_t i = 0; i < 200; i++)
	{
		pu.work();
	}

	pu.report();
	

    return 0;
}

