#pragma once

#include <vector>

#include "common.h"
#include "process.h"
#include "frame.h"

class operating_system
{


private:

	process* active_process;
	std::vector<process> processes;
	frame* frames;

	int freeframe();

public:
	operating_system();
	~operating_system();

	void load_page(int);

};

