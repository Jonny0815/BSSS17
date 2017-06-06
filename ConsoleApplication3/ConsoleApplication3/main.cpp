#include <cstdio>
#include <iostream>
#include <vector>


#include "operating_system.h"
#include "mmu.h"
#include "common.h"




int main()
{
    

	

	operating_system* os = new operating_system;
	mmu MMU(os, offset, mem_wide);




	delete os;

    return 0;
}