#pragma once

#include <vector>

#include "mmu.h"
#include "process.h"
#include "setitings.h"
#include "ram.h"

class processing_unit
{

private:

	ram* RAM;
	mmu* MMU;
	std::vector<process*> processes;
	process* active_process;

	bool write(int);
	bool read(int);
	bool switch_process();
	int gen_adress();


	int read_operations = 0;
	int write_operations = 0;
	int process_change_operations = 0;


public:
	processing_unit();
	~processing_unit();


	int work();

};

