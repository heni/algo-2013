all: program unittest

unittest: tests.cpp interface.h
	g++ -std=c++0x -O2 -o $@ $< -lboost_unit_test_framework

program: main.cpp interface.h
	g++ -std=c++0x -O2 -o $@ $<

test: unittest
	./unittest

clean:
	rm -f unittest program
