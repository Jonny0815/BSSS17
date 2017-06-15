#pragma once

#include "process.h"
#include "operating_system.h"
#include "mmu.h"
#include <vector>
#include <random>
#include <iostream>

class processor
{

private :

	int random_adress();
	bool read(int);
	bool write(int);
	bool change_process();

	operating_system* os;
	mmu* MMU;

public:
	processor(operating_system*, mmu*);
	~processor();

	bool work();
};

