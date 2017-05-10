#include "scheduler.h"



scheduler::scheduler()
{

	process_counter = 0;
	Processor = new processor; //create new processor
	run(create_proc("init",0)); //load init onto processor
	schedule(); //start scheduling
	
}


scheduler::~scheduler()
{
}

process *scheduler::create_proc(std::string file, int parent_id) {

	process_counter++;

	process *new_process = new process(file, process_counter, parent_id);
	
	return new_process;

}

void scheduler::block(process* p_h) {

	p_h->set_blocked(true);
	p_h->set_pc(Processor->get_pc());
	p_h->set_r1(Processor->get_r1());
	blocked_processes.push_back(p_h);
		
}

void scheduler::unblock(process* p_h) {

	p_h->set_blocked(false);
	unblocked_processes.push_back(p_h);

	//TODO remove process from blocked list

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

		Processor->set_pc(p_h->get_pc());
		Processor->set_r1(p_h->get_r1());

		run();

	}

}

void scheduler::run() {

	switch (active_process->next_command(Processor)) //process next command !
	{
	case 1:

		//start new program and save pc and r1

		active_process->set_pc(Processor->get_pc());
		active_process->set_r1(Processor->get_r1());
		active_process->add_succ();
		run(create_proc(active_process->to_exec, active_process->get_id()));

		break;
	case 0:

		std::cout << "Process PID " << active_process->get_id() << " finished succesful after " << active_process->get_succ() << " operations !" << std::endl;

		delete active_process;

		break;

	case 2:

		active_process->add_succ();

		break;

	case 3:

		active_process->set_pc(Processor->get_pc());
		active_process->set_r1(Processor->get_r1());

		//TODO trap !!!

		break;


	case 4:

		std::cout << "Error while processing commands, terminating active process!" << std::endl;

		delete active_process;

		break;
	default:
		break;
	}

}


void scheduler::user_unblock_oldest() {

	if (blocked_processes.size() != 0)
	{
		unblocked_processes.push_back(blocked_processes.front());
		blocked_processes.pop_front();
	}
	else {

		std::cout << "No blocked processs to unblock" << std::endl;

	}


}