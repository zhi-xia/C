#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stddef.h>
struct S
{
	char c;
	int i;
	double d;
};

int main()
{
	//offsetof - ��  �������ƫ����
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}



//����Ĭ�϶�����Ϊ4
//#pragma pack(4)
//struct S
//{
//	char c;//1
//	7
//	double d;//8
//};
//ȡ�����õ�Ĭ�϶�����
//#pragma pack()
//#pragma pack(1)  //����Ĭ�϶�����Ϊ1
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}



////�ڴ�����ԭ��
////1.ƽ̨ԭ���ڴ�û���룬��Щƽ̨�ᱨӲ���쳣
////2.�˷ѿռ�����ȡʱ�䣬Ч�ʸ���
//struct S3
//{
//	double d;//8
//	char c;//1
//	int i;//4
//};
//
//struct S4
//{
//	char c1;//1
//	struct S3 s3;//16
//	double d;//8
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//	return 0;
//}



//struct S1
//{
//	char c1;//1
//	int a;//4
//	char c2;//1
//};
//
//struct S2
//{
//	char c1;//1
//	char c2;//1
//	int a;//4
//};
////�ṹ���ڴ����
////1.��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ��
////2.������Ա����Ҫ���뵽���������������ĵ�ַ��
////3.������=������Ĭ�ϵĶ�������ó�Ա������С�Ľ�Сֵ
////4.�ṹ��������СΪ������������������
////5.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������������
////  �ṹ��������С�������ж�����(��Ƕ�׽ṹ��Ķ�����)����������
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));//12
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));//8
//
//	return 0;
//}



//struct T
//{
//	double weight;
//	short age;
//};
//
//struct S
//{
//	char c;
//	struct T st;
//	int a;
//	double d;
//	char arr[20];
//};
//
//int main()
//{
//	//struct S s = { 'c', 100, 3.14, "hello bit" };
//	//printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);
//	struct S s = { 'c', {55.6, 30}, 100, 3.14, "hello bit" };
//	printf("%c %lf %d %d %lf %s\n", s.c, s.st.weight, s.st.age, s.a, s.d, s.arr);
//	return 0;
//}



//typedef struct Node
//{
//	int data;//4
//	struct Node* next;//4/8
//}Node; //������
//
//int main()
//{
//	struct Node n1;
//	Node n2;
//
//	return 0;
//}

////�ṹ���������
//struct Node
//{
//	int data;//4
//	struct Node* next;//4/8
//};

////�����ṹ�����
////û�����֣�ֻ����������ʱ�򴴽�����
//struct
//{
//	char a;
//	int b;
//}x;
//
////����һ���ṹ������
////����һ��ѧ�����ͣ�����ͨ��ѧ�����ʹ�������
////����ѧ��������-����+�绰+�Ա�+����
//struct Stu
//{
//	char name[20];
//	char tele[12];
//	char sex[10];
//	int age;
//}s4, s5, s6;  //ȫ�ֱ���
//
////ȫ�ֱ���
//struct Stu s3;
//
//int main()
//{
//	//�����ṹ�����
//	struct Stu s1;
//	struct Stu s2;
//
//	return 0;
//}

