#include "hdd.h"



hdd::hdd()
{
}


hdd::~hdd()
{
	for (size_t i = 0; i < bytes.size(); i++)
	{
		delete bytes.at(i);
	}
}
