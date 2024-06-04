#include<stdio.h>

int factor(int num[],int n){
	int count = 0;
	int a=2;
	int i =0;
	
	if(n==1 || n==2){
		num[count] = n;
		count++;
	} 
	else {
		while(n!=1){
			if(n%a==0){
				num[i] = a;
				n /= a;
				count++;
				i++;
			} 
			else a++;
		}
	}
	return count-1;
}

void main(){
	int n1,n2,lcm=1,hcf=1;
	int n1f[10],n2f[10],common[10];
	int l1,l2;
	int i,j,k,s=0,c=0;
	int skiper[10];
	
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	
	l1 = factor(n1f,n1);
	l2 = factor(n2f,n2);
	
	printf("\nThe factor of 1st number: ");
	for(i=0;i<=l1;i++)
		printf("%d ",n1f[i]);
	printf("\nThe factor of 2nd number: ");
	for(i=0;i<=l2;i++)
		printf("%d ",n2f[i]);
		
//	finding common elements...
	for(i=0;i<=l1;i++){
		for(j=0;j<=l2;j++){
			if(n1f[i]==n2f[j]){
				s=0;
				for(k=0;k<c;k++){
					if(j==skiper[k]){
						s=1;
					}
				}
				if(s==0){
					common[c] = n1f[i];
						skiper[c] = j;
						c++;
						break;
				}
			}
		}
	}
	
	printf("\n\nCommon elements are: ");
	for(i=0;i<c;i++){
		printf("%d ",common[i]);
		hcf *= common[i];
	} 
	printf("\nThe HCF is: %d",hcf);
	lcm = (n1*n2)/hcf;
	printf("\nThe LCM is: %d",lcm);

}
