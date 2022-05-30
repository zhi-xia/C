#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ܽ� qsort������ʹ�÷���
// qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
// ��һ���������������������Ԫ�ص�ַ
// �ڶ��������������������Ԫ�ظ���
// ����������������������ÿ��Ԫ�صĴ�С - ��λ���ֽ�
// ���ĸ�����������ָ�� �Ƚ�����Ԫ�����ú����ĵ�ַ - ��Ҫ����ʹ�����Լ�ʵ��
//             ����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ


// ��Ϊ�ڴ���ֵ��ʱ���ܹ�����Ԫ�����ͣ�ֻ�ܽ�Ԫ�صĵ�ַ���(char*)����
// Ȼ�󴫵�Ԫ�صĴ�С - ��λ���ֽ�
// һ���ֽ�һ���ֽڽ�����ʵ������Ԫ��ֵ�Ľ���
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
	int i = 0; //����ð�����������
	for (i = 0; i < sz - 1; i++)
	{
		//����һ��ð������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			// Ԫ�رȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				// ����
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
	//�Ƚ��������͵�ֵ
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
	//�Ƚ����������͵���
	// ֱ������õ���ֵ������float��������Ҫ���ص�������int����Ҫ�ı�
	//return *(float*)e1 - *(float*)e2;
	//if (*(float*)e1 == *(float*)e2)
	//	return 0;
	//else if (*(float*)e1 > *(float*)e2)
	//	return 1;
	//else
	//	return -1;
	//����ǿ������ת��
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
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=��Ӧ����strcmp���� - #include <string.h>
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
	//ð��������ֻ��������������
	//qsort() - ���������������͵�����
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
//	// void* ���Խ����������ͱ����ĵ�ַ
//	// *p = 0;
//	// ���ǲ��ܽ��н����ò���
//	// p++;
//	// Ҳ���ܽ���+-�����Ĳ���
//	return 0;
//}





////��ϰ�ع�
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//ָ������
//	int* arr[10];
//	//����ָ��
//	int* (*pa)[10] = &arr;
//	//����ָ��
//	int (*pAdd)(int, int) = Add;
//	int sum = (*pAdd)(1, 2);
//	printf("sum = %d\n", sum);
//	//����ָ�������
//	int (*pArr[5])(int, int);
//	//ָ����ָ�������ָ��
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
//	int (*p)[10] = &arr; //ȡ������ĵ�ַ
//	int (*pf)(int, int); //pf��һ������ָ��
//	int (*pfArr[4])(int, int); //pfArr��һ������ - ����ָ������ - ��4��Ԫ��
//	//������ָ�뱣��pfArr�ĵ�ַ
//	int (*(*ppfArr)[4])(int, int) = &pfArr;
//	//ppfarr��һ������ָ�� - ָ��������ÿ��Ԫ�ص�������int(*)(int,int)
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
//int Xor(int x, int y) //���
//{
//	return x ^ y;
//}
////�ص�����
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("����������������:>");
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
////������
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
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
//	//����һ������ָ������ - ת�Ʊ�
//	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//
//	return 0;
//}




//int main()
//{
//	//��������
//	char* my_strcpy(char* dest, const char* src);
//	//дһ������ָ��pf��ָ��my_strcpy
//	char*(*pf)(char*, const char*) = my_strcpy;
//	//дһ������ָ�����飬�ܹ����4��my_strcpy�����ĵ�ַ
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
//	//����ָ��
//	int(*pa)(int, int) = Add;//Sub Mul Div
//	//����ָ������ - ���Դ��4������ָ��
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
//	//�⼸��д��������
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
//	//void(*)(int)��һ������ָ�룬������int����������void��
//	//signal��һ����������һ��������int���ڶ����Ǻ���ָ�룬����������void(*)(int)
//	//ֱ��д�Ƚϸ��ӣ���������ʹ��typedef�򻯺���ָ������
//	typedef unsigned int uint;
//	typedef void(*pfun_t)(int);  //pfun_t�Ǽ򻯺�ĺ���ָ������
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
//	//��һ������ָ�뱣�溯����ַ
//	void (*p)(char*) = Print;
//	//���ú���
//	(*p)("hello bit");
//	return 0;
//}



////����ָ�� - ��ָ�������ָ��
////����ָ�� - ��ָ������ָ��
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
//	//��ӡ�����ĵ�ַ
//	//&������ �� ������ ���Ǻ����ĵ�ַ
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);
//	//���庯��ָ��
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
//	//һ��ָ��p���θ�����
//	print(p, sz);
//	return 0;
//}



//void test(int arr[3][5]){}  //����
//void test1(int arr[][5]){}  //��ά�����п���ʡ��
//void test2(int arr[3][]){}  //�в���ʡ��
//void test3(int (*arr)[5]){}
//
//int main()
//{
//	int arr[3][5] = {0};
//	//��ά���鴫��
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
//		//�⼸��д��ȫ���ȼ�
//		printf("%d ", arr[i]);
//		printf("%d ", *(arr + i));
//		printf("%d ", p[i]);
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}



////�������������ʽ
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
////������ָ�����ʽ
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
//	print1(arr, 3, 5);  //arr ������������Ԫ�ص�ַ
//	print2(arr, 3, 5);
//	return 0;
//}



////ָ�������ʹ�÷���
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*pa)[10] = &arr;  //ָ������
//	//�����������Ԫ��ȡ��
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
//	//char* ��Ԫ������ pa ��ָ����������� [5] ��������5�ɸ�Ԫ��
//	int arr2[10] = { 0 };
//	int (*pa2) = &arr2;
//	return 0;
//}



//int main()
//{
//	//arr - ��Ԫ�صĵ�ַ
//	//&arr[0] - ��Ԫ�صĵ�ַ
//	//&arr - ����ĵ�ַ
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = { &arr }; //������ĵ�ַ������
//	//p��������ָ��
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
//	int arr[10] = { 0 }; //��������
//	char ch[5] = { 0 };  //�ַ�����
//	int* parr[5];        //����ָ������ -- ָ������
//	char* pch[5];        //�ַ�ָ������
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";   //�����ַ�����ͬ�����ڴ���ֻ����һ��
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
//    const char* p = "abcdef";  // ����һ�������ַ���,�����޸�
//    //*p = 'w';
//    printf("%c\n", *p);  // a
//    printf("%s\n", p);   // abcdef
//    return 0;
//}