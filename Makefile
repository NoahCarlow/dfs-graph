EXEC = assignment8
CPP = g++
CFLAGS = -c -Wall

$(EXEC) : Assignment8.o Graph.o LinkedList.o
	$(CPP) -o $(EXEC) Assignment8.o Graph.o LinkedList.o

Assignment7.o : Assignment8.cpp
	$(CPP) $(CFLAGS) Assignment8.cpp

Graph.o : Graph.h Graph.cpp
	$(CPP) $(CFLAGS) Graph.cpp

LinkedList.o : LinkedList.h LinkedList.cpp
	$(CPP) $(CFLAGS) LinkedList.cpp

clean :
	rm *.o