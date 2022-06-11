#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//栈区：局部变量、函数的形式参数
//堆区：动态内存分配
//静态区：全局变量、静态变量
//void* malloc(size_t size)
int main()
{
	//向内存申请10个整型空间
	int* p = (int*)malloc(10 * sizeof(int));  //include <stdlib.h>
	if (p == NULL)
	{
		//打印错误原因
		printf("%s\n", strerror(errno));  //Not enough space
	}
	else
	{
		//正常使用空间
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//当动态申请的空间不再使用的时候就应该还给操作系统
	//void free(void* memblock);
	free(p);
	//释放了空间后指针也要置为空指针
	p = NULL;

	return 0;
}