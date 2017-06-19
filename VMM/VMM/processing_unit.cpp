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

void processing_unit::work() {


	
	int command = rand() % 20;

	if (command < 12)
	{
		if (read(random_adress()))
		{
			read_operations++;
		}
	}

	if (command <= 12 && command != 20)
	{
		if (write(random_adress())) {

			write_operations++;
		}
	}

	if (command == 20)
	{
		if (switch_process()) {

			process_change_operations++;

		}
	}

	

}


bool processing_unit::write(int)
{
	return false;
}

bool processing_unit::read(int)
{
	return false;
}

bool processing_unit::switch_process()
{
	return false;
}

int processing_unit::random_adress() {

	return rand() % active_process->get_size();

}