#!/bin/bash
#gcc -Wall -c bsm.c -std=c99
g++ -Wall -c ProbStdmumu.cc
#g++ -Wall ProbStd.o bsm.o -lglobes -lgsl -lgslcblas -O3 -o ProbabilityStd
./ProbabilityStd 
rm *.o
