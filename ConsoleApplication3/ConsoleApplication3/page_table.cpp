#include "page_table.h"



page_table::page_table()
{
	int _number[frames_count];
	bool _present[frames_count];
	bool _refered[frames_count];
	bool _modified[frames_count];
	bool _protect[frames_count];
	
	number = _number;
	present = _present;
	refered = _refered;
	modified = _modified;
	protect = _protect;

}


page_table::~page_table()
{
}
