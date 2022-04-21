#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//使用递归
void Hanoi(int n, char sou, char tar, char aux)
{
	static i = 1;
	if (1 == n)
	{
		printf("第%d次，从%c移动到%c\n", i, sou, tar);
		i++;
	}
	else if (n >= 2)
	{
		Hanoi(n - 1, sou, aux, tar);
		printf("第%d次，从%c移动到%c\n", i, sou, tar);
		i++;
		Hanoi(n - 1, aux, tar, sou);
	}
}
//汉诺塔问题
int main()
{
	int n = 0;       //n个饼
	char sou = 'a';  //起始柱
	char tar = 'b';  //目标柱
	char aux = 'c';  //辅助柱
	scanf("%d", &n);
	Hanoi(n, sou, tar, aux);
	return 0;
}



//int Fib(int n)
//{
//	int a = 1;
//	int b = 2;
//	int c = 0;
//
//	if (1 == n)
//	{
//		return 1;
//	}
//	else if (2 == n)
//	{
//		return 2;
//	}
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
////青蛙跳台阶问题
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib(n);
//	printf("有%d种跳法\n", ret);
//	return 0;
//}



////使用while循环计算斐波那契数列
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
////使用递归来计算效率极低
////int Fib(int n)
////{
////	if (n <= 2)
////		return 1;
////	else
////		return Fib(n - 1) + Fib(n - 2);  //后一项等于前两项之和
////}
//
////斐波那契数列第n项
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	//TDD - 测试驱动开发（先写函数的使用方法，再实现函数）
//	ret = Fib(n);
//	printf("ret = %d\n", ret);
//	return 0;
//}



////使用循环求n的阶乘
//int Fac1(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
////使用函数递归求n的阶乘
//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac2(n - 1);
//}
////打印n的阶乘
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n);
//	printf("%d\n", ret);
//	return 0;
//}



////大事化小
////my_strlen("bit\0")
////1+my_strlen("it\0")
////1+1+my_strlen("t\0")
////1+1+1+my_strlen("\0")
////1+1+1+0 = 3
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(arr + 1);
//	}
//	else
//		return 0;
//}
//
////int my_strlen(char* arr)
////{
////	int count = 0;
////
////	while (*arr != '\0')
////	{
////		arr++;
////		count++;
////	}
////
////	return count;
////}
////打印字符串的长度
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}



////利用函数递归
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
////输入1234打印1 2 3 4
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}



//#include "add.h"  //引用自己写的头文件用双引号来写
////我们通常将函数的定义放在头文件里面，需要的时候就调用
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数的调用
//	int sum = Add(a, b);
//	printf("%d", sum);
//	return 0;
//}
////函数的定义通常写在其他源文件里面



////函数的声明
//int Add(int x, int y);  //里面的参数可以省略，因为声明不调用形参
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数的调用
//	int sum = Add(a, b);
//	printf("%d", sum);
//	return 0;
//}
//
////函数的定义
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}


//int main()
//{   //printf()函数的返回值是输出字符的个数
//	printf("%d", printf("%d", printf("%d", 43)));  //4321
//	return 0;
//}



//void Add(int* p)
//{
//	//*p++;  这样写没有效果，原因是++的优先级要比*高
//	(*p)++;  //加一个()就好了
//}
////写一个函数每调用一次num就加1
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);//1
//	Add(&num);
//	printf("%d\n", num);//2
//	Add(&num);
//	printf("%d\n", num);//3
//	return 0;
//}




////注意这里的数组只把首元素的地址传过来了，不能在这里面计算数组的大小
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);  //提前计算好数组的大小
//
//	printf("请输入要查找的数字:>");
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);  //将数组的大小传过去
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//		printf("找到了，下标是：%d\n", ret);
//	return 0;
//}



////判断是否为闰年
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y / 100 != 0) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
////输出1000到2000之间的闰年
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((is_leap_year(year)) == 1)
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}



////判断是否为素数，是返回1，否返回0
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	for (i = 2; i <= sqrt(n); i++)  //使用开根号函数sqrt() 要引用头文件 <math.h>
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
////打印100到200之间的素数
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



////使用指针直接修改变量内容
//void Swap(int* pa, int* pb)
//{
//    int tmp = 0;
//    tmp = *pa;
//    *pa = *pb;
//    *pb = tmp;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//
//    printf("a = %d b = %d\n", a, b);
//    Swap(&a, &b);  //取a，b的地址  函数直接修改里面的内容
//    printf("a = %d b = %d\n", a, b);
//
//    return 0;
//}