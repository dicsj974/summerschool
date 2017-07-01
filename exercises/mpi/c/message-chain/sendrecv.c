#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;
	int source, destination;
	int count;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++){
        message[i] = myid;
    }
    /* Start measuring the time spend in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();
	if (myid < ntasks -1){
		destination = myid +1;
	}
	else{
		destination = MPI_PROC_NULL;
	}
	if (myid > 0)
		source = myid-1;
       else{
               source = MPI_PROC_NULL;
        }
	
	
    /* TODO start */
    /* Send and receive messages as defined in exercise */
	MPI_Sendrecv(message, size, MPI_INT, destination, myid+1, receiveBuffer, size, MPI_INT, myid-1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
	printf("Sender: %d. Sent elements: %d. Tag: %d. Reciever: %d\n",
		 myid, size, myid+1, destination);
	
	MPI_Get_count(&status, MPI_INT, &count);
	printf("Reciever: %d. Recieved elements: %d. tag %d. Sender: %d\n",
		myid, count, status.MPI_TAG, status.MPI_SOURCE);
//        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n", myid, size, source, myid + 1);
//        printf("Receiver: %d. first element %d.\n", myid, receiveBuffer[0]);
    

/*    if (myid > 0) {
	MPI_Recv(receiveBuffer, size, MPI_INT, myid-1, myid, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Receiver: %d. first element %d.\n", myid, receiveBuffer[0]);
    }

     TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}

//      cc -o hello message-chain.c
//      aprun -n 8 ./message-chain
