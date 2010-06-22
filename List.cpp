/*
 * A List oject is a generic node for a
 * Linked List implementation.
 */

/*
 * I am making the assumption that the
 * programmer will delete the old data
 * and next/prev objects if they call
 * the get methods.
 * This is due in part to how linked
 * lists operate when swapping next
 * pointers.
 *
 */

#include "list.h"

List::List() {
	data = 0;
	next = 0;
	prev = 0;
}

List::List(Comparable *newdata) {
	data = newdata;
	next = 0;
	prev = 0;
}

List::List(Comparable *newdata, List *newnext, List *newprev) {
	data = newdata;
	next = newnext;
	prev = newprev;
}

List::List(List *newnext, List *newprev) {
	data = 0;
	next = newnext;
	prev = newprev;
}

Comparable *List::getData() {
	return data;
}

void List::setData(Comparable *newdata) {
	data = newdata;	
}

List *List::getNext() {
	return next;
}

void List::setNext(List *newnext) {
	next = newnext;
}

List *List::getPrev() {
	return prev;
}

void List::setPrev(List *newprev) {
	prev = newprev;
}

