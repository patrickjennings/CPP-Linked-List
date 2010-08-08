#include <linkedlist.h>
#include <item.h>
#include <iostream>

void testQueue() {
	std::string s1("hello");
	std::string s2(", ");
	std::string s3("world");
	LinkedList *ll = new LinkedList();
	Item *i1 = new Item(&s1);
	Item *i2 = new Item(&s2);
	Item *i3 = new Item(&s3);
	ll->enqueue(i1);
	ll->enqueue(i2);
	ll->enqueue(i3);
	Item *r1 = (Item *)ll->dequeue();
	Item *r2 = (Item *)ll->dequeue();
	Item *r3 = (Item *)ll->dequeue();
	std::cout << *r1->getData() << *r2->getData() << *r3->getData() << "\n";
	delete r1;
	delete r2;
	delete r3;
	delete ll;
}

void testStack() {
	std::string s3("Pop ");
	std::string s2("goes the ");
	std::string s1("weasel.");
	LinkedList *ll = new LinkedList();
	Item *i1 = new Item(&s1);
	Item *i2 = new Item(&s2);
	Item *i3 = new Item(&s3);
	ll->push(i1);
	ll->push(i2);
	ll->push(i3);
	Item *r1 = (Item *)ll->pop();
	Item *r2 = (Item *)ll->pop();
	Item *r3 = (Item *)ll->pop();
	std::cout << *r1->getData() << *r2->getData() << *r3->getData() << "\n";
	delete r1;
	delete r2;
	delete r3;
	delete ll;
}

void testFind() {
	std::string s1("Bob");
	std::string s2("Patrick");
	std::string s3("CUDA");
	std::string s4("Junk");
	LinkedList *ll = new LinkedList();
	Item *i1 = new Item(&s1);
	Item *i2 = new Item(&s2);
	Item *i3 = new Item(&s3);
	Item *i4 = new Item(&s4);
	ll->enqueue(i1);
	ll->enqueue(i2);
	ll->enqueue(i3);
	ll->enqueue(i4);
	Item *r1 = (Item *)ll->find(i1);
	if(r1)
		std::cout << "Found!" << "\n";
	else
		std::cout << "Houston, we have a problem." << "\n";
	ll->printLL();
	ll->remove(1);
	ll->printLL();
	delete i1;
	delete i2;
	delete i3;
	delete i4;
	delete ll;
}

int main() {
	testQueue();
	testStack();
	testFind();
}

