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
		*(char*)dest = *(char*)src; //ÿ�ζ�����һ���ֽ�
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
	//ǰ->��
	if (dest < src)
	{
		while (count--)
		{
			*(char*)src = *(char*)dest;
			++(char*)dest;
			++(char*)src;
		}
	}
	//��->ǰ
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
	my_memmove(arr + 2, arr, 20);//�����ڴ��ص������

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
//	//�ڴ濽�������Կ����κ���������
//	memcpy(arr2, arr1, sizeof(arr1));
//	float arr3[] = { 1.2, 3.14, 4.0, 5.35 };
//	float arr4[4] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//
//	struct S arr5[] = { {"����", 20},{"����", 30} };
//	struct S arr6[3] = { 0 };
//	my_memcpy(arr6, arr5, sizeof(arr5));
//
//	return 0;
//}



//int main()
//{
//	//char ch = 'Q';
//	//islower - �ж��Ƿ�ΪСд��ĸ
//	//�� - ���ط���int���� - ����0
//	//int ret = islower(ch);
//	//isdigit - �ж��Ƿ�Ϊ����
//	//int ret = isdigit(ch);
//	//printf("%d\n", ret);
//	//��дת����Сд�ַ�
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
//	// ������ - ������Ϣ
//	// 0 - No error
//	// 1 - Operation not permitted
//	// 2 - No such file or directory
//	// ...
//	//errno ��һ��ȫ�ֵĴ�����ı���
//	//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��errno��
//	//char* str = strerror(2);
//	//printf("%s\n", str);
//
//	//���ļ�
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
//	////�и�buf�е��ַ���
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
//			return cur; //�ҵ��ִ�
//		cur++;
//	}
//	return NULL; //�Ҳ����ִ�
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
//		printf("�ִ�������\n");
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
//	//1.���ַ�������ȥ(�Լ�ʵ��)
//	//int i = 0;
//	//for (i = 0; i < count; i++)
//	//{
//	//	if (*src)
//	//		*dest++ = *src++;
//	//	else
//	//		*dest++ = '\0';
//	//}
//	//(����ʵ��)
//	while (count && (*dest++ = *src++))
//		count--;
//	if (count)
//		while (--count)  //����ǰ��--����Ϊǰ��whileѭ����ʱ���Ѿ�������һ��\0
//			*dest = '\0';
//	//����dest��ʼ��ַ
//	return ret;
//}
//
//int main()
//{
//	char arr1[10] = "abc";
//	char arr2[] = "hello bit";
//	//strcpy(arr1, arr2);
//	//����д������ȫ������arr2�ж��ٸ��ַ���ȫ���´����ȥ���п��ܻ�Խ��
//	//strncpy(arr1, arr2, 6); //������������Ҫ�������ַ������������Դ�ַ���������'\0'
//	my_strncpy(arr1, arr2, 6);
//	printf("%s\n", arr1);
//	return 0;
//}



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