#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strncpy(char* dest,const char* src,size_t count)
{
	assert(dest && src);
	char* ret = dest;
	//1.把字符拷贝过去(自己实现)
	//int i = 0;
	//for (i = 0; i < count; i++)
	//{
	//	if (*src)
	//		*dest++ = *src++;
	//	else
	//		*dest++ = '\0';
	//}
	//(大佬实现)
	while (count && (*dest++ = *src++))
		count--;
	if (count)
		while (--count)  //这里前置--是因为前面while循环的时候已经拷贝了一个\0
			*dest = '\0';
	//返回dest初始地址
	return ret;
}

int main()
{
	char arr1[10] = "abc";
	char arr2[] = "hello bit";
	//strcpy(arr1, arr2);
	//这种写法不安全，不管arr2有多少个字符，全都会拷贝过去，有可能会越界
	//strncpy(arr1, arr2, 6); //第三个参数是要拷贝的字符个数，如果比源字符串长，则补'\0'
	my_strncpy(arr1, arr2, 6);
	printf("%s\n", arr1);
	return 0;
}



////字符串比较函数 - strcmp()
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0; //相等
//		str1++;
//		str2++;
//	}
//	//return (*str1 - *str2);
//	if (*str1 > *str2)
//		return 1;  //大于
//	else
//		return -1; //小于
//}
//
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "qabc";
//	//比较两个字符串是否相等
//	//比较的是ASCLL码值，如果第一个字符相等，就比较下一个，如果第一个比第二个大，返回大于0的数
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}



//#include <string.h>
//#include <assert.h>
////字符串追加
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//1.找到目的字符串的'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//3.返回目的地址
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}




//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的空间，包含'\0'
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//返回目的空间的起始地址
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}