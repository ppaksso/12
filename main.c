#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h" 
#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED  0
#define N_LINE 2
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void)
{
	int selNum=0;
	do
	{
		printf("select a number");
		scanf("%d",&selNum);
		fflush(stdin);
		
		if (selNum < 1 || selNum > N_SIZE*N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)//함수에 입력되는게 -2,-1이 되면 안되니까 그걸 방지하기 위해서 
		{
			printf("%i is not on the board! select other one\n",selNum);
		}
	} 
   	while(selNum < 1 || selNum > N_SIZE*N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT);
    	
  	     return selNum;
  	  }
	
	int check_gameEnd(void)
	{
		int res= BINGO_RES_UNFINISHED;
		if (bingo_countCompletedLine()>= N_LINE) //N_LINE=2
		{
			res= BINGO_RES_FINISHED;
		 } 
		return res;
		
	}
int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
    int selNum;

	printf("===================================\n");
	printf("###################################\n");
	printf("        !BINGO GAME START!         \n");
	printf("###################################\n");
	printf("===================================\n\n\n");
	//opening
	 
	 bingo_init();
	 
	 while (check_gameEnd()== BINGO_RES_UNFINISHED)
	 {
	 	//bingo board print
	 	bingo_printBoard();
		//print no.of completed line
		printf("No. of completed line : %i\n",bingo_countCompletedLine());
		// select a number
		selNum = get_number();
		//update the board status
		 bingo_inputNum(selNum);
		 
	
	 }


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
