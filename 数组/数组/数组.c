#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//ð�������㷨
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)  //ȷ���������
	{
		int flag = 1;   //�����Ѿ�����
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)  //ÿһ��ð������
		{
			if (arr[j] > arr[j + 1])  //���ǰһ��Ⱥ�һ����򽻻�����
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;  //���鲢������
			}
		}
		if (1 == flag)
			break;
	}
}

int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr[] = { 9,0,1,2,3,4,5,6,7,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



//int main()
//{
//	int arr[3][4] = { 1,2,3,4,5 };
//	int arr2[3][4] = { {1,2,3},{4,5} };
//	//��ά�����п���ʡ�ԣ������в���ʡ��
//	int arr3[][4] = { 1,2,3,4,5,6 };
//
//	//��ӡÿ��Ԫ�صĵ�ַ
//	//��ά�������ڴ��е�ַ��������
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr2[%d][%d] = %p\n", i, j, &arr2[i][j]);
//		}
//	}
//
//	// 1 2 3 0
//	// 4 5 0 0
//	// 0 0 0 0
//	// 0 0 0 0
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		printf("%d ", arr2[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);
//	}
//	return 0;
//}



//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%c", arr[3]);
//	int i = 0;
//	//             strlen()���ص����޷��ŵ�����������ǿ������ת��(int)strlen()
//	for (i = 0; i < strlen(arr); i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abc";            //'a', 'b', 'c', '\0'
//	char arr2[] = { 'a','b','c' };  //'a', 'b', 'c'
//	printf("%d\n", sizeof(arr1));  // 4
//	printf("%d\n", sizeof(arr2));  // 3
//	printf("%d\n", strlen(arr1));  // 3
//	printf("%d\n", strlen(arr2));  // �����
//	return 0;
//}



//int main()
//{
//    char arr[] = "abcdef";
//    printf("%d\n", sizeof(arr));  //7
//    printf("%d\n", strlen(arr));  //6
//    return 0;
//}