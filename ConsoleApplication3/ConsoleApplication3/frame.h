#pragma once

#include "process.h"

class frame
{


public:
	frame();
	~frame();



	process* myprocess;
	bool refered;
	bool modified;

};

