#include<stdio.h>
int main(){
	int a,b;
	
	printf("Enter A:");
	scanf("%d",&a);
	printf("Enter B:");
	scanf("%d",&b);
	
	a =a-b;
	b = a+b;
	a = b-a;
	
	printf("\na = %d\nb = %d",a,b);
}
