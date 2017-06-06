// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{

	int cell = 2857;
	int offset = 1024;

	std::cout << cell / offset << " " << cell % offset << std::endl;

    return 0;
}

