all: quicksort parentheses print_all_binary_trees lru_cache swapkthitem revklist clonelist clonelist_constspace mergesort_ll

quicksort: quicksort.cc
	g++ -g -std=c++11 -lm -o quicksort quicksort.cc

parentheses: parentheses.cc
	g++ -g -std=c++11 -lm -o parentheses parentheses.cc

lru_cache: lru_cache.cc
	g++ -g -std=c++11 -lm -o lru_cache lru_cache.cc

swapkthitem: swapkthitem.cc
	g++ -g -std=c++11 -lm -o swapkthitem swapkthitem.cc

revklist: revklist.cc
	g++ -g -std=c++11 -lm -o revklist revklist.cc

clonelist: clonelist.cc
	g++ -g -std=c++11 -lm -o clonelist clonelist.cc

clonelist_constspace: clonelist_constspace.cc
	g++ -g -std=c++11 -lm -o clonelist_constspace clonelist_constspace.cc

mergesort_ll: mergesort_ll.cc
	g++ -g -std=c++11 -lm -o mergesort_ll mergesort_ll.cc
