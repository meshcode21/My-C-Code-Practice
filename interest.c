#include<stdio.h>

main(){
	float p,t,i;
	char g;
	
	printf("Your Gender Please (m/f):");
	scanf("%c",&g);
	printf("\nEnter the Principal:");
	scanf("%f",&p);
	printf("\nTime in Years:");
	scanf("%f",&t);
	
	switch(g){
		case 'f':
			if(t<2.0)
				i = (p*t*5)/100;
			else
				i = (p*t*10)/100;
		break;
		
		case 'm':
			if(t<4.0)
				i = (p*t*5)/100;
			else
				i = (p*t*10)/100;
		break;
	}
	
	printf("\n\nThe Interest is: %.2f",i);
	
	
}
