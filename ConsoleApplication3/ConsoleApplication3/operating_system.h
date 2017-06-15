#pragma once

//#include <vector>
//
//#include "common.h"
//#include "process.h"
//#include "mmu.h"

class operating_system
{


private:

	
	//mmu* mymmu;
	int freeframe();

public:
	operating_system();
	~operating_system();

	void load_page(int);
	//std::vector<process*> processes;

};

