#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks;
//    int size = 100;
    int size = 100000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }
	if (myid == 0){
		MPI_Recv(receiveBuffer, size, MPI_INT, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(message, size, MPI_INT, 1, 1, MPI_COMM_WORLD);
	}else if (myid == 1){
		MPI_Send(message, size, MPI_INT, 0, 2, MPI_COMM_WORLD);
		MPI_Recv(receiveBuffer, size, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	
    /* TODO: */
    /* Send and receive messages as defined in exercise */
    if (myid == 0) {

        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    } else if (myid == 1) {

        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    }


    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}

//      cc -o hello hello.c
//      aprun -n 8 ./hello
