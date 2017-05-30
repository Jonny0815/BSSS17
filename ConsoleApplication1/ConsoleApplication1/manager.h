#pragma once

#include <list>
#include "reader-writer-threads.h"
#include "common.h"
#include <thread>
#include <chrono>

class manager
{
public:
	manager();
	~manager();

	void manage();

	std::list<user*> Users;

	

};

