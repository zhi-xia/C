#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//冒泡排序算法
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)  //确定排序次数
	{
		int flag = 1;   //假设已经有序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)  //每一趟冒泡排序
		{
			if (arr[j] > arr[j + 1])  //如果前一项比后一项大，则交换数据
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;  //数组并非有序
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
//	//二维数组行可以省略，但是列不能省略
//	int arr3[][4] = { 1,2,3,4,5,6 };
//
//	//打印每个元素的地址
//	//二维数组在内存中地址是连续的
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
//	//             strlen()返回的是无符号的数，可以用强制类型转换(int)strlen()
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
//	printf("%d\n", strlen(arr2));  // 随机数
//	return 0;
//}



//int main()
//{
//    char arr[] = "abcdef";
//    printf("%d\n", sizeof(arr));  //7
//    printf("%d\n", strlen(arr));  //6
//    return 0;
//}