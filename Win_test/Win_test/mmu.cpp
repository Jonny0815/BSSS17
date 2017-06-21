#include "mmu.h"



mmu::mmu(ram* RAM_h)
{

	
	RAM = RAM_h;
	OS = new operating_system(RAM);

}


mmu::~mmu()
{

	delete OS;
	
}


void mmu::set_pt(page_table* pt_h) {

	PT = pt_h;

}



int mmu::translate(int adress)
{
	int page = adress / page_size;
	int offset = adress % page_size;

	cout << "___MMU__: trying to translate adress " << adress << endl;

	if (PT->pages.at(page)->pres == true)
	{

		cout << "___MMU__: sucess ! returning adress " << PT->pages.at(page)->frame_number*page_size + offset << endl;

		PT->pages.at(page)->ref = true;
		return PT->pages.at(page)->frame_number*page_size + offset;
	}
	else {

		cout << "___MMU__: page not present, calling OS" << endl;

		PT->pages.at(page)->frame_number = OS->load_page(page);
		PT->pages.at(page)->pres = true;
		return PT->pages.at(page)->frame_number*page_size + offset;

	}

}
