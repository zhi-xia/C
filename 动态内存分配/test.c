#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//ջ�����ֲ���������������ʽ����
//��������̬�ڴ����
//��̬����ȫ�ֱ�������̬����
//void* malloc(size_t size)
int main()
{
	//���ڴ�����10�����Ϳռ�
	int* p = (int*)malloc(10 * sizeof(int));  //include <stdlib.h>
	if (p == NULL)
	{
		//��ӡ����ԭ��
		printf("%s\n", strerror(errno));  //Not enough space
	}
	else
	{
		//����ʹ�ÿռ�
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//����̬����Ŀռ䲻��ʹ�õ�ʱ���Ӧ�û�������ϵͳ
	//void free(void* memblock);
	free(p);
	//�ͷ��˿ռ��ָ��ҲҪ��Ϊ��ָ��
	p = NULL;

	return 0;
}