#ifndef _LinkedList_
#define _LinkedList_

#include "comparable.h"
#include "list.h"
#include <iostream>

class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		void push(Comparable *item);
		void enqueue(Comparable *item);
		Comparable *find(Comparable *item);
		Comparable *get(unsigned int i);
		Comparable *getFirst();
		Comparable *getLast();
		int  getSize();
		void remove(Comparable *item);
		Comparable *pop();
		Comparable *dequeue();
		Comparable *remove(unsigned int i);
		void printLL();
	private:
		List *head;
		unsigned int size;
};

#endif

