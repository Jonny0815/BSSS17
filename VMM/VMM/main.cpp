#include <cstdio>
#include <iostream>

#include "processing_unit.h"

int main()
{
	
	processing_unit pu;

	for (size_t i = 0; i < 20; i++)
	{
		pu.work();
	}
    
    return 0;
}