/*
 * A generic comparable object
 * that holds a string pointer
 * and can compare the string
 * with other Item object
 * strings.
 */

#include "item.h"

Item::Item(std::string *str) {
	data = str;
}

int Item::compare(Comparable *item) {
	if(data == NULL)
		return -1;
	return data->compare(*(((Item *)item)->getData()));
}

void Item::setData(std::string *str) {
	data = str;
}

std::string *Item::getData() {
	return data;
}

