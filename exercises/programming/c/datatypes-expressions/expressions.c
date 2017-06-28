#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare integers, floats, and doubles
	int a=200;
	float b=5.5;
	double c=1000;
	

   // evaluate expressions, e.g. c = a + 2.5 * b
   // and print out results. Try to combine integers, floats
   // and doubles and investigate what happens in type conversions

	printf("integer a is %d \n", a);
        printf("float b is %f \n", b);
	printf("double c is %f \n", c);
	
	a=+b;
	printf("a plus b is %d \n", a);
	
	a=+c;
	printf("a plus c is %d \n", a);
	printf("a plus c is %f \n", a);


   return 0;
}
