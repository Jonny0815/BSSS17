#include "scheduler.h"



scheduler::scheduler()
{

	process_counter = 0;
	Processor = new processor;
	run(create_proc("init"));
	
}


scheduler::~scheduler()
{
}

process *scheduler::create_proc(std::string file) {

	process *new_process = new process(file, process_counter);
	process_counter++;
	return new_process;

}

void scheduler::block(process* p_h) {

	p_h->set_blocked(true);
	p_h->set_pc(Processor->get_pc());
	p_h->set_r1(Processor->get_r1());
		
}

void scheduler::unblock(process* p_h) {

	p_h->set_blocked(false);

}

void scheduler::end(process* p_h) {

	delete p_h;

}

void scheduler::run(process *p_h) {

	if (active_process == p_h)
	{
		run();
	}
	else {

		active_process = p_h;

		run();

	}

}

void scheduler::run() {

	switch (active_process->next_command(Processor))
	{
	case 1:

		//TODO start to_exec from current active_proc and save pc and r1

		break;
	case 0:

		std::cout << "Process PID " << active_process->get_id() << " finished succesful!" << std::endl;

		break;
	default:
		break;
	}

}