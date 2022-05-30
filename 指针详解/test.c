#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 总结 qsort函数的使用方法
// qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
// 第一个参数：待排序数组的首元素地址
// 第二个参数：待排序数组的元素个数
// 第三个参数：待排序数组每个元素的大小 - 单位是字节
// 第四个参数：函数指针 比较两个元素所用函数的地址 - 需要函数使用者自己实现
//             函数指针的两个参数是：待比较的两个元素的地址


// 因为在传递值的时候不能够传递元素类型，只能将元素的地址拆成(char*)类型
// 然后传递元素的大小 - 单位是字节
// 一个字节一个字节交换，实现整个元素值的交换
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void BubbleSort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
{
	int i = 0; //控制冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		//进行一趟冒泡排序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			// 元素比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				// 交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
struct Stu
{
	char name[20];
	int age;
};

int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型的值
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2)
{
	//比较两个浮点型的数
	// 直接相减得到的值类型是float，而函数要返回的类型是int，需要改变
	//return *(float*)e1 - *(float*)e2;
	//if (*(float*)e1 == *(float*)e2)
	//	return 0;
	//else if (*(float*)e1 > *(float*)e2)
	//	return 1;
	//else
	//	return -1;
	//或者强制类型转换
	return ((int)*(float*)e1 - (int)*(float*)e2);
}

void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	BubbleSort(f, sz, sizeof(float), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);
	}
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test3()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	BubbleSort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int m = 0;
	for (m = 0; m < sz; m++)
	{
		printf("%s %d\n", s[m].name, s[m].age);
	}
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=，应该用strcmp函数 - #include <string.h>
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void test4()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int m = 0;
	for (m = 0; m < sz; m++)
	{
		printf("%s %d\n", s[m].name, s[m].age);
	}
}

int main()
{
	//冒泡排序函数只能排序整型数组
	//qsort() - 可以排序任意类型的数据
	//BubbleSort(arr, sz);
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}

//int main()
//{
//	int a = 0;
//	char ch = 'w';
//	void* p = &a;
//	p = &ch;
//	// void* 可以接收任意类型变量的地址
//	// *p = 0;
//	// 但是不能进行解引用操作
//	// p++;
//	// 也不能进行+-整数的操作
//	return 0;
//}





////复习回顾
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int* (*pa)[10] = &arr;
//	//函数指针
//	int (*pAdd)(int, int) = Add;
//	int sum = (*pAdd)(1, 2);
//	printf("sum = %d\n", sum);
//	//函数指针的数组
//	int (*pArr[5])(int, int);
//	//指向函数指针数组的指针
//	int (*(*ppArr)[5])(int, int) = &pArr;
//	return 0;
//}





//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr; //取出数组的地址
//	int (*pf)(int, int); //pf是一个函数指针
//	int (*pfArr[4])(int, int); //pfArr是一个数组 - 函数指针数组 - 有4个元素
//	//用数组指针保存pfArr的地址
//	int (*(*ppfArr)[4])(int, int) = &pfArr;
//	//ppfarr是一个数组指针 - 指向的数组的每个元素的类型是int(*)(int,int)
//
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y) //异或
//{
//	return x ^ y;
//}
////回调函数
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//void menu()
//{
//	printf("************************\n");
//	printf("***  1. add   2. sub  **\n");
//	printf("***  3. mul   4. div  **\n");
//	printf("***  5. xor   0. exit **\n");
//	printf("************************\n");
//}
////计算器
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//创建一个函数指针数组 - 转移表
//	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}




//int main()
//{
//	//函数声明
//	char* my_strcpy(char* dest, const char* src);
//	//写一个函数指针pf，指向my_strcpy
//	char*(*pf)(char*, const char*) = my_strcpy;
//	//写一个函数指针数组，能够存放4个my_strcpy函数的地址
//	char* (*pfArr[4])(char*, const char*) = { my_strcpy };
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	//函数指针
//	int(*pa)(int, int) = Add;//Sub Mul Div
//	//函数指针数组 - 可以存放4个函数指针
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", parr[i](2, 3));// 5 -1 6 0
//	}
//
//	return 0;
//}



//int Add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int(*pa)(int, int) = Add;
//	//这几种写法都可以
//	printf("%d\n", Add(2, 3));
//	printf("%d\n", pa(2, 3));
//	printf("%d\n", (pa)(2, 3));
//	printf("%d\n", (*pa)(2, 3));
//	printf("%d\n", (**pa)(2, 3));
//	printf("%d\n", (***pa)(2, 3));
//	return 0;
//}



//int main()
//{
//	void(* signal(int, void(*)(int)) )(int);
//	//void(*)(int)是一个函数指针，参数是int返回类型是void。
//	//signal是一个函数，第一个参数是int，第二个是函数指针，返回类型是void(*)(int)
//	//直接写比较复杂，所以我们使用typedef简化函数指针类型
//	typedef unsigned int uint;
//	typedef void(*pfun_t)(int);  //pfun_t是简化后的函数指针类型
//	pfun_t signal(int, pfun_t);
//	return 0;
//}



//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//
//int main()
//{
//	//用一个函数指针保存函数地址
//	void (*p)(char*) = Print;
//	//调用函数
//	(*p)("hello bit");
//	return 0;
//}



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