/*
 * A comparable object is an item
 * that can be compared with similar
 * items.
*/

#ifndef _COMPARABLE_
#define _COMPARABLE_

class Comparable {
	public:
		virtual int compare(Comparable *item) = 0;
};

#endif

