#pragma once

#include "page.h"

#include <vector>

class page_table
{
public:
	page_table(int);
	~page_table();


	std::vector<page*> pages;


};

