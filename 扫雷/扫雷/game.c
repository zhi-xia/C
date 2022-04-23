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
	// '1'-'0'=1  �ַ�-�ַ�=����
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

//չ������
void unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//���չ������Χû��������*�������
	if (get_mine_count(mine, x - 1, y) == 0 && HaveNotFound(show, x - 1, y) == 1)
		FindMine(mine, show, ROW, COL, x - 1, y);
	//���չ�������ף�����ʾ�׵ĸ���
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
		printf("�������Ų��׵�����:>\n");
		scanf("%d%d", &x, &y);
		if (x >= 0 && x <= row && y >= 0 && y <= col)
		{
			//����Ϸ�
			//1������
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else  //2��������
			{
				//����x,y��Χ�м�����
				int count = get_mine_count(mine, x, y);
				if (count == 0)  //�����Χû���ף�չ��
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
					//�����Χ���ף���ʾ��Χ�׵�����
					show[x][y] = count + '0';  //���������count��һ�����֣�����'0'����ַ�
				}
				win = NotFound(show, row, col);
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룡\n");
		}
	}
	if (win == EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
	}
}