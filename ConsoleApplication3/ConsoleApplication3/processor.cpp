#include "processor.h"



processor::processor(operating_system* os_h, mmu* mmu_h)
{
	os = os_h;
	MMU = mmu_h;
}


processor::~processor()
{
}

int processor::random_adress() {

	return rand() % active_process->data_size;

}

bool processor::work() {

	bool sucess;
	int command = rand() % 20;

	if (command < 12)
	{
		if (sucess = read(random_adress()))
		{
			read_operations++;
		}
	}

	if (command <= 12 && command != 20)
	{
		if (sucess = write(random_adress())) {

			write_operations++;
		}
	}

	if (command == 20)
	{
		if (change_process()) {

			process_change_operations++;

		}
	}

	return sucess;

}

bool processor::read(int adress) {

	int real_adress = MMU->translate(adress);

	bool content = RAM[real_adress];

	std::cout << "Process " << active_process->number << " is reading: virtual adress " << adress << " - real adress " << real_adress << " contains " << content << std::endl;

	return MMU->get_los();
	

}

bool processor::write(int adress)
{

	bool to_write = rand() % 2;

	int real_adress = MMU->translate(adress);

	RAM[real_adress] = to_write;


	std::cout << "Process " << active_process->number << " is writing " << to_write << "to virtual adress " << adress << " - real adress " << real_adress << std::endl;

	return MMU->get_los();
}

bool processor::change_process()
{

	int switch_to = rand() % number_of_processes;

	active_process = os->processes.at(switch_to);

	std::cout << "Switching active process to process  " << switch_to << std::endl;

	return true;
}

