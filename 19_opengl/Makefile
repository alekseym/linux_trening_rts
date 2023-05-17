CC=g++
CFLAGS=-I. -std=c++0x
DEPS =
OBJ = test1.o


#test1.o: %.cpp $(DEPS)
#	$(CC) -c -std=c++0x  -o $@ $< $(CFLAGS) -std=c++0x

test1: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) -lm -lGL -L/usr/X11R6/lib -lGLU -lglut -lGLEW -lXi -lXmu -lglfw


test1.o:test1.cpp $(DEPS)
	$(CC) -c -std=c++0x test1.cpp $(CFLAGS) -std=c++0x
