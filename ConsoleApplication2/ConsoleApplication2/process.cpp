#include "process.h"



process::process(std::string file,int id_h)
{

	blocked = false;
	id = id_h;
	

	// TODO save commands from file into commands vector

}


process::~process()
{
}

int process::next_command(processor* p_h) {

	if (commands.size() != 0)
	{
		char command; 
		int value_i;
		std::string value_s;
		

		//TODO convert loaded command from commands vector into command and value

		switch (command)
		{
		case 'S': p_h->set(value_i);
			break;
		case 'A': p_h->add(value_i);
			break;
		case 'D': p_h->sub(value_i);
			break;
		case 'R':

			to_exec = value_s;

			return 1;

			break;
		default:
			break;
		}


	}
	else {

		return 0;

	}

}