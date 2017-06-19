#pragma once

#include "frame.h"

class page
{
public:
	page();
	~page();

	bool mod;
	bool ref;
	bool prot;
	bool pres;
	int frame_number;
	

};

