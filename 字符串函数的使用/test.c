#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (num--)
	{
		*(char*)dest = *(char*)src; //每次都拷贝一个字节
		++(char*)dest;
		++(char*)src;
	}

	return ret;
}

struct S
{
	char name[20];
	int age;
};

void* my_memmove(void* dest, void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//前->后
	if (dest < src)
	{
		while (count--)
		{
			*(char*)src = *(char*)dest;
			++(char*)dest;
			++(char*)src;
		}
	}
	//后->前
	else
	{
		while (count--)	
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);//处理内存重叠的情况

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	//内存拷贝，可以拷贝任何类型数据
//	memcpy(arr2, arr1, sizeof(arr1));
//	float arr3[] = { 1.2, 3.14, 4.0, 5.35 };
//	float arr4[4] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//
//	struct S arr5[] = { {"张三", 20},{"李四", 30} };
//	struct S arr6[3] = { 0 };
//	my_memcpy(arr6, arr5, sizeof(arr5));
//
//	return 0;
//}



//int main()
//{
//	//char ch = 'Q';
//	//islower - 判断是否为小写字母
//	//是 - 返回非零int，否 - 返回0
//	//int ret = islower(ch);
//	//isdigit - 判断是否为数字
//	//int ret = isdigit(ch);
//	//printf("%d\n", ret);
//	//大写转化成小写字符
//	//ch = tolower(ch);
//	//putchar(ch);
//
//	char arr[] = "I Am A Student";
//	//int i = 0;
//	//while (arr[i])arr[i++] = tolower(arr[i]);
//	for (int i = 0;arr[i];arr[i++] = toupper(arr[i]));
//	printf("%s\n", arr);
//
//	return 0;
//}



//int main()
//{
//	// 错误码 - 错误信息
//	// 0 - No error
//	// 1 - Operation not permitted
//	// 2 - No such file or directory
//	// ...
//	//errno 是一个全局的错误码的变量
//	//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值到errno中
//	//char* str = strerror(2);
//	//printf("%s\n", str);
//
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (!pf)
//		printf("%s\n", strerror(errno));
//	else
//		printf("Open file success\n");
//
//	return 0;
//}



//int main()
//{
//	char arr[] = "123@234@.@234";
//	char* p = "@.";
//
//	//zpw\0bitedu.tech
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//
//	char* ret = NULL;
//	for (ret = strtok(arr, p);ret != NULL;ret = strtok(NULL, p))
//	{
//		printf("%s ", ret);
//	}
//	printf("\n");
//
//	////切割buf中的字符串
//	//char* ret = strtok(arr, p);
//	//printf("%s\n", ret);
//
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//
//	return 0;
//}



//char* my_strstr(
//	const char* p1,
//	const char* p2
//)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur = (char*)p1;
//	if (!*p2)
//		return (char*)p1;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && !(*s1 - *s2))
//			s1++, s2++;
//		if (!*s2)
//			return cur; //找到字串
//		cur++;
//	}
//	return NULL; //找不到字串
//}
//
//int main()
//{
//	char* p1 = "avbbcdef";
//	char* p2 = "bba";
//	char* ret = my_strstr(p1, p2);
//
//	if (ret == NULL)
//	{
//		printf("字串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}



//char* my_strncpy(char* dest,const char* src,size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//1.把字符拷贝过去(自己实现)
//	//int i = 0;
//	//for (i = 0; i < count; i++)
//	//{
//	//	if (*src)
//	//		*dest++ = *src++;
//	//	else
//	//		*dest++ = '\0';
//	//}
//	//(大佬实现)
//	while (count && (*dest++ = *src++))
//		count--;
//	if (count)
//		while (--count)  //这里前置--是因为前面while循环的时候已经拷贝了一个\0
//			*dest = '\0';
//	//返回dest初始地址
//	return ret;
//}
//
//int main()
//{
//	char arr1[10] = "abc";
//	char arr2[] = "hello bit";
//	//strcpy(arr1, arr2);
//	//这种写法不安全，不管arr2有多少个字符，全都会拷贝过去，有可能会越界
//	//strncpy(arr1, arr2, 6); //第三个参数是要拷贝的字符个数，如果比源字符串长，则补'\0'
//	my_strncpy(arr1, arr2, 6);
//	printf("%s\n", arr1);
//	return 0;
//}



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