/* Patrick Jennings
 *
 * A linked list implementation.
 *
 * This implementation uses List objects
 * in order to create a circular doubly
 * linked list.
*/

#include "linkedlist.h"

#define FIRST 0U

/*
 * Constructor. Inits the head pointer to
 * NULL and the size of the linked list
 * to 0.
*/
LinkedList::LinkedList() {
	head = 0;
	size = 0;
}

LinkedList::~LinkedList() {
	while(size)
		pop();
}

/*
 * Puts the item into the beginning of the
 * linked list.
*/
void LinkedList::push(Comparable *item) {
	List *newhead;
	if(head) {
		List *last = head->getPrev();
		newhead = new List(item, head, last);
		last->setNext(newhead);
		head->setPrev(newhead);
	}
	else {
		newhead = new List(item);
		newhead->setNext(newhead);
		newhead->setPrev(newhead);
	}
	head = newhead;
	size++;
}

/*
 * Puts the item into the end of the linked
 * list.
*/
void LinkedList::enqueue(Comparable *item) {
	List *newlast;
	if(head) {
		List *last = head->getPrev();
		newlast = new List(item, head, last);
		last->setNext(newlast);
		head->setPrev(newlast);
	}
	else {
		newlast = new List(item);
		newlast->setNext(newlast);
		newlast->setPrev(newlast);
		head = newlast;
	}
	size++;
}

/*
 * Finds the specified item in the linked
 * list. Returns NULL if not present.
*/
Comparable *LinkedList::find(Comparable *item) {
	List *temp = head;
	if(!item)
		return 0;
	for(unsigned int i = 0; i < size; i++) {
		if(item->compare(temp->getData()) == 0)
			return temp->getData();
		temp = temp->getNext();
	}
	return 0;
}

/*
 * Gets the ith list in the linked list.
*/
Comparable *LinkedList::get(unsigned int index) {
	List *temp = head;
	if(index >= size)
		return 0;
	for(unsigned int i = 0; i < index; i++)
		temp = temp->getNext();
	return temp->getData();
}

/*
 * Returns the head of the linked list.
*/
Comparable *LinkedList::getFirst() {
	return head->getData();
}

/*
 * Returns the tail of the linked list.
*/
Comparable *LinkedList::getLast() {
	return head->getPrev()->getData();
}

/*
 * Returns the number of items inside of
 * the linked list.
*/
int LinkedList::getSize() {
	return size;
}

/*
 * Removes the first item of the list.
*/
Comparable *LinkedList::pop() {
	return remove(FIRST);
}

/*
 * Removes the next (first) item in
 * the list.
*/
Comparable *LinkedList::dequeue() {
	return remove(FIRST);
}

/*
 * Removes the ith item in the list.
 * The index must be a valid integer
 * representing the index of the item
 * to be removed.
*/
Comparable *LinkedList::remove(unsigned int index) {
	List *temp = head;
	if(index >= size || size == 0)
		return 0;
	for(unsigned int i = 0; i < index; i++)
		temp = temp->getNext();
	List *first = temp;
        List *last = first->getPrev();
        List *next = first->getNext();
        Comparable *ret = first->getData();
        last->setNext(next);
        next->setPrev(last);
        delete first;
        size--;
        if(size)
                head = next;
        return ret;
}

/*
 * Prints the addresses of the pointers
 * of each item in the list. This can
 * be used for debugging.
*/
void LinkedList::printLL() {
	List *temp = head;
	std::cout << "==Linked List: " << temp <<  "==\n";
	
	for(unsigned int i = 0; i < size; i++) {
		std::cout << temp << "\n";
		std::cout << "\tNext: " << temp->getNext() << "\n";
		std::cout << "\tPrev: " << temp->getPrev() << "\n";
		std::cout << "\tData: " << temp->getData() << "\n";
		temp = temp->getNext();
	}
}

void liblinkedlist() {}

