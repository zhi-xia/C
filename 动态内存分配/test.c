#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

int FindP(int p[], int n)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 2; i < n; i++)
	{
		for (j = 2; j < n; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j >= i)
		{
			//printf("%d ", i);
			p[count++] = i;
		}
	}
	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	int p[50] = { 0 };
	int i = 0;
	int count = FindP(p, 50);
	printf("%d ", p[5]);

	return 0;
}



//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	//释放了以后再使用属于非法访问, str是野指针
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//释放内存
//	free(str);
//	str = NULL;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	char* str2 = GetMemory(str);
//	if (str2 != NULL)
//	{
//		str = str2;
//	}
//	strcpy(str, "hello world");
//	printf("%s\n", str);
//	free(str);
//	str = NULL;
//}

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
// 	printf("%s\n", str);
//	free(str);
//	str = NULL;
//}

//int main()
//{
//	Test();
//	return 0;
//}



//int main()
//{
//	//内存泄露
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}



//int main()
//{
//	//int* p = (int*)malloc(40);
//	//if (p == NULL)
//	//{
//	//	return 0;
//	//}
//	//int* p2 = realloc(p, 80);
//	//if (p2 != NULL)
//	//{
//	//	p = p2;
//	//}
//	int* p = realloc(NULL, 40);//malloc(40)
//
//	return 0;
//}



//int main()
//{
//	//realloc  调整动态开辟内存空间的大小
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//就是在使用malloc开辟的20个字节的空间
//	//假设这里，20个字节不能满足我们的使用了
//	//希望我们能有40个字节的空间
//	//我们就可以使用realloc来调整动态开辟的内存
//
//	//realloc使用的注意事项：
//	//1. 如果p指向的空间之后有足够的空间可以追加，则直接追加后返回p地址
//	//2. 如果没有足够的空间可以追加，则realloc函数会重新找一个新的内存区域，
//	//   开辟一块满足需求的空间，并把原来内存中的数据拷贝过来，释放旧的内存空间
//	//   最后返回新开辟的内存空间地址
//	//3. 要用新的变量来接收realloc函数的返回值，以免旧的地址丢失
//	int* p2 = realloc(p, 40);
//	if (p2 != NULL)
//	{
//		p = p2;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//int* p = (int*)malloc(10 * sizeof(int));
//	//                要开辟的数量，每个元素的大小
//	int* p = (int*)calloc(n, sizeof(int));
//	//calloc与malloc函数不同点：
//	//参数不一样
//	//calloc会初始化内容为0 malloc不会初始化
//	//malloc虽然不会初始化，但是效率会更高
//	if (p == NULL)
//	{
//		//打印错误信息
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//使用完了以后要释放空间
//	free(p);
//	//p要设置为空指针
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	//向内存申请十个整型空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	//开辟空间失败会返回 NULL
//	if (p == NULL)
//	{
//		//打印错误信息
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;
//
//	return 0;
//}





////栈区：局部变量、函数的形式参数
////堆区：动态内存分配
////静态区：全局变量、静态变量
////void* malloc(size_t size)
//int main()
//{
//	//向内存申请10个整型空间
//	int* p = (int*)malloc(10 * sizeof(int));  //include <stdlib.h>
//	if (p == NULL)
//	{
//		//打印错误原因
//		printf("%s\n", strerror(errno));  //Not enough space
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候就应该还给操作系统
//	//void free(void* memblock);
//	free(p);
//	//释放了空间后指针也要置为空指针
//	p = NULL;
//
//	return 0;
//}