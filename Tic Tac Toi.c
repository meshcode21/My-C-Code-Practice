#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void header();
void play_board();
int update(char,int);
int game_engin();

char a[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; // To store X or O ...
char checker[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // To check the number is alread entered of not...
int error = 0;
int times = 0;
char choose;
int player = 1;

main(){

	while(1){
		system("cls");
		
		header();
		play_board();
		
		if(times>=5 && error!=1 && error!=2){
			if(game_engin() == 1){
				printf("\n\t\t\t           Do you want to play again (y/n)");
				if(getch()=='y') restart();
				else return 0;
			}	
		}
		if(times == 9){
			printf("\t\t\t                  !!! Game Draw !!!\n");
			printf("\n\t\t\t           Do you want to play again (y/n)");
				if(getch()=='y') restart();
				else return 0;
		}
		logical_block();
	}
}

void restart(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			a[i][j] = 32;
	}
	for(i=0;i<9;i++){
		checker[i] = ' '; 
	}	
	error = 0;
	times = 0;
	choose;
	player = 1;
	system("cls");
	header();
	play_board();
}
void logical_block(){
	if(player == 1){
			printf("\t\t\t                  Player 1 Turn\n");
		}else {
			printf("\t\t\t                  Player 2 Turn\n");
		}
		
		if(error == 1) printf("\n\t\t\t                !!! Invalid Input !!!\n");
		else if(error == 2) printf("\n\t\t\t                !!! Already Entered !!!\n");
		
		if(update(getch(),player) == 0){
			
			if(player == 1){
				player = 2;
			}else {
				player = 1;
			}
			times++;
		}
}
int game_engin(){
	
	if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O' ||
		a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O' ||
		a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O' ||
		a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O' ||
		a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O' ||
		a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O' ||
		a[2][0]=='O' && a[1][1]=='O' && a[0][2]=='O' ||
		a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O' ){
			printf("\t\t\t              --- Player 1 winner ---\n");
			return 1;
		}
	
	if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X' ||
		a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X' ||
		a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X' ||
		a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X' ||
		a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X' ||
		a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X' ||
		a[2][0]=='X' && a[1][1]=='X' && a[0][2]=='X' ||
		a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X' ){
			printf("\t\t\t              --- Player 2 winner ---\n");
			return 1;
		}
}
void header(){
	printf("\t\t\t             ----- TIC TAC TOE -----             \n\n");
	printf("\t\t\tYou have to use number keys in the following way.\n\n");
	printf("\t\t\t                    7 | 8 | 9  \n");
	printf("\t\t\t                   ---+---+--- \n");
	printf("\t\t\t                    4 | 5 | 6  \n");
	printf("\t\t\t                   ---+---+--- \n");
	printf("\t\t\t                    1 | 2 | 3  \n\n");
	printf("\t\t\t    ========================================\n");
	printf("\t\t\t         Player 1 (O)       Player 2 (X)    \n");
	printf("\t\t\t    ========================================\n\n");
}
void play_board(){
	printf("\t\t\t                    %c | %c | %c  \n",a[2][0],a[2][1],a[2][2]);
	printf("\t\t\t                   ---+---+--- \n");
	printf("\t\t\t                    %c | %c | %c  \n",a[1][0],a[1][1],a[1][2]);
	printf("\t\t\t                   ---+---+--- \n");
	printf("\t\t\t                    %c | %c | %c  \n\n\n",a[0][0],a[0][1],a[0][2]);
}
int update(char choice,int player){
		
	int i;
	for(i = 0; i < times; i++){
		if(checker[i] == choice){
			error = 2;
			break;
		} else error = 0;
	}		
	if(error != 2){
		if(player == 1){
			choose = 'O';
		}else if(player == 2){
			choose = 'X';
		}
		switch(choice){
			case '1': a[0][0] = choose; break;
			case '2': a[0][1] = choose; break;
			case '3': a[0][2] = choose; break;
			case '4': a[1][0] = choose; break;
			case '5': a[1][1] = choose; break;
			case '6': a[1][2] = choose; break;
			case '7': a[2][0] = choose; break;
			case '8': a[2][1] = choose; break;
			case '9': a[2][2] = choose; break;
			default: 
				error = 1;
				return 1;
		}
		checker[times] = choice;
	}else return 1;
	
	return 0; 
}
