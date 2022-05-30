#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	//10,5
	return 0;
}



//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//p[4][2] == *(*(p + 4) + 2)
//	//&p[4][2] - &a[4][2]的值为-4
//	//10000000000000000000000000000100 - 原码
//	//11111111111111111111111111111011 - 反码
//	//11111111111111111111111111111100 - 补码
//	//%p 打印的是补码 FFFFFFFC
//	//FFFFFFFC,-4
//	return 0;
//}



//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };  //(0,1)是逗号表达式，结果是1 同理(2,3)=3 (4,5)=5
//	//int a[3][2] = { {0,1},{2,3},{4,5} };  //如果是数组，结果是0
//	//所以 a = {1,3,5}
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);  //1
//	return 0;
//}



//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x\n", ptr1[-1], *ptr2);  //4,2000000
//}



//struct Test
//{
//	int Num;
//	char* pcName;
//	short sData;
//	char cha[2];
//	short sBa[4];
//}* p;
//// 假设p的值为0x100000,如下表达式的值是多少
////已知Test类型的大小是20字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);  //00100020
//	printf("%p\n", (unsigned long)p + 0x1);  //00100001
//	printf("%p\n", (unsigned int*)p + 0x1);  //00100004
//	//指针+-整数
//	//取决于指针类型大小
//	return 0;
//}



//int main()
//{
//    int a[5] = {1,2,3,4,5};
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1)); // 2，5
//    return 0;
//}