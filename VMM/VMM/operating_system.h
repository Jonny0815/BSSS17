#pragma once

#include "hdd.h"
#include "ram.h"
#include "process.h"

#include "setitings.h"

using namespace std;

class operating_system
{

private:

	hdd* HDD;
	ram* RAM;

	process* active_process;

	int find_free_frame();

public:
	operating_system(ram*);
	~operating_system();

	hdd* get_hdd() { return HDD; }
	int load_page(int);
	void set_ap(process* ap_h) { active_process = ap_h; };

};

