# Variables
Cflags = -Wall 
CO = g++
DIR = $(notdir $(CURDIR))

# Dependencies
bubble_sort.x: bubble_sort.cpp
	$(CO) $(Cflags) -o $@ $^

# Compilation and running
.PHONY: run_bubble clean

uruchom_bubble: bubble_sort.x
	./bubble_sort.x

# Cleaning
clean:                                                     
	rm -f *.o *.dat *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}
