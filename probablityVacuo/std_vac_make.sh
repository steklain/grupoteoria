# !/bin/bash
# gcc -Wall -c bsm.c -std=c99
g++ -Wall -c ProbStdVac.cc
g++ -Wall ProbStdVac.o -lglobes -lgsl -lgslcblas -O3 -o ProbabilityStdVac
./ProbabilityStdVac
rm *.o
