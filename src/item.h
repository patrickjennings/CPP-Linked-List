#ifndef _ITEM_
#define _ITEM_

#include "comparable.h"
#include <string>

class Item : public Comparable {
	public:
		Item(std::string* str);
		int compare(Comparable* item);
		std::string *getData();
		void setData(std::string *str);
	private:
		std::string *data;
};

#endif

