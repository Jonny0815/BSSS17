#include "operating_system.h"




operating_system::operating_system(ram* RAM_h)
{

	HDD = new hdd;
	RAM = RAM_h;

	pages_removed = 0;

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

	RAM->frames.at(frame_number)->Page = active_process->get_pt()->pages.at(page);

	cout << "___OS___: Loading page " << page << " from process with data_startpoint " << active_process->get_data_start() << " into frame " << frame_number << endl;

	return frame_number;
}




int operating_system::find_free_frame()
{

	for (size_t i = 0; i < number_of_pages; i++)
	{
		if (RAM->frames.at(i)->Page == nullptr)
		{

			cout << "___OS___: found free frame at: " << i << endl;

			return i;
		}
	}


	clear_frame();
	return find_free_frame();

}

void operating_system::clear_frame()
{
	if (replacement_algorythm == 0)
	{

		for (size_t i = 0; i < number_of_pages; i++)
		{

			if (!RAM->frames.at(i)->Page->ref)
			{

				write_back(RAM->frames.at(i)->Page);

				cout << "___OS___: clearing frame " << i << endl;

				RAM->frames.at(i)->Page = nullptr;

				pages_removed++;

				return;

			}
			else {

				RAM->frames.at(i)->Page->ref = false;

				cout << "___OS___: ref of frame " << i << " set to false" << endl;

			}
		}







	}



}

void operating_system::write_back(page * page_rb)
{

	//TODO write ram page back to hdd where it belongs !

	/*int startpoint_hdd = active_process->get_data_start() + (page_rb->page_number * page_size);
	int startpoint_ram = page_rb->frame_number * page_size;

	cout << "___OS___: writing back page " << page_rb->page_number << "from frame " << page_rb->frame_number << " to hdd" << endl;

	for (size_t i = 0; i < page_size; i++)
	{
		HDD->bytes.at(startpoint_hdd + i)->value = RAM->bytes.at(startpoint_ram + i)->value;
	}*/

}
