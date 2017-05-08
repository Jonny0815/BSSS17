
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>



class processor
{

	

public:
	processor();
	~processor();

	void set(int);
	void add(int);
	void sub(int);
	
	int get_pc() { return pc; }
	int get_r1() { return r1; }

	void set_pc(int pc_h) { pc = pc_h; }
	void set_r1(int r1_h) { r1 = r1_h; }

private:
	


	int r1;
	int pc;
	

};

#endif