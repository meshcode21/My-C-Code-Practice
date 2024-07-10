// random number generator using linear congruence method...
#include<stdio.h>

int main(){
	int x0 = 37, a = 51, c = 29, m = 100;
	int randomNumber[50], n ,i;
	
	printf("Enter no. of random numbers: ");
	scanf("%d",&n);
	
	randomNumber[0] = x0;
	
	for(i = 1;i < n; i++)
		randomNumber[i] = ((randomNumber[i-1] * a) + c) % m;
	
	printf("\n%d Random Numbers are:\n",n);
	for(i = 1;i <= n; i++){
		printf("	%d",randomNumber[i-1]);
		if(i%5==0) printf("\n");
	}
	
	return 0;
}
