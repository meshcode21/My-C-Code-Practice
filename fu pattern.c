#include<stdio.h>

void bhuwan(int n,char ch){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++)
			printf("%c",ch);
		printf("\n");
	}
}

int main(){
	int i;
	bhuwan(5,'@');
}

