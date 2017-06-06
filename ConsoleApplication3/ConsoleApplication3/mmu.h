#pragma once

#include <vector>
#include <math.h>

#include "operating_system.h"
#include "page_table.h"
#include "common.h"

class mmu
{

private:

	page_table* pt;
	operating_system* os;
	

public:
	mmu(operating_system*,int, int);
	~mmu();

	void set_pt(page_table* pt_h) { pt = pt_h; };

	int translate(int);






};

