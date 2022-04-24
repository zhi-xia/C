#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//字符串长度计算（优化）
int my_strlen(const char* str)
{
	int count = 0;
	assert(*str != NULL); //保证指针的有效性
	while (*str++ != '\0')
	{
		count++;
		//str++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdef";
	int len = 0;
	len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}



////const 的使用方法
//int main()
//{
//	const int num = 0;
//	int n = 100;
//	//const int* p = &num;
//	//const 放在指针变量的左边时，修饰的是*p，也就是说：不能通过p来改变*p（num）的值
//	int* const p = &num;
//	//const 放在指针变量的右边时，修饰的是p，p不能改变
//	//num = 20;
//	*p = 20;
//	//p = &n; //err
//
//	printf("%d\n", num);
//	return 0;
//}



////字符串复制
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//
//	//int i = 0;
//
//	//while (src[i] != '\0')
//	//{
//	//	dest[i] = src[i];
//	//	i++;
//	//}
//
//	//for (i = 0; src[i] != '\0'; i++)
//	//{
//	//	dest[i] = src[i];
//	//}
//}

////字符串复制优化
//#include <assert.h>
////把src指向的字符串拷贝到dest指向的空间，包含'\0'
//char* my_strcpy(char* dest, const char* src)  // const修饰的值不能被改变
//{
//	char* ret = dest;
//	assert(dest != NULL);  // 断言 - 如果判断为真，继续运行，如果判断为假，则报错
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char arr1[] = { "##############" };
//	char arr2[] = { "bit" };
//	//strcpy(arr1, arr2);
//	//my_strcpy(arr1, arr2);
//	//my_strcpy(arr1, NULL);
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}



//int main()
//{
//    int i = 0;
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        printf("hehe\n");
//        arr[i] = 0;
//    }
//    system("pause");
//    return 0;
//}