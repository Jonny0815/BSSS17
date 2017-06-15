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


public:
	processing_unit();
	~processing_unit();
};

