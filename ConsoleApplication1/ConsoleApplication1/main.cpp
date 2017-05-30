#include <iostream>		// for std::cout, cin, etc.
#include <thread>		// for std::thread
#include <cassert>		// for assert()
#include <cstdlib>		// for atoi()
#include <vector>       // for std::vector
#include <list>
#include <algorithm>

#include "manager.h"
#include "common.h"
#include "database.h"
#include "reader-writer-threads.h"

const int maxThreads = 1024;



/********************************************* * main entry point *********************************************/
int main(int argc, char *argv[])
{

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0]
			<< " numSeconds numReaders numWriters" << std::endl;
		return(1);
	}

	int numSeconds = atoi(argv[1]);
	assert((0 < numSeconds) && (numSeconds < (60 * 60 * 24))); // max 1 day
	int numReaders = atoi(argv[2]);
	assert((0 <= numReaders) && (numReaders < maxThreads));
	int numWriters = atoi(argv[3]);
	assert((0 <= numWriters) && (numWriters < maxThreads));

	std::vector< std::thread > rThread(numReaders);
	std::vector< std::thread > wThread(numWriters);

	

	std::cout << "In " << argv[0]
		<< ", seconds = " << numSeconds
		<< ", writers = " << numWriters
		<< ", readers = " << numReaders
		<< ", ready to go..." << std::endl;


	manager Manager;

	// create writer threads
	for (int w = 0; w < numWriters; w++) {
		user *User = new writer;
		wThread[w] = User->go(w, numSeconds); //neither working
		
		Manager.Users.push_back(User);
	}

	// create reader threads
	for (int r = 0; r < numReaders; r++) {
		user *User = new reader;
		rThread[r] = std::thread(User->read, r, numSeconds);
		
		Manager.Users.push_back(User);
	}

	

	std::thread mThread = std::thread(Manager.manage);

	std::random_shuffle(Manager.Users.begin(), Manager.Users.end());

	std::cout << "Finished creating all threads..." << std::endl;

	// wait for writers and readers to finish...
	for (std::thread& t : wThread)
		t.join();
	for (std::thread& t : rThread)
		t.join();

	mThread.join();

	theDatabase.printStatistics();
	std::cout << "Simulation finished! Database is "
		<< (theDatabase.ok() ? "OK!" : "NOT OK!!!")
		<< std::endl;

	return(0);
}

