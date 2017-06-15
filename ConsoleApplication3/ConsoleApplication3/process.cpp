#include "process.h"



process::process(page_table* pt_h, int number_h, int start_h, int size_h)
{
	pt = pt_h;
	number = number_h;
	data_start = start_h;
	data_size = size_h;
}


process::~process()
{
}

