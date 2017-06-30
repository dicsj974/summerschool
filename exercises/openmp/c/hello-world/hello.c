#include <stdio.h>
#include <omp.h> // Included omp header - gives omp lib.

int omp_rank;

int main(int argc, char *argv[])
{
int omp_rank;
#pragma omp parallel private(omp_rank)
    {
	omp_rank = omp_get_thread_num();
        printf("Hello world by thread %d\n", omp_rank);
    }

}

// Compile with cray: cc -h omp hello.c  -o omp
// Run with aprun -n 4 ./omp     where n is number of threads.

// Run with aprun -e OMP_NUM_THREADS=4 -n 1 -d 4 ./omp   or batch script (sisu.sh)
