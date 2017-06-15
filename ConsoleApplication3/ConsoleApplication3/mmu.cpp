#include "mmu.h"



mmu::mmu(operating_system* os_h)
{
	os = os_h;

	for (int i = 0; i < frames; i++)
	{

	}
	
}


mmu::~mmu()
{
}


bool mmu::get_los()
{
	return last_operation_sucess;
}

int mmu::translate(int cell) {

	int read_page = cell / offset;
	int read_offset = cell % offset;

	//TODO

	return 0;
}