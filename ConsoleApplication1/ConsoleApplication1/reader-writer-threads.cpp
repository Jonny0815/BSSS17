#include <iostream>			// for std::cin, cerr, cout ...
#include <thread>			// for std::this_thread
#include <chrono>			// for std::chrono... 
#include <mutex>
#include "database.h"
#include "reader-writer-threads.h"


// ******** reader & writer threads ******** 

// The writer thread

int rc = 0;

std::mutex mtx_enter;
std::mutex mtx_rc;

int writer_wait = 0;

std::chrono::nanoseconds time_writer;

void writer( int writerID, int numSeconds ) {

	std::cout << "Writer " << writerID << " starting..." << std::endl;

	int	tests = 0; 
	
	auto startTime = std::chrono::steady_clock::now();
	std::chrono::seconds maxTime( numSeconds ); 
	while ( ( std::chrono::steady_clock::now() - startTime ) < maxTime ) {
		

		

		mtx_enter.lock();
		
		auto time_start = std::chrono::steady_clock::now();

		while (true)
		{
			mtx_rc.lock();

			if (rc == 0)
			{
				mtx_rc.unlock();
				break;
			}

			mtx_rc.unlock();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(timetowait));
			writer_wait++;
			
		}
		

		bool result = theDatabase.write( writerID );

		auto time_end = std::chrono::steady_clock::now();

		time_writer = time_writer + (time_end - time_start);

		mtx_enter.unlock();

		++tests;

		// sleep a while...
		int numSeconds2sleep = randomInt( 3 ); // i.e. either 0, 1 or 2 
		std::chrono::seconds randomSeconds( numSeconds2sleep );
		std::cout << "WRITER " << writerID 
			      << " Finished test " << tests
			      << ", result = " << result
			      << ", sleeping " << numSeconds2sleep
			      << " seconds " << std::endl;
		if ( numSeconds2sleep ) std::this_thread::sleep_for ( randomSeconds ); 
		
	} // repeat until time used is up
	
	std::cout << "WRITER " << writerID 
		      << "Finished. Returning after " << tests 
		      << " tests." << std::endl;

} // end writer function

// The reader thread
void reader( int readerID, int numSeconds ) {
	
	std::cout << "Reader " << readerID << " starting..." << std::endl;
	
	int	tests=0;
	auto startTime = std::chrono::steady_clock::now();
	std::chrono::seconds maxTime( numSeconds ); 
	while ( ( std::chrono::steady_clock::now() - startTime ) < maxTime ) {


		mtx_enter.lock();
		mtx_rc.lock();
		rc++;
		mtx_rc.unlock();
		mtx_enter.unlock();

		bool result = theDatabase.read( readerID );

		
		mtx_rc.lock();
		rc--;
		mtx_rc.unlock();
		

		++tests;

		// sleep a while...
		int numSeconds2sleep = randomInt( 3 ); // i.e. either 0, 1 or 2 
		std::chrono::seconds randomSeconds( numSeconds2sleep );
		std::cout << "READER " << readerID 
			      << " Finished test " << tests
			      << ", result = " << result
			      << ", sleeping " << numSeconds2sleep
			      << " seconds " << std::endl;
		if ( numSeconds2sleep ) std::this_thread::sleep_for ( randomSeconds ); 

	} // repeat until time is used up
	
	std::cout << "READER " << readerID 
		      << "Finished. Returning after " << tests 
		      << " tests." << std::endl;

} // end reader function


void waittime() {

	std::cout << "Overall waiting time writer = " << writer_wait << std::endl;
	std::cout << "Time writer = " << time_writer.count() << std::endl;

}