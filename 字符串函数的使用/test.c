#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strncpy(char* dest,const char* src,size_t count)
{
	assert(dest && src);
	char* ret = dest;
	//1.���ַ�������ȥ(�Լ�ʵ��)
	//int i = 0;
	//for (i = 0; i < count; i++)
	//{
	//	if (*src)
	//		*dest++ = *src++;
	//	else
	//		*dest++ = '\0';
	//}
	//(����ʵ��)
	while (count && (*dest++ = *src++))
		count--;
	if (count)
		while (--count)  //����ǰ��--����Ϊǰ��whileѭ����ʱ���Ѿ�������һ��\0
			*dest = '\0';
	//����dest��ʼ��ַ
	return ret;
}

int main()
{
	char arr1[10] = "abc";
	char arr2[] = "hello bit";
	//strcpy(arr1, arr2);
	//����д������ȫ������arr2�ж��ٸ��ַ���ȫ���´����ȥ���п��ܻ�Խ��
	//strncpy(arr1, arr2, 6); //������������Ҫ�������ַ������������Դ�ַ���������'\0'
	my_strncpy(arr1, arr2, 6);
	printf("%s\n", arr1);
	return 0;
}



////�ַ����ȽϺ��� - strcmp()
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0; //���
//		str1++;
//		str2++;
//	}
//	//return (*str1 - *str2);
//	if (*str1 > *str2)
//		return 1;  //����
//	else
//		return -1; //С��
//}
//
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "qabc";
//	//�Ƚ������ַ����Ƿ����
//	//�Ƚϵ���ASCLL��ֵ�������һ���ַ���ȣ��ͱȽ���һ���������һ���ȵڶ����󣬷��ش���0����
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}



//#include <string.h>
//#include <assert.h>
////�ַ���׷��
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//1.�ҵ�Ŀ���ַ�����'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.׷��
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//3.����Ŀ�ĵ�ַ
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
//	//����srcָ����ַ�����destָ��Ŀռ䣬����'\0'
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//����Ŀ�Ŀռ����ʼ��ַ
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