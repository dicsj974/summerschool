#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status statuses[2];
    MPI_Request requests[2];

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
    t0 = MPI_Wtime();
	
	
    /* TODO start */
    /* Send and receive messages as defined in exercise */
    
    MPI_Irecv(receiveBuffer, size, MPI_INT, source, MPI_ANY_TAG,
        MPI_COMM_WORLD, &requests[0]);
 
    MPI_Isend(message, size, MPI_INT, destination, myid+1,
       MPI_COMM_WORLD, &requests[1]);

    MPI_Waitall(2, requests, statuses);
    MPI_Get_count(&statuses[0], MPI_INT, &count);
    printf("Sender: %d. Sent elements: %d. Tag: %d. Reciever: %d\n",
        myid, size, myid+1, destination);
    printf("Reciever: %d. Recieved elements: %d. tag %d. Sender: %d\n",
	myid, count, statuses[0].MPI_TAG, statuses[0].MPI_SOURCE);


 /*    TODO end */
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
