#include <stdio.h>
#include "bingoBoard.h" 
#define BINGO_NUMSTATUS_ABSENT   -1
#define BINGO_NUMSTATUS_PRESENT  0//위에 absent랑 다르게만 하면 됨 
#define BINGONUM_HOLE 0 //매크로정의 

static int bingoBoard[N_SIZE][N_SIZE];
static int numberstatus[N_SIZE*N_SIZE];//static써서 다른 파일에서 못 넘어오게 

int bingo_checkNum(int selNum)
{
	if(numberstatus[selNum-1] == BINGONUM_HOLE) 
	//어떤 위치에 해당하는 수나  BINGO_HOLE과 같음, BINGO_HOLE과 같으면  입력한 숫자에 해당하는 값이 없다, 즉 absent를 반환 
	{
		return BINGO_NUMSTATUS_ABSENT;
	}
	return BINGO_NUMSTATUS_PRESENT;
 
 } 
 
void bingo_init(void)
{
	int i,j,k;
	int randNum;
	int maxNum=N_SIZE*N_SIZE;
	
	for(i=0;i<N_SIZE*N_SIZE;i++)
	  numberstatus[i]= BINGO_NUMSTATUS_ABSENT; 

	
	for(i=0;i<N_SIZE;i++)
	{
	  for(j=0;j<N_SIZE;j++)
	  {
	  	randNum = rand()%maxNum;//랜덤으로 숫자 선택  
	  	
	  	for(k=0;k<N_SIZE*N_SIZE;k++)
	  	{
	  		if(numberstatus[k]== BINGO_NUMSTATUS_ABSENT)
	  		{
	  			if(randNum == 0)
	  			  break;
	  			else
	  			  randNum--;
			  }
		  }
		  numberstatus[k]=i*N_SIZE +j;//k+1번째 빙고칸에 숫자 부여  
		  bingoBoard[i][j]=k+1;
		  maxNum--;

		 	
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
	int row = numberstatus[sel-1]/N_SIZE;
	int col = numberstatus[sel-1]%N_SIZE;
	
	bingoBoard[row][col] = BINGONUM_HOLE;
	numberstatus[sel-1] = BINGONUM_HOLE;
}


int bingo_countCompletedLine(void)
{
	int i,j;
	int cnt=0;
	int checkBingo;
	
	//check row
	for (i=0;i<N_SIZE;i++)
	{
		checkBingo=1;
		for(j=0;j<N_SIZE;j++)
		{
			if (bingoBoard[i][j]>0)
			{
				checkBingo=0;
				break;
			}
		}
		if (checkBingo == 1)
		{
			cnt++;
		}
	
	}
	
	//check col
	for (j=0;j<N_SIZE;j++)
	{
		checkBingo=1;
		for(i=0;i<N_SIZE;i++)
		{
			if (bingoBoard[i][j]>0)
			{
				checkBingo=0;
				break;
			}
		}
		if (checkBingo == 1)
		{
			cnt++;
		}
    }
	//check 대각선1
	checkBingo=1;
	for (i=0;i<N_SIZE;i++)
	{
		if (bingoBoard[i][i]>0)
		{
			checkBingo=0;
			break;
		}
		
	
	}	
	if (checkBingo == 1)
		{
			cnt++;
		}
	//check 대각선2
	checkBingo=1;
	for (i=0;i<N_SIZE;i++)
	{

	
			if (bingoBoard[i][N_SIZE-i-1]>0)
			{
				checkBingo=0;
				break;
			}
    }
		if (checkBingo == 1)
		{
			cnt++;
	     }
    
	//누적으로 해야지 전체에서 몇줄이 완성되었는지 알 수 있음 
	
	return cnt;
	
}

