#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Print(char* str)
{
	printf("%s\n", str);
}

int main()
{
	//��һ������ָ�뱣�溯����ַ
	void (*p)(char*) = Print;
	//���ú���
	(*p)("hello bit");
	return 0;
}



////����ָ�� - ��ָ�������ָ��
////����ָ�� - ��ָ������ָ��
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//printf("%d\n",Add(a, b));
//	//��ӡ�����ĵ�ַ
//	//&������ �� ������ ���Ǻ����ĵ�ַ
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);
//	//���庯��ָ��
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3));  //5
//	return 0;
//}



//void print(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//һ��ָ��p���θ�����
//	print(p, sz);
//	return 0;
//}



//void test(int arr[3][5]){}  //����
//void test1(int arr[][5]){}  //��ά�����п���ʡ��
//void test2(int arr[3][]){}  //�в���ʡ��
//void test3(int (*arr)[5]){}
//
//int main()
//{
//	int arr[3][5] = {0};
//	//��ά���鴫��
//	//test(arr);
//	//test1(arr);
//	//test2(arr);
//	test3(arr);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//�⼸��д��ȫ���ȼ�
//		printf("%d ", arr[i]);
//		printf("%d ", *(arr + i));
//		printf("%d ", p[i]);
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}



////�������������ʽ
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////������ָ�����ʽ
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);  //arr ������������Ԫ�ص�ַ
//	print2(arr, 3, 5);
//	return 0;
//}



////ָ�������ʹ�÷���
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*pa)[10] = &arr;  //ָ������
//	//�����������Ԫ��ȡ��
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d ", (*pa)[i]);
//		printf("%d ", *(*pa + i));  //*pa == arr
//	}
//	return 0;
//}



//int main()
//{
//	char* arr[5];
//	char* (*pa)[5] = &arr;
//	//char* ��Ԫ������ pa ��ָ����������� [5] ��������5�ɸ�Ԫ��
//	int arr2[10] = { 0 };
//	int (*pa2) = &arr2;
//	return 0;
//}



//int main()
//{
//	//arr - ��Ԫ�صĵ�ַ
//	//&arr[0] - ��Ԫ�صĵ�ַ
//	//&arr - ����ĵ�ַ
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = { &arr }; //������ĵ�ַ������
//	//p��������ָ��
//	return 0;
//}



//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ",* (parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a,&b,&c,&d };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%p ", arr[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 }; //��������
//	char ch[5] = { 0 };  //�ַ�����
//	int* parr[5];        //����ָ������ -- ָ������
//	char* pch[5];        //�ַ�ָ������
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";   //�����ַ�����ͬ�����ڴ���ֻ����һ��
//	char* p2 = "abcdef";
//
//	if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}



//int main()
//{
//    const char* p = "abcdef";  // ����һ�������ַ���,�����޸�
//    //*p = 'w';
//    printf("%c\n", *p);  // a
//    printf("%s\n", p);   // abcdef
//    return 0;
//}