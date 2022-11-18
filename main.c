#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
 

	printf("===================================\n");
	printf("###################################\n");
	printf("        !BINGO GAME START!         \n");
	printf("###################################\n");
	printf("===================================\n\n\n");
	//opening
	 
	 bingo_init();
	 bingo_printBoard();
	 bingo_inputNum(21);
	 bingo_print(;)
	 
	//game 
	//initialize bingo board 
	  
	 /* 
	 while(game is not over)//줄수가 N_BINGO보다 작음 
	 {
	   //bingo board print
	   //print no. of completed lines
	   //select a proper number
	   //update the board status
	 }
	 
	 */
	 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("===================================\n");
	printf("###################################\n");
	printf("       !!! CONGRATULATION !!!      \n");
	printf("          !!! YOU WIN !!!          \n");
    printf("###################################\n");
	printf("===================================\n");
	//ending
	return 0;
}
