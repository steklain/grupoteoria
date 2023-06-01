# !/bin/bash
# gcc -Wall -c bsm.c -std=c99
g++ -Wall -c ProbStdmue.cc
g++ -Wall ProbStdmue.o -lglobes -lgsl -lgslcblas -O3 -o ProbabilityStdmue
./ProbabilityStdmue
rm *.o
