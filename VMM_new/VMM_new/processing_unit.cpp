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

	cout << "___CPU__: Command = " << command << endl;

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
	if (RAM->bytes[MMU->translate(adress)]->value != active_process->get_stdb()->value)
	{
		cout << "___CPU__: Seems like the active process is trying to overwrite bytes not matching std_byte, abording" << endl;

		write_acess_violations++;

		return false;
	}
	else {

		cout << "___CPU__: writing to virtual adress " << adress << " successful" << endl;

	}

	RAM->bytes[MMU->translate(adress)] = active_process->get_writeb();


	return true;
}

bool processing_unit::read(int adress)
{
	if (RAM->bytes[MMU->translate(adress)]->value != active_process->get_stdb()->value)
	{

		cout << "___CPU__: Seems like the active process is trying to read bytes not matching std_byte, abording" << endl;

		read_acess_violations++;

		return false;
	}
	else {

		cout << "___CPU__: reading virtual adress " << adress << " successful" << endl;
	}



	return true;
}

bool processing_unit::switch_process()
{
	active_process = processes.at(rand() % number_of_processes);

	MMU->set_pt(active_process->get_pt());

	MMU->get_os()->set_ap(active_process);

	cout << "___OS___: active process changed to process with data_startpoint " << active_process->get_data_start() << endl;

	return true;
}

int processing_unit::gen_adress() {

	if (adress_generator_mode == 0)
	{
		int random_multi = active_process->get_size()*page_size;
		int adress = rand() % random_multi; //generate random adress

		for (size_t i = 0; i < active_process->used_adr.size(); i++) //make sure it has not been used yet
		{
			if (active_process->used_adr.at(i) == adress)
			{
				return gen_adress();
			}
		}


		active_process->used_adr.push_back(adress);

		return adress;
	}

	if (adress_generator_mode == 1)
	{

		//TODO

		return 0;
	}

	return 0;

}






void processing_unit::report() {

	cout << "________________________________________________________________________________" << endl;
	cout << "sucessful write operations: " << write_operations << endl;
	cout << "sucessful read operations : " << read_operations << endl;
	cout << "sucessful process changes : " << process_change_operations << endl<<endl;
	cout << "read acess violations     : " << read_acess_violations << endl;
	cout << "write acess violations    : " << write_acess_violations << endl<<endl;
	cout << "number of pages removed   : " << MMU->get_os()->pages_removed << endl;
	cout << "number of pages loaded   : " << MMU->get_os()->pages_loaded << endl;
	cout << "________________________________________________________________________________" << endl;
}