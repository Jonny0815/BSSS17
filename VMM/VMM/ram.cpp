#include "ram.h"



ram::ram()
{

	for (size_t i = 0; i < number_of_pages; i++)
	{
		frames.push_back(new frame);
	}

}


ram::~ram()
{
	for (size_t i = 0; i < frames.size(); i++)
	{
		delete frames.at(i);
	}

	for (size_t i = 0; i < 1024; i++)
	{
		delete bytes[i];
	}
}
