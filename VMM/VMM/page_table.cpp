#include "page_table.h"



page_table::page_table(int amount)
{

	page* tmp = new page;
	tmp->frame_number = 0;
	tmp->mod = false;
	tmp->pres = false;
	tmp->prot = false;
	tmp->ref = false;
	pages.push_back(tmp);

}


page_table::~page_table()
{
	for (int i = 0; i < pages.size(); i++)
	{
		delete pages.at(i);
	}
}
