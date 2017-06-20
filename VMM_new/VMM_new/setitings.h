#pragma once





	//___________SETTINGS____________________________

	static int number_of_processes = 10;
	static int page_size = 64; //pagesize in bytes, only use pow(2,x)
	static int adress_generator_mode = 0; // 0 = random, 1= TODO
	static int replacement_algorythm = 0; // 0 = clock, 1 = TODO

	//_______________________________________________

	static int number_of_pages = 1024 / page_size;

