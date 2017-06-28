#include <stdio.h>
#include <stdlib.h>

//define NX 258
//int NX=258; ?
//define NY 258


int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
	double array[258][258];
//#error Define the array

    // Initialize first the zeros
//error Initialize the zeros for interior
for (i=0; i<258; i++)
	for (j=0;j<258; j++)
		array[i][j]=0;

    // Initial conditions for left and right
	

	//Left
//for (i=0; i<258; i++)
	// Right
	// Top
	// Bottom

    // and top and bottom boundaries
//error add boundary conditions for top and bottom
for (i=0; i<258; i++){
	printf("\n");
	for (j=0;j<258; j++)
		printf("%f ", array[i][j]);
}
    return 0;
}
