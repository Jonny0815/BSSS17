#include "process.h"
#include <fstream>


process::process(std::string file,int id_h, int pid_h)
{

	blocked = false;
	id = id_h;
	parent_id = pid_h;
	
	
	std::ifstream ifs;
	ifs.open(file.c_str(), std::ios::in);

	while (!ifs.eof())
	{
		std::string commandbuffer;
		getline(ifs, commandbuffer);
		commands.push_back(commandbuffer);
	}

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
		

		//TODO seprate commands from commands list into command and value

		switch (command)
		{
		case 'S': p_h->set(value_i);
			return 2;
			break;
		case 'A': p_h->add(value_i);
			return 2;
			break;
		case 'D': p_h->sub(value_i);
			return 2;
			break;
		case 'R':

			to_exec = value_s;

			return 1;

			break;

		case 'B' :

			this->set_blocked(true);

			return 3;

			break;

		default:

			return 4;

			break;
		}


	}
	else {

		return 0;

	}

}