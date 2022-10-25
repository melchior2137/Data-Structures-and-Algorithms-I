# Variables
Cflags = -Wall 
CO = g++
DIR = $(notdir $(CURDIR))

# Dependencies
bubble_sort.x: bubble_sort.cpp
	$(CO) $(Cflags) -o $@ $^

quick_sort.x: quick_sort.cpp
	$(CO) $(Cflags) -o $@ $^


# Compilation and running
.PHONY: run_bubble run_quick clean

run_bubble: bubble_sort.x
	./bubble_sort.x

run_quick: quick_sort.x
	./quick_sort.x

# Cleaning
clean:                                                     
	rm -f *.o *.dat *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}
