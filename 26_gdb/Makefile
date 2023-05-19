CFLAGS=-g
LDFLAGS=-lpthread

factorial:factorial.o
	gcc $(LDLAGS)  -o factorial factorial.o
	
factorial.o:factorial.c
	gcc $(CFLAGS) -c factorial.c
