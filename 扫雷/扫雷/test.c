#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
    printf("******************************\n");
    printf("**********1.��ʼ��Ϸ**********\n");
    printf("**********0.�˳���Ϸ**********\n");
    printf("******************************\n");
}

void game()
{
    //�׵���Ϣ�洢
    //1�����úõ��׵���Ϣ
    char mine[ROWS][COLS] = { 0 };  //11*11
    //2���Ų�õ��׵���Ϣ
    char show[ROWS][COLS] = { 0 };
    //��ʼ��
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //������
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //��ӡ����
    //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //ɨ��
    FindMine(mine, show, ROW, COL);

}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:>\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default :
            printf("ѡ�����������ѡ��\n");
            break;
        }
    } while (input);

}

int main()
{
    test();
    return 0;
}