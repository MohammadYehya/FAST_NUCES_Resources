#!/bin/bash
export OMP_NUM_THREADS=1
gcc K213309_Lab04Ex2.c -o T -fopenmp
./T
