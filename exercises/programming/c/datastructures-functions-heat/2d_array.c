#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258


int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
	double array[NX][NY];
//#error Define the array

    // Initialize first the zeros
//error Initialize the zeros for interior
for (i=0; i<NX - 1; i++){
	for (j=0;j<NY - 1; j++){
		array[i][j]=0.0;
	}
}

    // Initial conditions for left and right
for (i=0; i< NX;i++){
	array[i][0] = 20.0;
	array[i][NY-1] = 70.0;
}

	// Initial conditions for top and bottom
for (j=0; j<NY; j++) {
	array[0][j]=85.0;
	array[NX-1][j]=5.0;
}
	// Right
	// Top
	// Bottom

for (i=0; i<NX; i++){
	printf("\n");
	for (j=0;j<NY; j++)
		printf("%f ", array[i][j]);
}
    return 0;
}
