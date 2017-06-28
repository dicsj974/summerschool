
#include <stdio.h>
int main(int argc, char *argv[]){
void add_one_to_both(int *a, int *b){  // Function to add to both pointers
	(*a)++;
	(*b)++;
}

int a, b;	// Declare variables
a=10;
b=20;

add_one_to_both(&a, &b);  // (Instruction: At this point a==11, b==21)
printf("a is %d and b is %d\n", a, b);

return 0;
}

// compiled with gcc -o add_one_to_both add_one_to_both.c
