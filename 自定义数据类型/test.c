#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//int main()
//{
//	enum Sex s = MALE;
//	printf("%d\n", sizeof(s)); //4
//
//	return 0;
//}



//int check_sys()
//{
//	int a = 1;
//	//����1��ʾС��
//	//����0��ʾ���
//	return *(char*)&a;
//}

//int check_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	//����1��ʾС��
//	//����0��ʾ���
//	return u.c;
//}
//
//int main()
//{
//	//int a = 0x11223344;
//	//�͵�ַ---------------->�ߵ�ַ
//	//...[][][][11][22][33][44][][][]... ����ֽ���洢ģʽ
//	//...[][][][44][33][22][11][][][]... С���ֽ���洢ģʽ
//	int ret = check_sys();
//	if (1 == ret)
//		printf("С��\n");
//	else
//		printf("���\n");
//
//	return 0;
//}



////���� - ������ - ��ͬ��
////�������ǹ���һ���ڴ�ռ��
////�ڴ��С����������Ա�Ĵ�С
////������Ա��С��������������������ʱ����Ҫ���뵽����������������
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4���ֽ�
//	//������ͬ�ĵ�ַ
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}


////ö������
//enum Sex
//{
//	//ö�ٵĿ���ȡֵ - ����
//	//���Գ�ʼ�������Ǻ��治���޸�
//	MALE = 2,
//	FEMALE = 4,
//	SECRET = 8
//};
//
//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//int main()
//{
//	enum Sex s = MALE;
//	s = FEMALE;
//	enum Color c = BLUE;
//	printf("%d %d %d\n", RED, GREEN, BLUE); // 0 1 2
//	printf("%d %d %d\n", MALE, FEMALE, SECRET); // 2 4 8
//
//	return 0;
//}



//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 20;
//	s.c = 3;
//	s.d = 4;
//	//���ڴ����� 22 03 04
//	return 0;
//}



////λ�� - ������λ
////λ�ο��ԺܺõĽ�ʡ�ռ䣬���ǿ�ƽ̨���������
//struct S
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//	//int e : 33; err ���ܳ������ʹ�С32
//};
////47bit - ռ6���ֽ�
//
//int main()
//{
//	struct S s;
//	struct S2 s2;
//	printf("%d\n", sizeof(s)); //8
//	printf("%d\n", sizeof(s2)); //3
//	return 0;
//}



//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//
//void Init(struct S* ps)
//{
//	ps->a = 100;
//	ps->c = 'w';
//	ps->d = 3.14;
//}
////��ֵ - �ǽṹ�����͵Ŀ�����ռ�ռ�Ƚϴ�
//void Print1(struct S tmp)
//{
//	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
//}
////��ַ - �����ǵ�ַ���ռ俪���Ƚ�С
//void Print2(const struct S* ps)
//{
//	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
//}
//
//int main()
//{
//	struct S s = { 0 };
//	Init(&s);
//	Print1(s);
//	Print2(&s);
//
//	return 0;
//}



//#include <stddef.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	//offsetof - ��  �������ƫ����
//	printf("%d\n", offsetof(struct S, c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}



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

