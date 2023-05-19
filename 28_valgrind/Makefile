CFLAGS=-g -std=c++11
LDFLAGS=-lpthread -lrt 

main:main.o
	g++ -o main main.o $(LDFLAGS) 
	
main.o:main.cpp
	g++ $(CFLAGS) -c main.cpp
