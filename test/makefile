#!/usr/bin/gmake

.PHONY: all test clean

CXX = g++
LINK = g++

all:
	$(CXX) -c driver.cpp -o driver.o `python3-config --cflags` -I../
	$(LINK) -o driver driver.o -lpython3.10
	./driver

clean:
	rm -f driver.o driver

