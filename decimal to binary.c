#include<stdio.h>

int main(){
	int n;
	long int bn;
	int i=1,temp,rem;
	
	printf("Enter the number:"); scanf("%d",&n);
	temp = n;
	
	while(temp!=0){
		rem = temp%2;
		temp = temp/2;
		bn = bn + rem*i;
		i *= 10;
	}

	printf("\nThe binary number of %d is: 00%d",n,bn);
}
