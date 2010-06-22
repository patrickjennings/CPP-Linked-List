CC 	=	g++
CFLAGS 	=	-g -Wall -pedantic -W -O2
LIBFLAGS = 	$(CFLAGS) -fPIC
PROJECT	=	linkedlist
LIBRARY	=	lib$(PROJECT)
MAJOR_VERSION = 0
MINOR_VERSION = 1

all: linkedlist

linkedlist: Item.o LinkedList.o List.o main.o
	$(CC) -o $(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION) \
		-shared -W1,-soname,$(LIBRARY).so.$(MAJOR_VERSION) \
		LinkedList.o List.o
	$(CC) -o $(PROJECT) Item.o LinkedList.o List.o main.o

install:
	cp $(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION) \
		/usr/local/lib
	ln -s /usr/local/lib/$(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION) \
		/usr/local/lib/$(LIBRARY).so
	ln -s /usr/local/lib/$(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION) \
		/usr/local/lib/$(LIBRARY).so.$(MAJOR_VERSION)
	ldconfig

uninstall:
	rm /usr/local/lib/$(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION)
	rm /usr/local/lib/$(LIBRARY).so.$(MAJOR_VERSION)
	rm /usr/local/lib/$(LIBRARY).so
	ldconfig

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Item.o: Item.cpp
	$(CC) $(CFLAGS) -c Item.cpp

LinkedList.o: LinkedList.cpp
	$(CC) $(LIBFLAGS) -c LinkedList.cpp

List.o: List.cpp
	$(CC) $(LIBFLAGS) -c List.cpp

clean:
	rm *.o $(PROJECT) $(LIBRARY).so.$(MAJOR_VERSION).$(MINOR_VERSION)
