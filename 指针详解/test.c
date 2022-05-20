#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Print(char* str)
{
	printf("%s\n", str);
}

int main()
{
	//用一个函数指针保存函数地址
	void (*p)(char*) = Print;
	//调用函数
	(*p)("hello bit");
	return 0;
}



////数组指针 - 是指向数组的指针
////函数指针 - 是指向函数的指针
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
//	//打印函数的地址
//	//&函数名 和 函数名 都是函数的地址
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);
//	//定义函数指针
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
//	//一级指针p传参给函数
//	print(p, sz);
//	return 0;
//}



//void test(int arr[3][5]){}  //可以
//void test1(int arr[][5]){}  //二维数组行可以省略
//void test2(int arr[3][]){}  //列不能省略
//void test3(int (*arr)[5]){}
//
//int main()
//{
//	int arr[3][5] = {0};
//	//二维数组传参
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
//		//这几种写法全部等价
//		printf("%d ", arr[i]);
//		printf("%d ", *(arr + i));
//		printf("%d ", p[i]);
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}



////参数是数组的形式
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
////参数是指针的形式
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
//	print1(arr, 3, 5);  //arr 数组名就是首元素地址
//	print2(arr, 3, 5);
//	return 0;
//}



////指针数组的使用方法
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*pa)[10] = &arr;  //指针数组
//	//将数组里面的元素取出
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
//	//char* 是元素类型 pa 是指针变量的名字 [5] 是数组有5干个元素
//	int arr2[10] = { 0 };
//	int (*pa2) = &arr2;
//	return 0;
//}



//int main()
//{
//	//arr - 首元素的地址
//	//&arr[0] - 首元素的地址
//	//&arr - 数组的地址
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = { &arr }; //将数组的地址存起来
//	//p就是数组指针
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
//	int arr[10] = { 0 }; //整型数组
//	char ch[5] = { 0 };  //字符数组
//	int* parr[5];        //整型指针数组 -- 指针数组
//	char* pch[5];        //字符指针数组
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";   //常量字符串相同，在内存中只存了一份
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
//    const char* p = "abcdef";  // 这是一个常量字符串,不能修改
//    //*p = 'w';
//    printf("%c\n", *p);  // a
//    printf("%s\n", p);   // abcdef
//    return 0;
//}