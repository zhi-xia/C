#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int i = 0;
	// 指针数组 -- 存放指针的数组
	int* arr[3] = { &a,&b,&c };
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", *(arr[i]));
		printf("%p\n", &arr[i]);
	}
	return 0;
}



//int main()
//{
//	int a = 10;
//	int* pa = &a;       // 一级指针
//	int** ppa = &pa;    // 二级指针
//	int*** pppa = &ppa; // 三级指针
//	**ppa = 20;
//	printf("%d\n", **ppa);
//	printf("%d\n", a);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);  //地址-首元素的地址
//	printf("%p\n", &arr[0]);
//	//1、&arr - &数组名 - 数组名不是首元素的地址，数组名表示整个数组 &arr是取整个数组的地址
//	//2、sizeof(arr) - sizeof(数组名) - 数组名表示整个数组，sizeof(数组名)是计算整个数组的大小(单位是字节)
//	printf("%p\n", &arr);
//	printf("%d\n", sizeof(arr));
//	return 0;
//}



////用指针求字符串长度
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}



//int main()
//{
//	char ch[5] = { 0 };
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", &arr[9] - &arr[0]); // 指针-指针=中间元素的个数
//	printf("%d\n", &arr[0] - &arr[9]); // 大地址-小地址 值为负数
//	printf("%d\n", &arr[0] - &ch[0]);  // 这种写法是有问题的，两个指针要指向同一个空间才可以相减，否则结果不可预知
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int* p = &arr[9];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		//p++;  // 指针的运算
//		p -= 2;
//	}
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	pa = NULL; //这样设置以后pa就不会干扰a了
//	*pa = 30;  //空指针不能使用
//
//	//int a = 10;
//	//int* pa = &a; // 初始化
//	//int* p = NULL; // NULL - 用来初始化指针，给指针赋值
//
//
//	////数组越界导致的野指针问题
//	//int i = 0;
//	//int a[10] = { 0 };
//	//int* p = a;
//	//for (i = 0; i < 12; i++)
//	//{
//	//	//*p = i;
//	//	//p++;
//	//	*p++ = i;
//	//}
//
//
//	////野指针
//	//int* p;  //指针变量未初始化会导致取的地址是随机值，不能通过编译
//	//*p = 20;
//	//printf("%d\n", *p);
//	return 0;
//}



//int main()
//{
//    int arr[10] = { 0 };
//    char* pa = arr;  // 数组名--首元素的地址
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        *(pa + i) = 1;
//    }
//
//
//
//    //int a = 0x11223344;
//    //int* pa = &a;
//    //*pa = 0;
//    //char* pc = &a;
//    //printf("%p\n", pa);
//    //printf("%p\n", pc);
//
//
//    //指针大小在36位平台上占4个字节，在64位平台上占8个字节
//    //printf("%d\n", sizeof(char*));
//    //printf("%d\n", sizeof(short*));
//    //printf("%d\n", sizeof(int*));
//    //printf("%d\n", sizeof(double*));
//    return 0;
//}