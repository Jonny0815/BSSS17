#pragma once

#include "common.h"
#include "page.h"
#include <vector>

class page_table
{
private:

	

public:
	page_table();
	~page_table();

	std::vector<page> pages;

};

