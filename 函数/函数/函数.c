#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//ʹ�õݹ�
void Hanoi(int n, char sou, char tar, char aux)
{
	static i = 1;
	if (1 == n)
	{
		printf("��%d�Σ���%c�ƶ���%c\n", i, sou, tar);
		i++;
	}
	else if (n >= 2)
	{
		Hanoi(n - 1, sou, aux, tar);
		printf("��%d�Σ���%c�ƶ���%c\n", i, sou, tar);
		i++;
		Hanoi(n - 1, aux, tar, sou);
	}
}
//��ŵ������
int main()
{
	int n = 0;       //n����
	char sou = 'a';  //��ʼ��
	char tar = 'b';  //Ŀ����
	char aux = 'c';  //������
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
////������̨������
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib(n);
//	printf("��%d������\n", ret);
//	return 0;
//}



////ʹ��whileѭ������쳲���������
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
////ʹ�õݹ�������Ч�ʼ���
////int Fib(int n)
////{
////	if (n <= 2)
////		return 1;
////	else
////		return Fib(n - 1) + Fib(n - 2);  //��һ�����ǰ����֮��
////}
//
////쳲��������е�n��
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	//TDD - ����������������д������ʹ�÷�������ʵ�ֺ�����
//	ret = Fib(n);
//	printf("ret = %d\n", ret);
//	return 0;
//}



////ʹ��ѭ����n�Ľ׳�
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
////ʹ�ú����ݹ���n�Ľ׳�
//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac2(n - 1);
//}
////��ӡn�Ľ׳�
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n);
//	printf("%d\n", ret);
//	return 0;
//}



////���»�С
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
////��ӡ�ַ����ĳ���
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}



////���ú����ݹ�
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
////����1234��ӡ1 2 3 4
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}



//#include "add.h"  //�����Լ�д��ͷ�ļ���˫������д
////����ͨ���������Ķ������ͷ�ļ����棬��Ҫ��ʱ��͵���
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//�����ĵ���
//	int sum = Add(a, b);
//	printf("%d", sum);
//	return 0;
//}
////�����Ķ���ͨ��д������Դ�ļ�����



////����������
//int Add(int x, int y);  //����Ĳ�������ʡ�ԣ���Ϊ�����������β�
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//�����ĵ���
//	int sum = Add(a, b);
//	printf("%d", sum);
//	return 0;
//}
//
////�����Ķ���
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}


//int main()
//{   //printf()�����ķ���ֵ������ַ��ĸ���
//	printf("%d", printf("%d", printf("%d", 43)));  //4321
//	return 0;
//}



//void Add(int* p)
//{
//	//*p++;  ����дû��Ч����ԭ����++�����ȼ�Ҫ��*��
//	(*p)++;  //��һ��()�ͺ���
//}
////дһ������ÿ����һ��num�ͼ�1
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




////ע�����������ֻ����Ԫ�صĵ�ַ�������ˣ��������������������Ĵ�С
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
//	int sz = sizeof(arr) / sizeof(arr[0]);  //��ǰ���������Ĵ�С
//
//	printf("������Ҫ���ҵ�����:>");
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);  //������Ĵ�С����ȥ
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	return 0;
//}



////�ж��Ƿ�Ϊ����
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y / 100 != 0) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
////���1000��2000֮�������
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



////�ж��Ƿ�Ϊ�������Ƿ���1���񷵻�0
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	for (i = 2; i <= sqrt(n); i++)  //ʹ�ÿ����ź���sqrt() Ҫ����ͷ�ļ� <math.h>
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
////��ӡ100��200֮�������
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



////ʹ��ָ��ֱ���޸ı�������
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
//    Swap(&a, &b);  //ȡa��b�ĵ�ַ  ����ֱ���޸����������
//    printf("a = %d b = %d\n", a, b);
//
//    return 0;
//}