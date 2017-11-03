all: quicksort

quicksort: quicksort.cc
	g++ -g -std=c++11 -lm -o quicksort quicksort.cc

