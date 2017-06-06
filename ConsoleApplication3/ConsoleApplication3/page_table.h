#pragma once

#include "common.h"

class page_table
{
private:

	

public:
	page_table();
	~page_table();

	int* number;
	bool* present;
	bool* refered;
	bool* modified;
	bool* protect;

};

