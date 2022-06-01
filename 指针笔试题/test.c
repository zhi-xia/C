#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵是从上到下递增的
//请编写程序在这样的矩阵中查找某个数字是否存在
//要求时间复杂度小于O(N)
//1 2 3
//4 5 6
//7 8 9
int FindNum(int arr[3][3], int k, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是%d %d", x, y);
	}
	else
		printf("找不到\n");
	return 0;
}



////实现一个函数，可以左旋字符串中k个字符
////例如：
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#include <string.h>
//#include <assert.h>
//////暴力求解法
//////void left_move(char arr[], int k) //用数组形式
////void left_move(char* arr, int k)  //用指针形式
////{
////	assert(arr);  //断言(要引用头文件<assert.h>)，如果表达式的值为假，报错
////	int i = 0;
////	for (i = 0; i < k; i++)
////	{
////		//左旋一个字符
////		//1保存第一个元素
////		char tmp = *arr;
////		//2把后面的元素向前移动
////		int j = 0;
////		int len = strlen(arr);
////		for (j = 0; j < len - 1; j++)
////		{
////			*(arr + j) = *(arr + j + 1);
////		}
////		//3把第一个元素的值放到最后一个元素的位置
////		*(arr + len - 1) = tmp;
////	}
////}
//
////三步翻转法
////ba cdef  逆序左边
////ba fedc  逆序右边
////cdefab   逆序整体
//void reverse(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	assert(k <= len);
//	reverse(arr, arr + k - 1);//逆序左边
//	reverse(arr + k, arr + len - 1);//逆序右边
//	reverse(arr, arr + len - 1);//逆序整体
//}
//
////int is_left_move(char* s1, char* s2)
////{
////	int len = strlen(s1);
////	int i = 0;
////	for (i = 0; i < len; i++)
////	{
////		left_move(s1, 1);
////		int ret = strcmp(s1, s2);
////		if (ret == 0)
////			return 1;
////	}
////	return 0;
////}
//
//int is_left_move(char* str1, char* str2)
//{
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	//1.在str1字符串中追加一个str1字符串
//	// strcat()
//	// strncat()
//	//strcat(str1,str1);//err 不能自己给自己加
//	strncat(str1, str1, len1);//abcdefabcdef\0
//	//2.判断str2指向的字符串是否为str1指向的字符串
//	//strstr()-用来找字串的
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}



//// 猜名次
//// a - b第二，我第三
//// b - 我第二，e第四
//// c - 我第一，d第二
//// d - c最后，我第三
//// e - 我第四，a第一
//// 每个人都说对了一半
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1;a <= 5;a++)
//	{
//		for (b = 1;b <= 5;b++)
//		{
//			for (c = 1;c <= 5;c++)
//			{
//				for (d = 1;d <= 5;d++)
//				{
//					for (e = 1;e <= 5;e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a*b*c*d*e==120)
//							{
//								printf("a = %d b = %d c = %d d = %d e = %d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}



//// 猜凶手
//// 四个人中必有一个凶手
//// A：不是我   //killer != 'a'
//// B：是C      //killer == 'c'
//// C：是D      //killer == 'd'
//// D：C在胡说  //killer != 'd'
//// 已知三个人说真话，一个人说谎
//// 编写一个程序找出凶手
//int main()
//{
//	int killer = 0;
//	for (killer == 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer = %c\n", killer);
//		}
//	}
//	return 0;
//}



////杨辉三角
////1
////1 1
////1 2 1
////1 3 3 1
////1 4 6 4 1
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			//计算
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//			}
//		}
//	}
//	//打印
//	for (i = 0;i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <string.h>
//int main()
//{
//	//有符号的char类型 -128 --> 127
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	//-1 -2 -3 ... -128 127 126 ... 3 2 1 0
//	printf("%d\n", strlen(a));//255
//}



//int main()
//{
//	unsigned int a = 0x1234;
//	// 实际上是0x00001234
//	unsigned char b = *(unsigned char*)&a;
//	printf("%x\n", b);
//	//在大端的编译器里面结果是0x00,小端结果是0x34
//	return 0;
//}



//int main()
//{
//	unsigned char a = 100;
//	unsigned char b = 200;
//	unsigned char c = 0;
//	//00000000000000000000000001100100 整型提升
//	//00000000000000000000000011001000
//	//00000000000000000000000100101100 - 300
//	//01100100 - a
//	//11001000 - b
//	//00101100 - c
//	c = a + b;
//	printf("%d %d\n", a + b, c);//300 44
//	return 0;
//}



////交换奇数与偶数，奇数在前偶数在后
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		//从左边找偶数
//		while ((left < right) && arr[left] % 2 == 1)  //避免数组越界访问
//		{
//			left++;
//		}
//		//从右边找奇数
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left<right)
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}



////喝汽水问题
////1瓶汽水1元，2个空瓶可以换1瓶汽水，给20块钱，可以喝多少汽水
////答：可以喝39瓶汽水
//struct Water
//{
//	int price;
//	int bottle;
//};
//
//int main()
//{
//	int money = 20;
//	int empty_bottle = 0;
//	int total = 0;
//	struct Water w = { 1,1 };
//	total = money / w.price;
//	empty_bottle = total;
//	while (empty_bottle >= 2)
//	{
//		total += empty_bottle / 2;
//		empty_bottle = empty_bottle / 2 + empty_bottle % 2;
//	}
//	printf("可以喝%d瓶汽水\n", total);
//	return 0;
//}



////打印菱形
//int main()
//{
//	//要打印多少行
//	int line = 0;
//	scanf("%d", &line); //7
//	//打印上半部分
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半部分
//	for (i = 0;i < line - 1;i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0;j < i + 1;j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0;j < (line - i - 1)*2-1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}



////打印0-100000之间的水仙花数
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i是否为水仙花数（自幂数）
//		//1、计算i的位数 - n位数
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2、计算i的每一位的n次方之和 sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n); //计算n次方
//			tmp /= 10;
//		}
//		//3、比较 i == sum
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



////求Sn = a+aa+aaa+aaaa+aaaaa...
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int sum = 0;
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	//断言，如果括号里面的表达式为假时就会报错
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char* tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);
//	//读取一行
//	gets(arr);
//	//逆序函数
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}



//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}



//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);  //at
//	return 0;
//}



//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
//	//10,5
//	return 0;
//}



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