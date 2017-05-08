#include "processor.h"



processor::processor()
{

}


processor::~processor()
{
}


void processor::set(int n) {

	r1 = n;
	pc++;

};

void processor::add(int n) {

	r1 = r1 + n;
	pc++;

};

void processor::sub(int n) {

	r1 = r1 - n;
	pc++;

}



