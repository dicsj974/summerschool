#include <stdio.h>

int main(int argc, char *argv[])
{
   int a, b, c;
   // declare a pointer variable and assign it to address of e.g. a
	//Declaring pointer p to variable a
	int *p;
	a=15;
//Pointers to integer
 /*
	p=&a; 
   // Evaluate expressions using both the original and the pointer variable
   // and investigate the value / value pointed to
	printf("a equals %d \n", a);
	printf("p equals %d \n", p);
	printf("pointer p adress equals %p \n", p);

//	p++;	
	printf("p equals %d \n", p);
	printf("pointer p adress equals %p \n", p);
	*p=150;
	printf("*p changed to 150\n");
	printf("a equals %d \n", a);
	printf("pointer p equals %d \n", *p);
	printf("p equals %d \n", p);
	printf("pointer p adress equals %p \n", p);
 */
//Pointers to doubles
	b=11e23;	
	p=&a;
	printf("b equals %d \n", b);
	printf("p equals %d \n", p);
	

   return 0;
}
