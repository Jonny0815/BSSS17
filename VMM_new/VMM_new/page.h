#pragma once

#include "frame.h"

class page
{
public:
	page();
	~page();

	bool mod = false;
	bool ref = false;
	bool prot = false;
	bool pres = false;
	int frame_number = -1;
	int page_number = -1;
	

};

