CC 	=	g++
CFLAGS 	=	-static -g -Wall -pedantic -W -O2
LIBS	=	-llinkedlist
OBJECT	=	lltest

all: testll

testll:
	$(CC) $(CFLAGS) main.cpp -o $(OBJECT) $(LIBS)

clean:
	rm $(OBJECT)
