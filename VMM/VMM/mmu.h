#pragma once


#include "operating_system.h"
#include "ram.h"
#include "page_table.h"

class mmu
{
private:

	operating_system* OS;
	ram* RAM;
	page_table* PT;


public:
	mmu();
	~mmu();

	void set_pt(page_table*);
	operating_system* get_os() { return OS; }
};

