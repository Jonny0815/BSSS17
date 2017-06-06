#include <cstdio>
#include <iostream>
#include <vector>


#include "operating_system.h"
#include "mmu.h"

const int mem_wide = 16; 
const int offset = 10; // keep lower than mem_wide !


int main()
{
    

	bool RAM[8192] = {};
	std::vector <bool> HDD;

	operating_system* os = new operating_system;
	mmu MMU(os, offset, mem_wide);

    return 0;
}