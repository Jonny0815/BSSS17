#include "operating_system.h"



operating_system::operating_system(ram* RAM_h)
{

	HDD = new hdd;
	RAM = RAM_h;

}


operating_system::~operating_system()
{

	delete HDD;

}
