# !/bin/bash
# gcc -Wall -c bsm.c -std=c99
g++ -Wall -c ProbStdmutau.cc
g++ -Wall ProbStdmutau.o -lglobes -lgsl -lgslcblas -O3 -o ProbabilityStdmutau
./ProbabilityStdmutau
rm *.o
