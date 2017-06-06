#pragma once

#include "page_table.h"

class process
{

private:

	page_table* pt;

	


public:
	process();
	~process();


	int data_start;
	int data_size;

};

