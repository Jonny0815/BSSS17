#include "scheduler_algorythm_1.h"



scheduler_algorythm_1::scheduler_algorythm_1()
{
}


scheduler_algorythm_1::~scheduler_algorythm_1()
{
}

void scheduler_algorythm_1::schedule() {


	do {

		//replace following with fancy scheduling code ... TODO

		

		block(active_process);
		active_process = NULL;
		
		if (blocked_processes.size() != 0)
		{
			unblock(blocked_processes.front());
		}

		if (unblocked_processes.size() != 0)
		{
			run(unblocked_processes.front());
		}
		else {

			active_process = NULL;

		}





		// scheduling ends here

		if (automode == true)
		{
			sleep(1);

			if (active_process == NULL && unblocked_processes.size() == 0 && blocked_processes.size() == 0) //check for remaining processes
			{
				return;
			}

		}

	} while (automode == true); //repeat while in automode, will be executed once while in debug mode

}