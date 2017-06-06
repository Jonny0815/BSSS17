#include "page_table.h"



page_table::page_table()
{
	int _number[frames];
	bool _present[frames];
	bool _refered[frames];
	bool _modified[frames];
	bool _protect[frames];
	
	number = _number;
	present = _present;
	refered = _refered;
	modified = _modified;
	protect = _protect;

}


page_table::~page_table()
{
}
