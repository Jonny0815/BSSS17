#include "processing_unit.h"



processing_unit::processing_unit()
{

	RAM = new ram;
	MMU = new mmu(RAM);


	for (int i = 0; i < number_of_processes; i++)
	{
		processes.push_back(new process(MMU->get_os()->get_hdd()));
	}

	switch_process();
}


processing_unit::~processing_unit()
{

	delete RAM;
	delete MMU;

}

int processing_unit::work() {


	
	int command = rand() % 20 + 1;

	if (command < 12)
	{
		if (read(gen_adress()))
		{
			read_operations++;
			return 0;
		}
		else {
			return 1;
		}
	}

	if (command >= 12 && command <= 18)
	{
		if (write(gen_adress())) {

			write_operations++;
			return 0;
		}
		else {
			return 2;
		}
	}

	if (command >= 19)
	{
		if (switch_process()) {

			process_change_operations++;
			return 0;
		}
		else {
			return 3;

		}
	}

	return 0;

}


bool processing_unit::write(int adress)
{
	if (RAM->bytes[MMU->translate(adress)] != active_process->get_stdb())
	{
		cout << "CPU: Seems like the active process is trying to overwrite bytes not matching std_byte, abording" << endl;
		return false;
	}

	RAM->bytes[MMU->translate(adress)] = active_process->get_writeb();


	return true;
}

bool processing_unit::read(int adress)
{
	if (RAM->bytes[MMU->translate(adress)] != active_process->get_stdb())
	{

		cout << "CPU: Seems like the active process is trying to read bytes not matching std_byte, abording" << endl;

		return false;
	}



	return true;
}

bool processing_unit::switch_process()
{
	active_process = processes.at(rand() % number_of_processes);

	MMU->set_pt(active_process->get_pt());

	MMU->get_os()->set_ap(active_process);

	return true;
}

int processing_unit::gen_adress() {

	if (adress_generator_mode == 0)
	{
		int adress = rand() % active_process->get_size()*page_size; //generate random adress

		for (size_t i = 0; i < active_process->used_adr.size(); i++) //make sure it has not been used yet
		{
			if (active_process->used_adr.at(i) == adress)
			{
				return gen_adress();
			}
		}




		return adress;
	}

	if (adress_generator_mode == 1)
	{

		//TODO

		return 0;
	}

	return 0;

}