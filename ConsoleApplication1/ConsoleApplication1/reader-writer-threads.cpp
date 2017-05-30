
#include "reader-writer-threads.h"

// ******** reader & writer threads ******** 




// The writer thread


writer::writer() {

	mtx.lock();

}


	void writer::write(int writerID, int numSeconds) {

		std::cout << "Writer " << writerID << " starting..." << std::endl;

		int	tests = 0;
		auto startTime = std::chrono::steady_clock::now();
		std::chrono::seconds maxTime(numSeconds);
		while ((std::chrono::steady_clock::now() - startTime) < maxTime) {

			mtx.lock();

			writing.lock();

			bool result = theDatabase.write(writerID);

			writing.unlock();


			++tests;

			// sleep a while...
			int numSeconds2sleep = randomInt(3); // i.e. either 0, 1 or 2 
			std::chrono::seconds randomSeconds(numSeconds2sleep);
			std::cout << "WRITER " << writerID
				<< " Finished test " << tests
				<< ", result = " << result
				<< ", sleeping " << numSeconds2sleep
				<< " seconds " << std::endl;
			if (numSeconds2sleep) std::this_thread::sleep_for(randomSeconds);

		} // repeat until time used is up

		std::cout << "WRITER " << writerID
			<< "Finished. Returning after " << tests
			<< " tests." << std::endl;

		finished = true;

	} // end writer function



// The reader thread



	reader::reader() {

		mtx.lock();

	}


	void reader::read(int readerID, int numSeconds) {

		std::cout << "Reader " << readerID << " starting..." << std::endl;

		int	tests = 0;
		auto startTime = std::chrono::steady_clock::now();
		std::chrono::seconds maxTime(numSeconds);
		while ((std::chrono::steady_clock::now() - startTime) < maxTime) {

			mtx.lock();



			num_rdr_mtx.lock();
			num_rdr = num_rdr + 1;
			num_rdr_mtx.unlock();

			bool result = theDatabase.read(readerID);


			num_rdr_mtx.lock();
			num_rdr = num_rdr -1;
			num_rdr_mtx.unlock();
			
			++tests;

			// sleep a while...
			int numSeconds2sleep = randomInt(3); // i.e. either 0, 1 or 2 
			std::chrono::seconds randomSeconds(numSeconds2sleep);
			std::cout << "READER " << readerID
				<< " Finished test " << tests
				<< ", result = " << result
				<< ", sleeping " << numSeconds2sleep
				<< " seconds " << std::endl;
			if (numSeconds2sleep) std::this_thread::sleep_for(randomSeconds);

		} // repeat until time is used up

		std::cout << "READER " << readerID
			<< "Finished. Returning after " << tests
			<< " tests." << std::endl;


		finished = true;

	} // end reader function




	std::thread writer::go(int w, int numsec) {

		return std::thread(write, w, numsec);

	}