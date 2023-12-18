#!/usr/bin/gmake

.PHONY: all test clean

CXX = g++
LINK = $(CXX)
CFLAGS = -std=c++17 `python3-config --includes` -I../
LDFLAGS = `python3-config --ldflags --embed`

%.o: %.cpp ../*.hpp
	$(CXX) -o $@ -c $< $(CFLAGS)

all: driver

driver: driver.o
	$(LINK) -o $@ $^ $(LDFLAGS)

run: driver
	./driver

clean:
	rm -f driver.o driver

