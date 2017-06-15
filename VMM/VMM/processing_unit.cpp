#include "processing_unit.h"



processing_unit::processing_unit()
{

	MMU = new mmu;


	for (int i = 0; i < number_of_processes; i++)
	{
		processes.push_back(new process(MMU->get_os()->get_hdd()));
	}

}


processing_unit::~processing_unit()
{

	delete MMU;

}
