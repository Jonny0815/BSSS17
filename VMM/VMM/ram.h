#pragma once

#include "byte.h"
#include "frame.h"
#include "setitings.h"

#include <vector>

class ram
{
public:
	ram();
	~ram();

	byte* bytes[1024];

	std::vector<frame*> frames;

};

