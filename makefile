all: quicksort parentheses

quicksort: quicksort.cc
	g++ -g -std=c++11 -lm -o quicksort quicksort.cc

parentheses: parentheses.cc
	g++ -g -std=c++11 -lm -o parentheses parentheses.cc

