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
//	//�ͷ����Ժ���ʹ�����ڷǷ�����, str��Ұָ��
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
//	//�ͷ��ڴ�
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
//	//�ڴ�й¶
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
//	//realloc  ������̬�����ڴ�ռ�Ĵ�С
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
//	//������ʹ��malloc���ٵ�20���ֽڵĿռ�
//	//�������20���ֽڲ����������ǵ�ʹ����
//	//ϣ����������40���ֽڵĿռ�
//	//���ǾͿ���ʹ��realloc��������̬���ٵ��ڴ�
//
//	//reallocʹ�õ�ע�����
//	//1. ���pָ��Ŀռ�֮�����㹻�Ŀռ����׷�ӣ���ֱ��׷�Ӻ󷵻�p��ַ
//	//2. ���û���㹻�Ŀռ����׷�ӣ���realloc������������һ���µ��ڴ�����
//	//   ����һ����������Ŀռ䣬����ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
//	//   ��󷵻��¿��ٵ��ڴ�ռ��ַ
//	//3. Ҫ���µı���������realloc�����ķ���ֵ������ɵĵ�ַ��ʧ
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
//	//�ͷſռ�
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
//	//                Ҫ���ٵ�������ÿ��Ԫ�صĴ�С
//	int* p = (int*)calloc(n, sizeof(int));
//	//calloc��malloc������ͬ�㣺
//	//������һ��
//	//calloc���ʼ������Ϊ0 malloc�����ʼ��
//	//malloc��Ȼ�����ʼ��������Ч�ʻ����
//	if (p == NULL)
//	{
//		//��ӡ������Ϣ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ��
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//ʹ�������Ժ�Ҫ�ͷſռ�
//	free(p);
//	//pҪ����Ϊ��ָ��
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	//���ڴ�����ʮ�����Ϳռ�
//	int* p = (int*)malloc(10 * sizeof(int));
//	//���ٿռ�ʧ�ܻ᷵�� NULL
//	if (p == NULL)
//	{
//		//��ӡ������Ϣ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;
//
//	return 0;
//}





////ջ�����ֲ���������������ʽ����
////��������̬�ڴ����
////��̬����ȫ�ֱ�������̬����
////void* malloc(size_t size)
//int main()
//{
//	//���ڴ�����10�����Ϳռ�
//	int* p = (int*)malloc(10 * sizeof(int));  //include <stdlib.h>
//	if (p == NULL)
//	{
//		//��ӡ����ԭ��
//		printf("%s\n", strerror(errno));  //Not enough space
//	}
//	else
//	{
//		//����ʹ�ÿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ���Ӧ�û�������ϵͳ
//	//void free(void* memblock);
//	free(p);
//	//�ͷ��˿ռ��ָ��ҲҪ��Ϊ��ָ��
//	p = NULL;
//
//	return 0;
//}