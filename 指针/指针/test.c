#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int i = 0;
	// ָ������ -- ���ָ�������
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
//	int* pa = &a;       // һ��ָ��
//	int** ppa = &pa;    // ����ָ��
//	int*** pppa = &ppa; // ����ָ��
//	**ppa = 20;
//	printf("%d\n", **ppa);
//	printf("%d\n", a);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);  //��ַ-��Ԫ�صĵ�ַ
//	printf("%p\n", &arr[0]);
//	//1��&arr - &������ - ������������Ԫ�صĵ�ַ����������ʾ�������� &arr��ȡ��������ĵ�ַ
//	//2��sizeof(arr) - sizeof(������) - ��������ʾ�������飬sizeof(������)�Ǽ�����������Ĵ�С(��λ���ֽ�)
//	printf("%p\n", &arr);
//	printf("%d\n", sizeof(arr));
//	return 0;
//}



////��ָ�����ַ�������
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
//	printf("%d\n", &arr[9] - &arr[0]); // ָ��-ָ��=�м�Ԫ�صĸ���
//	printf("%d\n", &arr[0] - &arr[9]); // ���ַ-С��ַ ֵΪ����
//	printf("%d\n", &arr[0] - &ch[0]);  // ����д����������ģ�����ָ��Ҫָ��ͬһ���ռ�ſ������������������Ԥ֪
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
//		//p++;  // ָ�������
//		p -= 2;
//	}
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	pa = NULL; //���������Ժ�pa�Ͳ������a��
//	*pa = 30;  //��ָ�벻��ʹ��
//
//	//int a = 10;
//	//int* pa = &a; // ��ʼ��
//	//int* p = NULL; // NULL - ������ʼ��ָ�룬��ָ�븳ֵ
//
//
//	////����Խ�絼�µ�Ұָ������
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
//	////Ұָ��
//	//int* p;  //ָ�����δ��ʼ���ᵼ��ȡ�ĵ�ַ�����ֵ������ͨ������
//	//*p = 20;
//	//printf("%d\n", *p);
//	return 0;
//}



//int main()
//{
//    int arr[10] = { 0 };
//    char* pa = arr;  // ������--��Ԫ�صĵ�ַ
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
//    //ָ���С��36λƽ̨��ռ4���ֽڣ���64λƽ̨��ռ8���ֽ�
//    //printf("%d\n", sizeof(char*));
//    //printf("%d\n", sizeof(short*));
//    //printf("%d\n", sizeof(int*));
//    //printf("%d\n", sizeof(double*));
//    return 0;
//}