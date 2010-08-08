#ifndef _LIST_
#define _LIST_

#include "comparable.h"

class List {
	public:
		List();
		List(Comparable *newdata);
		List(Comparable *newdata, List *newnext, List *newprev);
		List(List *newnext, List *newprev);
		Comparable *getData();
		void setData(Comparable *newdata);
		List *getNext();
		void setNext(List *newnext);
		List *getPrev();
		void setPrev(List *newprev);
	private:
		List *next;
		List *prev;
		Comparable *data;
};

#endif

