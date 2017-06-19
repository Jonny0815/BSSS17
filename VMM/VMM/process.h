#pragma once

#include "page_table.h"
#include "hdd.h"
#include "setitings.h"
#include "byte.h"

#include <random>
#include <vector>

class process
{

private:

	page_table* PT;
	int data_startpoint;
	size_t data_size;

	static byte* std_byte;
	static byte* write_byte;

	

public:
	process(hdd*);
	~process();

	size_t get_size() { return data_size; }
	page_table* get_pt() { return PT; }
	byte* get_stdb() { return std_byte; }
	byte* get_writeb() { return write_byte; }
	int get_data_start() { return data_startpoint; }

	std::vector<int> used_adr;
};

