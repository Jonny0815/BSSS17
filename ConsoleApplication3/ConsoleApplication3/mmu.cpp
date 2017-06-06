#include "mmu.h"



mmu::mmu(operating_system* os_h, int offset_h, int mem_wide_h)
{
	os = os_h;
	mem_wide = mem_wide_h;
	offset = offset_h;
	frames = pow(2 , mem_wide - offset);
}


mmu::~mmu()
{
}


int mmu::translate(int cell) {

	int read_page = cell / offset;
	int read_offset = cell % offset;

	for (std::size_t i = 0; i < frames-1; i++) // i = frame
	{
		if (pt->table[i] == read_page)
		{
			return i * offset + read_offset;
		}
	}

	os->load_page(cell);
	translate(cell);

}