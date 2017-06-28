#include <stdio.h>

int main(int argc, char *argv[])
{
	   int i=12;

   /* Write the control structure as described in the exercise
    and run the code with different values for i
   */
	if (i < 0) {
	printf("i is negative\n");
}	else if (i==0) {
	printf("i is zero\n");
}
	else if (i>100) {
	printf("i is larger than 100\n");
	
}

   return 0;
}
