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
	
	bool last_operation_sucess;
	

public:
	mmu(operating_system*);
	~mmu();

	void set_pt(page_table* pt_h) { pt = pt_h; };
	bool get_los();
	int translate(int);


	//std::vector<frame> frames_vector;



};

