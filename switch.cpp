#include<stdio.h>
#include<stdlib.h>

main(){
	char ch;
	bool a = true;
	AB:
		printf("enter choice:");
	scanf("%c",&ch);

	switch(ch){
		case 'a': printf("\nAAAA"); goto AB ;
		case 'b': printf("\nBBBB"); goto AB ;
		case 'c': printf("\nCCCC"); goto AB ;
		case 'd': exit(0); 
	}	

}
