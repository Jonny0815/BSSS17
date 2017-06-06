// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

int main()
{

	int cell = 2857;
	int offset = 1024;

	std::cout << 8192/pow(2,10) << " " << cell % offset << std::endl;

    return 0;
}

