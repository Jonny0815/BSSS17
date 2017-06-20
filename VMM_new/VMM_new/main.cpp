#include <cstdio>

#include "processing_unit.h"

int main()
{
	processing_unit pu;

	for (size_t i = 0; i < 200; i++)
	{
		pu.work();
	}

	pu.report();

    return 0;
}