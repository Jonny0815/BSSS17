#include "page_table.h"



page_table::page_table(int amount)
{

	for (int i = 0; i < amount; i++)
	{
		pages.push_back(new page);
	}

}


page_table::~page_table()
{
	for (int i = 0; i < pages.size(); i++)
	{
		delete pages.at(i);
	}
}
