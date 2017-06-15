#include "mmu.h"



mmu::mmu()
{

	
	RAM = new ram;
	OS = new operating_system(RAM);

}


mmu::~mmu()
{

	delete OS;
	delete RAM;

}


void mmu::set_pt(page_table* pt_h) {

	PT = pt_h;

}