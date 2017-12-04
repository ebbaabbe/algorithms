all: quicksort paranthesis

quicksort: quicksort.cc
	g++ -g -std=c++11 -lm -o quicksort quicksort.cc

paranthesis: paranthesis.cc
	g++ -g -std=c++11 -lm -o paranthesis paranthesis.cc

