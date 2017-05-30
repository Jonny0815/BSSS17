#include "manager.h"



manager::manager()
{
}


manager::~manager()
{
}


void manager::manage() {

	while (Users.size() != 0)
	{
		user *User_h = Users.front();

		Users.pop_front();

		if (dynamic_cast<reader*>(User_h) != 0)
		{
			User_h->mtx.unlock();


		}

		if (dynamic_cast<writer*>(User_h) != 0)
		{
			if (num_rdr == 0)
			{
				User_h->mtx.unlock();
			}
			else {

				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "Waiting for all readers to finish so writer can start" << std::endl;

			}

		}


		if (User_h->finished == false)
		{
			Users.push_back(User_h);
		}

	}


}