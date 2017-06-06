#pragma once

#include <vector>

#include "common.h"
#include "process.h"

class operating_system
{


private:

	process* active_process;
	std::vector<process> processes;

	int freeframe();

public:
	operating_system();
	~operating_system();

	void load_page(int);

};

