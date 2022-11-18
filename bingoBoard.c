#include <stdio.h>
#include "bingoBoard.h" 

#define BINGONUM_HOLE 0 //매크로정의 

static int bingoBoard[N_SIZE][N_SIZE];
static int numberstatus[N_SIZE*N_SIZE];//static써서 다른 파일에서 못 넘어오게 

void bingo_init(void)
{
	int i,j;
	int cnt=1;
	
	for(i=0;i<N_SIZE;i++)
	  for(j=0;j<N_SIZE;j++)
	  {
	  	if(cnt == 15)
	  	{
	  	    bingoBoard[i][j] = BINGONUM_HOLE;
	  	   	numberstatus[cnt-1]=BINGONUM_HOLE;
	  	   	
			cnt++;
		}
		else 
		 {
		 	numberstatus[cnt-1]=i*N_SIZE+j;
		 	bingoBoard[i][j]=cnt++;
		 	
		  } 
	  	
	  }
}
void bingo_printBoard(void)
{
	int i,j;
	
	printf("===================================\n");
    for(i=0;i<N_SIZE;i++)
    {
      for(j=0;j<N_SIZE;j++)
        {
        	if (bingoBoard[i][j]== BINGONUM_HOLE)
        	  printf("X\t");
        	else
        	  printf("%i\t",bingoBoard[i][j]);
		}
		printf("\n");
	}
	printf("===================================\n\n");

}

void bingo_inputNum(int sel)
{
	printf("select a number");
	scanf("%d",&sel);
	
	index_row = numberstatus[sel-1]/N_SIZE;
	index_col = numberstatus[sel-1]%N_SIZE;
	
	bingoBoard[index_row][index_col] = 
}

int bingo_countCompletedLine(void)
{
}

