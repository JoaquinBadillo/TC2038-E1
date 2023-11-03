CXX=g++
CXXFLAGS=-std=c++17

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $<