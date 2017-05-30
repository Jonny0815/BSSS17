#pragma once
#include <iostream>			// for std::cin, cerr, cout ...
#include <thread>			// for std::this_thread
#include <chrono>			// for std::chrono... 
#include <mutex>
#include "common.h"
#include "database.h"


class user {

public:
	user();
	~user();

	std::mutex mtx;
	bool finished = false;

	virtual void write(int, int);
	virtual void read(int, int);
	std::thread go(int, int);

};

class writer : public user {

public:
	writer();
	~writer();



	void write(int, int);
	std::thread go(int, int);

};


class reader : public user {

public:
	reader();
	~reader();



	void read(int, int);

};

// The writer thread
//void writer( int writerID, int numSeconds );

// The reader thread
//void reader( int readerID, int numSeconds );

