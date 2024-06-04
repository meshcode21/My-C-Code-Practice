#include<stdio.h>

int fib(int n){
	int f1 = 0, f2 = 1;
//	int fn,i;
	
	if(n==0) return 0;
	else if(n==1) return f1;
	else if(n==2) return f2;
	else{
//		for(i=3; i<=n; i++){
//			fn = f1 + f2;
//			f1 = f2;
//			f2 = fn;
//		}
		return fib(n-1) + fib(n-2);
	}
}

int isPrime(int n){
	int i;
	
	if(n<=1) return -1;
	else {
		for(i=2;i<=n/2;i++){
			if(n%i==0) return 0;
		}
		return 1;
	}
}

void main(){
	int n,i;
	int nth_fib;
	
	printf("Enter the nth term of fibonacci series: "); scanf("%d",&n);
	
	nth_fib = fib(n);
	printf("\nThe nth term of fibonacci series is: %d\n",nth_fib);
	
	printf("\nThe series is:\n");
	for(i=1;i<=n;i++)
		printf(" %d",fib(i));
//	printf("\n==================================\n");	
	
	if(isPrime(nth_fib) == 1) printf("\n\nThe %d is prime.",nth_fib);
	else printf("\n\nThe number %d is not prime.",nth_fib);
}
