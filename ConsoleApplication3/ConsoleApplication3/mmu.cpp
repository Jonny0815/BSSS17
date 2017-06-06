#include "mmu.h"



mmu::mmu(operating_system* os_h, int offset_h, int mem_wide_h)
{
	os = os_h;
	
}


mmu::~mmu()
{
}


int mmu::translate(int cell) {

	int read_page = cell / offset;
	int read_offset = cell % offset;

	for (std::size_t i = 0; i < frames-1; i++) // i = frame
	{
		if (pt->number[i] == read_page) //TODO somethings wrong here !!!
		{
			return i * offset + read_offset;
		}
	}

	os->load_page(cell);
	translate(cell);

}