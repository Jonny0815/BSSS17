#pragma once

#include "page_table.h"
#include "hdd.h"
#include "setitings.h"
#include "byte.h"

#include <random>

class process
{

private:

	page_table* PT;
	int data_startpoint;
	size_t data_size;

	byte* std_byte;
	byte* write_byte;

public:
	process(hdd*);
	~process();
};

