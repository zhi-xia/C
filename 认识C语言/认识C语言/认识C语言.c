#include <stdio.h>			
#include <string.h>



////���ýṹ������--����һ�������͵Ľṹ�����
//struct Book
//{
//	char name[20];
//	short price;
//};
//
//int main()
//{
//	struct Book b1 = { "C���Գ������",55 };
//	struct Book* pb1 = &b1;
//
//	//printf("%s\n", pb1->name);
//	//printf("%dԪ\n", pb1->price);
//
//	//printf("������%s\n", (*pb1).name);
//	//printf("�۸�%dԪ\n", (*pb1).price);
//
//	printf("������%s\n", b1.name);
//	printf("�۸�%dԪ\n", b1.price);
//	//�޸����ֱ�������
//	b1.price = 15;
//	printf("�޸ĺ�ļ۸�%dԪ\n", b1.price);
//	//�޸��ַ�����������
//	//ʹ�� -- strcpy(��Ҫ���޸ĵı���������)���� -- �滻ԭ��������
//	strcpy(b1.name,"C++");
//	printf("�޸ĺ��������%s\n", b1.name);
//	
//	return 0;
//}

////��ʶָ��
//int main()
//{
//	char ch = 'w';
//	char* pch = &ch;
//	*pch = 'a';
//	printf("%c\n", ch);
//	printf("%d\n", sizeof(pch));//ָ�������64λ����ϵͳ��ռ8���ֽ�
//	return 0;
//}



//int main()
//{
//	int a = 10;//4���ֽ�
//	//��һ�ֱ�����������ŵ�ַ��--ָ�����
//	int* p = &a; //ȡa�ĵ�ַ
//	printf("&a = %p\n", &a); //%p ������ӡ��ַ
//	printf(" p = %p\n", p);
//	printf("*p = %d\n", *p);// * -- �����ò�����
//	*p = 20; //��ѭ�ŵ�ַ�޸�����
//	printf("*p = %d\n", *p);
//	printf(" a = %d\n", a);
//	//a �ĵ�ַ 0000006D1F75FC54
//	return 0;
//}



////��������
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
////��Ķ���
//#define MAX(X,Y) (X>Y?X:Y)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//������ʵ��
//	int max = Max(a, b);
//	printf("max = %d\n", max);
//	//���ʵ��
//	max = MAX(a, b);  //�ᱻ������������(a>b?a:b)
//	printf("max = %d\n", max);
//	return 0;
//}




//#define MAX 100 //#define �����ʶ������
//
//int main()
//{
//	int a = 100;
//	int b = MAX;
//	printf("a = %d\nb = %d", a, b);
//	return 0;
//}



//int main()
//{
//	//static ���ξֲ��������ֲ������������ڱ䳤
//	//static ����ȫ�ֱ������ı��˱������������þ�̬��ȫ�ֱ���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ��
//	//����Դ�ļ��޷�ʹ��
//	//extern -- �����ⲿ����
//	extern int g_val;
//	printf("g_val = %d\n", g_val);
//	//ȫ�ֱ���g_val2��static�����ˣ��޷����ⲿ���á�
//	//extern int g_val2;
//	//printf("g_val2 = %d\n", g_val2);
//	//static ���κ�����ȫ�ֱ������ƣ�Ҳ���޷�������Դ�ļ�������
//	extern int Add(int, int);
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
//}



//void test()
//{
//	//int a = 1; �Ǿ�̬�ı���ÿ�ζ��ᱻ����
//	//static ���ξֲ��������ֲ������������ڱ䳤
//	static int a = 1;
//	a++;
//	printf("a = %d\n", a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}



//int main()
//{
//	//typedef - ���Ͷ��� - �����ض���
//	typedef int i;
//	int a = 10;
//	i b = 20;
//	printf("a = %d\nb = %d", a, b);
//	return 0;
//}



//int main()
//{
//	//register int a = 0;//�����a����ɼĴ�����������߷����ٶȣ��������ȡ���ڱ�������
//	int a = -1;//int(signed int)����ı������з��ŵģ�
//	printf("a = %d\n", a);
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 111;
//	int max = 0;
//	//�������������Ŀ�������
//	max = a > b ? a : b;
//	printf("%d\n", max);
//	return 0;
//}



//int main()
//{
//	//ǿ������ת��  �����ͣ�
//	int a = (int)3.14;
//	printf("%lf\n", (double)a);
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = --a;
//	printf("a = %d  b = %d\n", a, b);
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}



////�����ֵ����
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int max = Max(num1, num2);
//	printf("���ֵ�ǣ�%d\n",max);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(int);
//	printf("%d\n", sz);
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	//���������С
//	printf("%d\n", sizeof(arr));
//	//��������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(int);
//	printf("%d\n", sz);
//	return 0;
//}



//int main()
//{
//	int a = 23;
//	//��λ������
//	int b = a << 9;
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//int main()
//{
//	//����һ�����飬�����洢��ͬ��������
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for(int i=0;i<10;i++)
//	printf("%d\n", arr1[i]);
//	return 0;
//}



////����һ����ͺ���
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int sum = 0;
//	sum = Add(num1, num2);
//	printf("%d\n", sum);
//	return 0;
//}



//int main()
//{
//	int line = 0;
//	printf("�������");
//	while (line<=2000)
//	{
//	printf("��һ�д��룺%d\n", line);
//	line++;
//	}
//	printf("��offer");
//	return 0;
//}




//int main()
//{
//	int input = 0;
//	printf("�������\n");
//	printf("��Ҫ�ú�ѧϰ�� >:");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("��offer");
//	else
//		printf("������");
//	return 0;
//}




//int main()
//{
//	printf("%s\n", "c:\\test\\32\\test.c");
//	printf("%d\n", strlen("c:\\test\\32\\test.c"));
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a','b','c'};
//	char arr3[] = {'a','b','c','\0'};
//	//strlen()���ַ�������
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//���ֵ
//	printf("%d\n", strlen(arr3));//3
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abc";//���ַ����洢����������
//	char arr2[] = { 'a','b','c','\0'};//�ַ�����β�����ص�\0����ʾ�ַ���������
//	char arr3[] = { 'a','b','c',0};
//	printf("%s\n", arr1);//��ӡ�ַ�����%s
//	printf("%s\n", arr2);
//	printf("%s\n", arr3);
//	return 0;
//}


//enum Sex
//{
//	male,
//	female,
//	secret
//};
//
//int main()
//{
//	//ö�ٳ���
//	enum Sex man = male;
//	printf("%d\n", male);//0
//	printf("%d\n", female);//1
//	printf("%d\n", secret);//2
//	return 0;
//}



//���
//int main()					
//{	
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	extern int g_val;
//	scanf("%d%d", &num1, &num2);
//	sum = num1 + num2;
//	printf("%d\n",sum);
//	printf("g_val = %d\n", g_val);
//	return 0;
//}