#pragma once

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>


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
	int read_acess_violations = 0;
	int write_acess_violations = 0;

public:
	processing_unit();
	~processing_unit();


	int work();

	void report();

};

