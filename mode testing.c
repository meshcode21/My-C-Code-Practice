#include<stdio.h>

void main(){
	int n,m;
	int result;
	
	printf("n\"%m\n");
	scanf("%d%d",&n,&m);
	
	result = (n==0)?(m-1):(n-1);
	
	printf("%d",result);
}
