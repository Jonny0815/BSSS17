#include "byte.h"



byte::byte()
{
	value = rand() % 256;
}

byte::byte(byte* byte_to_copy) {

	value = byte_to_copy->value;

}

byte::~byte()
{
}

