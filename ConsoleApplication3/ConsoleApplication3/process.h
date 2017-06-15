#pragma once

#include "page_table.h"

class process
{

private:

	page_table* pt;
	int number;
	int data_start;
	int data_size;

	


public:
	process(page_table*, int, int, int);
	~process();

	

};

