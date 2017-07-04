#include <stdio.h>
#include <mpi.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rank, rc; //rank and rank count
    int required, provided; //Threading variants
    int thrnum;

    // Check support level: 
  // How does this work:?  MPI_CHECK();
    
    MPI_Init_thread(&argc, &argv, required, &provided);
    MPI_Comm_size(MPI_COMM_WORLD, &rc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#pragma omp parallel private(thrnum)
    {
        thrnum=omp_get_thread_num();
        printf("Hello world! from rank %d, thread %d\n,", rank, thrnum);
    }
    MPI_Finalize;
    return 0;
}


//	cc -o hybrid hybrid.c
//	aprun -n 8 -d 8 ./hybrid
//
// cc -h omp hello.c  -o omp
// aprun -e OMP_NUM_THREADS=4 -n 4 -d 4 ./hybrid	
