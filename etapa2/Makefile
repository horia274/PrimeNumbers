CC = g++
CFLAGS = -Wall -Wextra -O2

build: algo1.o algo2.o main.o
	$(CC) $(CFLAGS) algo1.o algo2.o main.o -o main

run_tests: build
	./main

algo1.o: algo1.cpp
	$(CC) $(CFLAGS) -c algo1.cpp

algo2.o: algo2.cpp
	$(CC) $(CFLAGS) -c algo2.cpp

main.o: main.cpp
	$(CC) $(CFALGS) -c main.cpp

.PHONY: clean
clean:
	rm -rf *.o main
