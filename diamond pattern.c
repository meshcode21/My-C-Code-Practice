#include<stdio.h>
#include<conio.h>

void main(){
	int sp, st , row;
	int i,j,k;
	
	for(row=1;row<=10;row++){
		for(sp=20;sp>=row*2-1;sp--){
			printf(" ");
		}
		for(st=1;st<=row*2-1;st++){
			printf("* ");
		}
		printf("\n");
	}
	for(row=9;row>=1;row--){
		printf("  ");
		for(sp=18;sp>=row*2-1;sp--){
			printf(" ");
		}
		for(st=1;st<=row*2-1;st++){
			printf("* ");
		}
		printf("\n");
	}
	
	for(i=1;i<=4;i++){
		for(j=3;j>i;j--)
			printf()
	}
	getch();
}
