#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int rank, nprocesses;

	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &nprocesses); 	// MPI_COMM_WORLD is the communicator
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0){ 	// Print nprocesses if process ID 0
		printf("There are %i processes saying hi\n", nprocesses);
	}	
	MPI_Barrier(MPI_COMM_WORLD); // Make sure nprocesses is printed out first.
   	printf("Hello world! from rank %i\n", rank); //Each process says hi!

   	MPI_Finalize;
}


//	cc -o hello hello.c
//	aprun -n 8 ./hello
//	
