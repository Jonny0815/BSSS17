#pragma once

#include <math.h>
#include <vector>
#include "process.h"

// ---------------------- Settings ----------------------------------

const int mem_wide = 16;
const int offset = 10; // keep lower than mem_wide !
const int number_of_processes = 8; // number of processes here
const int max_cpu_op = 100; // number of operations performed by the processor

// ----------------------------------------------------------------------


bool RAM[8192] = {};
std::vector <bool> HDD;
process* active_process;
int read_operations = 0;
int write_operations = 0;
int process_change_operations = 0;

//finger off those below !

const int offset_pow = pow(2, offset);
const int frames = 8192 / offset_pow; // sync with RAM size