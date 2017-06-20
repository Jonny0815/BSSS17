#include "process.h"



process::process(hdd* HDD_h)
{

	
	std_byte = new byte;
	write_byte = new byte;

	data_size = rand() % 20 + 1; //amount of sides on hdd
	data_startpoint = HDD_h->bytes.size();


	PT = new page_table(data_size);

	for (int i = 0; i < data_size; i++)
	{
		for (int i = 0; i < page_size; i++)
		{
			HDD_h->bytes.push_back(new byte(std_byte));
		}

	}

}


process::~process()
{

	delete PT;
	delete std_byte;
	delete write_byte;

}
