#ifndef SCHEDULER_H
#define SCHEDULER_H


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
	void user_unblock_oldest(); //user can interfere with scheduling here
	virtual void schedule() = 0; // work function of scheduler, will run automatic or when step is called at main depending on automode true/false
	
	process *create_proc(std::string, int);
	process *get_active_process() { return active_process; }
	processor *get_processor() { return Processor; };

	void set_automode(bool m_h) { automode = m_h; }

protected:

	process* active_process = NULL;
	std::list<process*> blocked_processes;
	std::list<process*> unblocked_processes;
	int process_counter;
	processor *Processor;
	int result;

	bool automode = false;



	void run(process*);
	void run();


	void block(process*);
	void unblock(process*);
	void end(process*);

};

#endif