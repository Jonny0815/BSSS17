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

	for (size_t i = 0; i < page_size; i++)
	{
		
		RAM->bytes[frame_number*page_size + i] = HDD->bytes.at(active_process->get_data_start() + i);
	}

	RAM->frames.at(frame_number)->Page->mod = true;
	RAM->frames.at(frame_number)->Page->ref = true;
	RAM->frames.at(frame_number)->Page->pres = true;

	return frame_number;
}




int operating_system::find_free_frame()
{

	for (size_t i = 0; i < number_of_pages; i++)
	{
		if (RAM->frames.at(i)->Page == nullptr)
		{
			return i;
		}
	}


	clear_frame();
	return find_free_frame();

}

void operating_system::clear_frame()
{




}
