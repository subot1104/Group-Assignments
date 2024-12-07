CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = deque

all:    class

class:	deque.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) deque.o main.o

deque.o:	deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

main.o:	main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
