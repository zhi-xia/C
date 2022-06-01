#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ������Ǵ��ϵ��µ�����
//���д�����������ľ����в���ĳ�������Ƿ����
//Ҫ��ʱ�临�Ӷ�С��O(N)
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
		printf("�ҵ���\n");
		printf("�±���%d %d", x, y);
	}
	else
		printf("�Ҳ���\n");
	return 0;
}



////ʵ��һ�����������������ַ�����k���ַ�
////���磺
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
//#include <string.h>
//#include <assert.h>
//////������ⷨ
//////void left_move(char arr[], int k) //��������ʽ
////void left_move(char* arr, int k)  //��ָ����ʽ
////{
////	assert(arr);  //����(Ҫ����ͷ�ļ�<assert.h>)��������ʽ��ֵΪ�٣�����
////	int i = 0;
////	for (i = 0; i < k; i++)
////	{
////		//����һ���ַ�
////		//1�����һ��Ԫ��
////		char tmp = *arr;
////		//2�Ѻ����Ԫ����ǰ�ƶ�
////		int j = 0;
////		int len = strlen(arr);
////		for (j = 0; j < len - 1; j++)
////		{
////			*(arr + j) = *(arr + j + 1);
////		}
////		//3�ѵ�һ��Ԫ�ص�ֵ�ŵ����һ��Ԫ�ص�λ��
////		*(arr + len - 1) = tmp;
////	}
////}
//
////������ת��
////ba cdef  �������
////ba fedc  �����ұ�
////cdefab   ��������
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
//	reverse(arr, arr + k - 1);//�������
//	reverse(arr + k, arr + len - 1);//�����ұ�
//	reverse(arr, arr + len - 1);//��������
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
//	//1.��str1�ַ�����׷��һ��str1�ַ���
//	// strcat()
//	// strncat()
//	//strcat(str1,str1);//err �����Լ����Լ���
//	strncat(str1, str1, len1);//abcdefabcdef\0
//	//2.�ж�str2ָ����ַ����Ƿ�Ϊstr1ָ����ַ���
//	//strstr()-�������ִ���
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



//// ������
//// a - b�ڶ����ҵ���
//// b - �ҵڶ���e����
//// c - �ҵ�һ��d�ڶ�
//// d - c����ҵ���
//// e - �ҵ��ģ�a��һ
//// ÿ���˶�˵����һ��
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



//// ������
//// �ĸ����б���һ������
//// A��������   //killer != 'a'
//// B����C      //killer == 'c'
//// C����D      //killer == 'd'
//// D��C�ں�˵  //killer != 'd'
//// ��֪������˵�滰��һ����˵��
//// ��дһ�������ҳ�����
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



////�������
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
//			//����
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//			}
//		}
//	}
//	//��ӡ
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
//	//�з��ŵ�char���� -128 --> 127
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
//	// ʵ������0x00001234
//	unsigned char b = *(unsigned char*)&a;
//	printf("%x\n", b);
//	//�ڴ�˵ı�������������0x00,С�˽����0x34
//	return 0;
//}



//int main()
//{
//	unsigned char a = 100;
//	unsigned char b = 200;
//	unsigned char c = 0;
//	//00000000000000000000000001100100 ��������
//	//00000000000000000000000011001000
//	//00000000000000000000000100101100 - 300
//	//01100100 - a
//	//11001000 - b
//	//00101100 - c
//	c = a + b;
//	printf("%d %d\n", a + b, c);//300 44
//	return 0;
//}



////����������ż����������ǰż���ں�
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		//�������ż��
//		while ((left < right) && arr[left] % 2 == 1)  //��������Խ�����
//		{
//			left++;
//		}
//		//���ұ�������
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



////����ˮ����
////1ƿ��ˮ1Ԫ��2����ƿ���Ի�1ƿ��ˮ����20��Ǯ�����Ժȶ�����ˮ
////�𣺿��Ժ�39ƿ��ˮ
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
//	printf("���Ժ�%dƿ��ˮ\n", total);
//	return 0;
//}



////��ӡ����
//int main()
//{
//	//Ҫ��ӡ������
//	int line = 0;
//	scanf("%d", &line); //7
//	//��ӡ�ϰ벿��
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//��ӡ�°벿��
//	for (i = 0;i < line - 1;i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0;j < i + 1;j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0;j < (line - i - 1)*2-1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}



////��ӡ0-100000֮���ˮ�ɻ���
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//�ж�i�Ƿ�Ϊˮ�ɻ�������������
//		//1������i��λ�� - nλ��
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2������i��ÿһλ��n�η�֮�� sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n); //����n�η�
//			tmp /= 10;
//		}
//		//3���Ƚ� i == sum
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



////��Sn = a+aa+aaa+aaaa+aaaaa...
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
//	//���ԣ������������ı��ʽΪ��ʱ�ͻᱨ��
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
//	//��ȡһ��
//	gets(arr);
//	//������
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
//	//&p[4][2] - &a[4][2]��ֵΪ-4
//	//10000000000000000000000000000100 - ԭ��
//	//11111111111111111111111111111011 - ����
//	//11111111111111111111111111111100 - ����
//	//%p ��ӡ���ǲ��� FFFFFFFC
//	//FFFFFFFC,-4
//	return 0;
//}



//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };  //(0,1)�Ƕ��ű��ʽ�������1 ͬ��(2,3)=3 (4,5)=5
//	//int a[3][2] = { {0,1},{2,3},{4,5} };  //��������飬�����0
//	//���� a = {1,3,5}
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
//// ����p��ֵΪ0x100000,���±��ʽ��ֵ�Ƕ���
////��֪Test���͵Ĵ�С��20�ֽ�
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);  //00100020
//	printf("%p\n", (unsigned long)p + 0x1);  //00100001
//	printf("%p\n", (unsigned int*)p + 0x1);  //00100004
//	//ָ��+-����
//	//ȡ����ָ�����ʹ�С
//	return 0;
//}



//int main()
//{
//    int a[5] = {1,2,3,4,5};
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1)); // 2��5
//    return 0;
//}