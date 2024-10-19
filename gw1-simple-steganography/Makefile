CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = steganography

all:    class

class:	steganography.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) steganography.o main.o

steganography.o:	steganography.cpp steganography.h
	$(CC) $(CFLAGS) -c steganography.cpp

main.o:	main.cpp steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
