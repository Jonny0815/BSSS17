#include "operating_system.h"



operating_system::operating_system()
{

	frames = new frame[frames_count];

}


operating_system::~operating_system()
{

	delete frames;

}


void operating_system::load_page(int cell) {

	int page = cell / offset;
	
	int load_startpoint = freeframe();

	int data_startpoint = active_process->data_start;

	for (int i = load_startpoint; i < load_startpoint+offset_pow; i++)
	{
		RAM[i] = HDD[data_startpoint];

		data_startpoint++;
	}



}

int operating_system::freeframe() {






}