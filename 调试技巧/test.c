#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//�ַ������ȼ��㣨�Ż���
int my_strlen(const char* str)
{
	int count = 0;
	assert(*str != NULL); //��ָ֤�����Ч��
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



////const ��ʹ�÷���
//int main()
//{
//	const int num = 0;
//	int n = 100;
//	//const int* p = &num;
//	//const ����ָ����������ʱ�����ε���*p��Ҳ����˵������ͨ��p���ı�*p��num����ֵ
//	int* const p = &num;
//	//const ����ָ��������ұ�ʱ�����ε���p��p���ܸı�
//	//num = 20;
//	*p = 20;
//	//p = &n; //err
//
//	printf("%d\n", num);
//	return 0;
//}



////�ַ�������
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

////�ַ��������Ż�
//#include <assert.h>
////��srcָ����ַ���������destָ��Ŀռ䣬����'\0'
//char* my_strcpy(char* dest, const char* src)  // const���ε�ֵ���ܱ��ı�
//{
//	char* ret = dest;
//	assert(dest != NULL);  // ���� - ����ж�Ϊ�棬�������У�����ж�Ϊ�٣��򱨴�
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