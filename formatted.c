#include <stdio.h>

int main() {
	//initialization using assignment operator
   	int a = 10;
	int b = 3;
	int c= 5;

	printf("\nA=%d \nB=%d\nC=%d \n\n",a,b);
	
	//Arithmetic Operations
	printf("Sum: %d\n", a+b);
	printf("Difference: %d\n", a-b);
	printf("Product: %d\n", a*b);
	printf("Division: %d\n", a/b);
	printf("Remainder: %d\n\n", a%b);
	
	//Relational Operators
	printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n\n", a != b);
    
    
	//Logical Operations
    printf("(a > b) && (b < c): %d\n", (a > b) && (b < c));
    printf("(a > b) || (b < c): %d\n", (a > b) || (b < c));
    printf("!(a > b): %d\n", !(a > b));

   return 0;
}
