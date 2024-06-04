#include<stdio.h>
int is_prime(int num){
	int i;
	
	if(num <= 1 ) return 0; //not prime
	else{
		for(i = 2; i<=num/2; i++){
			if(num % i == 0){
			return 0;
			} 
		}
	} 
	return 1;
}

int main(){
	int num;

	FILE *nfile = fopen("number.txt","r");
	FILE *pfile = fopen("prime.txt","w");
		
	if(nfile != NULL || pfile != NULL){
		while(fscanf(nfile,"%d",&num) != EOF){
			if(is_prime(num)){
				fprintf(pfile,"%d\n",num);
				printf("%d\n",num);
			}
		}
	}else{
		printf("Unsuccessful to open file...!!!");
	}
	
	fclose(nfile);
	fclose(pfile);
	return 0;
}
