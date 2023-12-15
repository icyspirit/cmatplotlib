#!/usr/bin/gmake

.PHONY: all test clean

CXX = g++
LINK = g++

all:
	$(CXX) -c driver.cpp -std=c++17 -o driver.o -fPIE `python3-config --cflags` -I../
	$(LINK) -o driver driver.o -lpython3.8
	./driver

clean:
	rm -f driver.o driver

