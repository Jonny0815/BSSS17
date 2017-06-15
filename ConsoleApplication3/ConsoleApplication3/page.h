#pragma once


#include "frame.h"

class page
{
public:


	page();
	~page();


	frame* myframe;

	int number;
	bool present;
	bool refered;
	bool modified;
	bool protect;

	


};

