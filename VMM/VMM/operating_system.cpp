#include "operating_system.h"




operating_system::operating_system(ram* RAM_h)
{

	HDD = new hdd;
	RAM = RAM_h;

}


operating_system::~operating_system()
{

	delete HDD;

}

int operating_system::load_page(int page)
{
	int frame_number = find_free_frame();

	for (size_t i = active_process->get_data_start(); i < active_process->get_data_start()+page_size; i++)
	{
		
		RAM->bytes[frame_number*page_size + i] = HDD->bytes.at(active_process->get_data_start() + i);
	}


	return frame_number;
}




int operating_system::find_free_frame()
{
	return 0;
}
