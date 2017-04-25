SOURCES = main.cpp matrix.cpp matrix.h
CC = g++
FLAGS = -Wall
EXEC = main

all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CC) $(SOURCES) -o $(EXEC) $(FLAGS)

clean:
	rm $(EXEC)
	rm *~
