#include <stdio.h>
#include <omp.h> // Included omp header - gives omp lib.

int omp_rank;

int main(int argc, char *argv[])
{
int omp_rank;
int nthreads;

#pragma omp parallel private(omp_rank)
    {
	omp_rank = omp_get_thread_num();
#pragma omp single
	nthreads = omp_get_num_threads();

        printf("Hello world by thread ID %d\n", omp_rank);
    }
	printf("There were %i threads in total\n", nthreads);
}

// Compile with cray: cc -h omp hello.c  -o omp
// Compile with gcc: gcc -fopenmp -o hello hello.c
// Run with aprun -n 4 ./omp     where n is number of threads.

// Run with aprun -e OMP_NUM_THREADS=4 -n 1 -d 4 ./omp   or batch script (sisu.sh)
   // man aprun
