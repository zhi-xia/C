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
//	//&p[4][2] - &a[4][2]��ֵΪ-4
//	//10000000000000000000000000000100 - ԭ��
//	//11111111111111111111111111111011 - ����
//	//11111111111111111111111111111100 - ����
//	//%p ��ӡ���ǲ��� FFFFFFFC
//	//FFFFFFFC,-4
//	return 0;
//}



//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };  //(0,1)�Ƕ��ű��ʽ�������1 ͬ��(2,3)=3 (4,5)=5
//	//int a[3][2] = { {0,1},{2,3},{4,5} };  //��������飬�����0
//	//���� a = {1,3,5}
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
//// ����p��ֵΪ0x100000,���±��ʽ��ֵ�Ƕ���
////��֪Test���͵Ĵ�С��20�ֽ�
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);  //00100020
//	printf("%p\n", (unsigned long)p + 0x1);  //00100001
//	printf("%p\n", (unsigned int*)p + 0x1);  //00100004
//	//ָ��+-����
//	//ȡ����ָ�����ʹ�С
//	return 0;
//}



//int main()
//{
//    int a[5] = {1,2,3,4,5};
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1)); // 2��5
//    return 0;
//}