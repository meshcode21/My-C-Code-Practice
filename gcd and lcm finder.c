#include<stdio.h>
#include<math.h>

int isprime(int n){
	int i;	
	if(n==2) return 1;	
	for(i=2;i<=n/2;i++){
		if(n%i==0){
			return 0; // if number is not prime...
		}
	}	
	return 1; // if number is prime...
}

int factor_pow(int n,int n_fact_pows[]){
	int prime=2;
	int i=0;
	int power=0;
	int s=0;
	
	while(n!=1){
		if(isprime(prime)){
			if(n%prime==0){
				power++;
				n_fact_pows[i] = power;
				n /= prime;
				s=1;
			} 
			else{
				power = 0; 
				prime++;
				if(s==1){	
					i++;
					n_fact_pows[i] = power;
				}else{
					n_fact_pows[i] = power;
					i++;
				}
			}
		}else{
			prime++;
		}	
	}
	int a;
	for(a=i+1;a<30;a++) n_fact_pows[a]=0;
	
	return i+1;
}

int GCD(int n1,int n2){
	int n1_fact_pows[30] ,n1_fact_len;
	int n2_fact_pows[30] ,n2_fact_len;
	int gcd = 1;
	
	int i=0;
	int p=2;
	
	n1_fact_len = factor_pow(n1,n1_fact_pows);
	n2_fact_len = factor_pow(n2,n2_fact_pows);

	int length = max(n1_fact_len,n2_fact_len);
		
	printf("\nThe factor of first and second num is:\n");
	while(i!=length){
		if(isprime(p)){
			printf(" %d^%d\t %d^%d\n",p,n1_fact_pows[i],p,n2_fact_pows[i]);
			gcd *= pow(p,min(n1_fact_pows[i],n2_fact_pows[i]));
			i++;
		}
		p++;
	}
	return gcd;
}
int min(int n1,int n2){
	return n1<n2?n1:n2;
}
int max(int n1,int n2){
	return n1>n2?n1:n2;
}

void main(){
	int n1,n2;
	int gcd,lcm;
	printf("Enter two integer: ");
	scanf("%d%d",&n1,&n2);
	
	gcd = GCD(n1,n2);
	lcm = n1*n2/gcd;
	printf("\nThe GCD is: %d\nThe LCM is: %d",gcd,lcm);
}
