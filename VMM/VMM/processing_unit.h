#pragma once

#include <vector>

#include "mmu.h"
#include "process.h"
#include "setitings.h"

class processing_unit
{

private:

	mmu* MMU;
	std::vector<process*> processes;
	process* active_process;

	bool write(int);
	bool read(int);
	bool switch_process();
	int random_adress();


	int read_operations = 0;
	int write_operations = 0;
	int process_change_operations = 0;


public:
	processing_unit();
	~processing_unit();


	void work();

};

