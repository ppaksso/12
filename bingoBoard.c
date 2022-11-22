#include <stdio.h>
#include "bingoBoard.h" 
#define BINGO_NUMSTATUS_ABSENT   -1
#define BINGO_NUMSTATUS_PRESENT  0//���� absent�� �ٸ��Ը� �ϸ� �� 
#define BINGONUM_HOLE 0 //��ũ������ 

static int bingoBoard[N_SIZE][N_SIZE];
static int numberstatus[N_SIZE*N_SIZE];//static�Ἥ �ٸ� ���Ͽ��� �� �Ѿ���� 

int bingo_checkNum(int selNum)
{
	if(numberstatus[selNum-1] == BINGONUM_HOLE) 
	//� ��ġ�� �ش��ϴ� ����  BINGO_HOLE�� ����, BINGO_HOLE�� ������  �Է��� ���ڿ� �ش��ϴ� ���� ����, �� absent�� ��ȯ 
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
	  	randNum = rand()%maxNum;//�������� ���� ����  
	  	
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
		  numberstatus[k]=i*N_SIZE +j;//k+1��° ����ĭ�� ���� �ο�  
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
	//check �밢��1
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
	//check �밢��2
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
    
	//�������� �ؾ��� ��ü���� ������ �ϼ��Ǿ����� �� �� ���� 
	
	return cnt;
	
}

