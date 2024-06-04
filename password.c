#include<stdio.h>
#include<conio.h>

int main(){
 	int uctr=0,pctr=0;
	char name[20],pass[20];
	int i = 0;
	char txt;
	char user[] = "mahesh";
	char pd[] = "mahesh123";
	
	printf("Enter username:");
	scanf("%s",name);
	
	printf("Enter password:"); 

	while(txt = getch()){
		 if(txt != 13){
		 	pass[i] = txt;
		 	i++;
		 	printf("*");
		 }
		 else{
			 break;	 	
		 }
	}
	pass[i] = '\0';


    while(name[uctr]==user[uctr])
    {
        if(name[uctr]=='\0'||user[uctr]=='\0')
            break;
        uctr++;
    }
    
    while(pass[pctr] == pd[pctr])
    {
        if(pass[pctr] == '\0' || pd[pctr] == '\0')
            break;
        pctr++;
    }
    
    if(name[uctr]=='\0' && user[uctr]=='\0' && pass[pctr] == '\0' && pd[pctr] == '\0')
        printf("\nLogin successed....");
    else
        printf("\nUnsuccessfull Login....");

}
