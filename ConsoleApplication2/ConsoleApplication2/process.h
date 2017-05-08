
#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <list>
#include "processor.h"

class process
{
public:
	process(std::string, int);
	~process();

	void set_blocked(bool a_h) { blocked = a_h; }
	void set_r1(int r1_h) { r1_backup = r1_h; }
	void set_pc(int pc_h) { pc_backup = pc_h; }

	bool get_blocked() { return blocked; }
	int get_r1() { return r1_backup; }
	int get_pc() { return pc_backup; }
	int get_id() { return id; }


	std::string to_exec;
	int next_command(processor*);

private:

	bool blocked;
	std::list<std::string> commands;
	int r1_backup;
	int pc_backup;
	int id;
};

#endif