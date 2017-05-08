#pragma once

#include "process.h"
#include "processor.h"
#include <list>
#include <string>
#include <iostream>

class scheduler
{


public:
	scheduler();
	~scheduler();
	virtual void unblock() = 0;
	void run(process*);
	void run();
	process *create_proc(std::string);

private:

	process* active_process = NULL;
	std::list<process*> blocked_processes;
	std::list<process*> unblocked_processes;
	int process_counter;
	processor *Processor;
	int result;


	void block(process*);
	void unblock(process*);
	void end(process*);

};

