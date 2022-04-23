#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;  //1-9
		int y = rand() % col + 1;  //1-9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}

	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	// '0'-'0'=0
	// '1'-'0'=1  字符-字符=数字
		return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

int NotFound(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1;j <= col; j++)
		{
			if (board[i][j] == '*')
				count++;
		}
	}
	return count;
}

int HaveNotFound(char show[ROWS][COLS], int x, int y)
{
	if (show[x - 1][y] == '*')
		return 1;
	if (show[x - 1][y - 1] == '*')
		return 1;
	if (show[x][y - 1] == '*')
		return 1;
	if (show[x + 1][y - 1] == '*')
		return 1;
	if (show[x + 1][y] == '*')
		return 1;
	if (show[x + 1][y + 1] == '*')
		return 1;
	if (show[x][y + 1] == '*')
		return 1;
	if (show[x - 1][y + 1] == '*')
		return 1;
	return 0;
}

//展开函数
void unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//如果展开后周围没有雷且有*，则查找
	if (get_mine_count(mine, x - 1, y) == 0 && HaveNotFound(show, x - 1, y) == 1)
		FindMine(mine, show, ROW, COL, x - 1, y);
	//如果展开后有雷，则显示雷的个数
	else
		show[x - 1][y] = get_mine_count(mine, x - 1, y) + '0';

	if (get_mine_count(mine, x - 1, y - 1) == 0 && HaveNotFound(show, x - 1, y - 1) == 1)
		FindMine(mine, show, ROW, COL, x - 1, y - 1);
	else
		show[x - 1][y - 1] = get_mine_count(mine, x - 1, y - 1) + '0';

	if (get_mine_count(mine, x, y - 1) == 0 && HaveNotFound(show, x, y - 1) == 1)
		FindMine(mine, show, ROW, COL, x, y - 1);
	else
		show[x][y - 1] = get_mine_count(mine, x, y - 1) + '0';

	if (get_mine_count(mine, x + 1, y - 1) == 0 && HaveNotFound(show, x + 1, y - 1) == 1)
		FindMine(mine, show, ROW, COL, x + 1, y - 1);
	else
		show[x + 1][y - 1] = get_mine_count(mine, x + 1, y - 1) + '0';

	if (get_mine_count(mine, x + 1, y) == 0 && HaveNotFound(show, x + 1, y) == 1)
		FindMine(mine, show, ROW, COL, x + 1, y);
	else
		show[x + 1][y] = get_mine_count(mine, x + 1, y) + '0';

	if (get_mine_count(mine, x + 1, y + 1) == 0 && HaveNotFound(show, x + 1, y + 1) == 1)
		FindMine(mine, show, ROW, COL, x + 1, y + 1);
	else
		show[x + 1][y + 1] = get_mine_count(mine, x + 1, y + 1) + '0';

	if (get_mine_count(mine, x, y + 1) == 0 && HaveNotFound(show, x, y + 1) == 1)
		FindMine(mine, show, ROW, COL, x, y + 1);
	else
		show[x][y + 1] = get_mine_count(mine, x, y + 1) + '0';

	if (get_mine_count(mine, x - 1, y + 1) == 0 && HaveNotFound(show, x - 1, y + 1) == 1)
		FindMine(mine, show, ROW, COL, x - 1, y + 1);
	else
		show[x - 1][y + 1] = get_mine_count(mine, x - 1, y + 1) + '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = NotFound(show, row, col);
	//9*9-10=71
	while (win > EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>\n");
		scanf("%d%d", &x, &y);
		if (x >= 0 && x <= row && y >= 0 && y <= col)
		{
			//坐标合法
			//1、踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else  //2、不是雷
			{
				//计算x,y周围有几个雷
				int count = get_mine_count(mine, x, y);
				if (count == 0)  //如果周围没有雷，展开
				{
					//unfold(mine, show, x, y);
					show[x][y] = ' ';
					show[x - 1][y] = get_mine_count(mine, x - 1, y) + '0';
					show[x - 1][y - 1] = get_mine_count(mine, x - 1, y - 1) + '0';
					show[x][y - 1] = get_mine_count(mine, x, y - 1) + '0';
					show[x + 1][y - 1] = get_mine_count(mine, x + 1, y - 1) + '0';
					show[x + 1][y] = get_mine_count(mine, x + 1, y) + '0';
					show[x + 1][y + 1] = get_mine_count(mine, x + 1, y + 1) + '0';
					show[x][y + 1] = get_mine_count(mine, x, y + 1) + '0';
					show[x - 1][y + 1] = get_mine_count(mine, x - 1, y + 1) + '0';
				}
				else
				{
					//如果周围有雷，显示周围雷的数量
					show[x][y] = count + '0';  //计算出来的count是一个数字，加上'0'变成字符
				}
				win = NotFound(show, row, col);
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("非法坐标，请重新输入！\n");
		}
	}
	if (win == EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}