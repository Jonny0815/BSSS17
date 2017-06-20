#include "byte.h"



byte::byte()
{
	value = rand() % 256;
}

byte::byte(byte* org) {

	value = org->value;

}

byte::byte(int val)
{
	value = val;
}

byte::~byte()
{
}


