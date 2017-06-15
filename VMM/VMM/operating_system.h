#pragma once

#include "hdd.h"
#include "ram.h"


using namespace std;

class operating_system
{

private:

	hdd* HDD;
	ram* RAM;

public:
	operating_system(ram*);
	~operating_system();

	hdd* get_hdd() { return HDD; }

};

