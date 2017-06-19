#include "mmu.h"



mmu::mmu(ram* RAM_h)
{

	
	RAM = RAM_h;
	OS = new operating_system(RAM);

}


mmu::~mmu()
{

	delete OS;
	
}


void mmu::set_pt(page_table* pt_h) {

	PT = pt_h;

}



int mmu::translate(int adress)
{
	int page = adress / page_size;
	int offset = adress % page_size;

	if (PT->pages.at(page)->pres)
	{
		return PT->pages.at(page)->frame_number*page_size + offset;
	}
	else {

		PT->pages.at(page)->frame_number = OS->load_page(page);
		PT->pages.at(page)->pres = true;
		return PT->pages.at(page)->frame_number*page_size + offset;

	}

}
