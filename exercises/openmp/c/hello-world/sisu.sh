#!/bin/bash

#SBATCH -t 00:10:00
#SBATCH -N 1
#SBATCH -J omp-test
#SBATCH -p test

export OMP_NUM_THREADS=4

aprun -n 1 -d 4 ./omp
