#include<stdio.h>
#include<Windows.h>
#define ROW 8
#define COL 8
#define ROWS ROW+2
#define COLS COL+2
char board[ROWS][COLS];
int count = 0;
struct Pos
{
	int yos;//行的偏移量
	int xos;//列的偏移量
};
struct Pos pos[3] = { { -1, -1 }, { -1, 0 }, { -1, 1 } };
void Init(void)//初始化棋盘边界
{
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			board[0][col] = '#';
			board[ROWS - 1][col] = '#';
			board[row][0] = '#';
			board[row][COLS - 1] = '#';
		}
	}
	for (i = 1; i < ROW; i++)
	{
		for (j = 1; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void show()
{
	printf("\n");
	printf("-------------------\n");
	count++;
	int i = 0;
	for (i = 0; i<ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//测试row，col是否可以放置皇后
int check(int row, int col)
{
	int nr;
	int nc;
	int i = 0;
	int ret = 1;
	for (i = 0; (i<3) && ret; i++)
	{
		nr = row;
		nc = col;
		while (ret && (board[nr][nc] != '#'))
		{
			if (board[nr][nc] == '*')
				ret = 0;
			nr = nr + pos[i].yos;
			nc = nc + pos[i].xos;
		}
	}
	return ret;
}
//找合适位置放皇后
void find(int row)
{
	if (row>ROW)
	{
		show();
	}
	else
	{
		int col = 1;
		for (col = 1; col <= COL; col++)
		{
			if (check(row, col))
			{
				board[row][col] = '*';
				find(row + 1);
				board[row][col] = ' ';
			}
		}
	}
}
int main()
{
	Init();
	find(1);
	printf("有%d种放置方法\n", count);
	system("pause");
	return 0;
}