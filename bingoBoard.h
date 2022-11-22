
#define N_SIZE  5
#define BINGO_NUMSTATUS_ABSENT   -1
#define BINGO_NUMSTATUS_PRESENT  0

void bingo_init(void);
void bingo_printBoard(void);
int bingo_countCompletedLine(void);
void bingo_inputNum(int sel);
int bingo_checkNum(int selNum);
