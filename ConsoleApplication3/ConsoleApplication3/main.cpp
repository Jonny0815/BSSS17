#include <cstdio>
#include <iostream>
#include <vector>


#include "operating_system.h"
//#include "mmu.h"
//#include "common.h"
//#include "processor.h"




int main()
{
    

	

	operating_system* os = new operating_system;
	/*mmu* MMU = new mmu(os);
	processor cpu1(os, MMU);

	int commands_processed = 0;

	while (cpu1.work() && commands_processed <= max_cpu_op)
	{
		commands_processed++;
	}

	delete MMU;*/
	delete os;

    return 0;
}