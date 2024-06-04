	#include<stdio.h>
	#include<stdlib.h>
	
	void prime_compoite(int n){
		int i;
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0){
				printf("\n %d is composite no.",n);	
				exit(0);		
			}
		}
		printf("\n %d is Prime No.",n);
	}
	
	void main(){
		int n;
		printf("enter n:");
		scanf("%d",&n);
		prime_compoite(n);
	}
