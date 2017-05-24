#pragma once

#include <mutex>

class user {

public:
	user();
	~user();

	std::mutex mtx;

	virtual void write(int, int);
	virtual void read(int, int);

};

class writer : public user {

public:
	writer();
	~writer();



	void write(int, int);

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

