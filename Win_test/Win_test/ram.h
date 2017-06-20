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

	std::vector<byte*> bytes;

	std::vector<frame*> frames;

};

