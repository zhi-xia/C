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
	//offsetof - 宏  可以求出偏移量
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}



//设置默认对齐数为4
//#pragma pack(4)
//struct S
//{
//	char c;//1
//	7
//	double d;//8
//};
//取消设置的默认对齐数
//#pragma pack()
//#pragma pack(1)  //设置默认对齐数为1
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}



////内存对齐的原因：
////1.平台原因：内存没对齐，有些平台会报硬件异常
////2.浪费空间来换取时间，效率更高
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
////结构体内存对齐
////1.第一个成员在与结构体变量偏移量为0的地址处
////2.其他成员变量要对齐到对齐数的整数倍的地址处
////3.对齐数=编译器默认的对齐数与该成员变量大小的较小值
////4.结构体的总体大小为最大对齐数的整数倍数
////5.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍数处
////  结构体的整体大小就是所有对齐数(含嵌套结构体的对齐数)的整数倍数
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
//}Node; //重命名
//
//int main()
//{
//	struct Node n1;
//	Node n2;
//
//	return 0;
//}

////结构体的自引用
//struct Node
//{
//	int data;//4
//	struct Node* next;//4/8
//};

////匿名结构体变量
////没有名字，只能在声明的时候创建变量
//struct
//{
//	char a;
//	int b;
//}x;
//
////声明一个结构体类型
////声明一个学生类型，是想通过学生类型创建对象
////描述学生：属性-名字+电话+性别+年龄
//struct Stu
//{
//	char name[20];
//	char tele[12];
//	char sex[10];
//	int age;
//}s4, s5, s6;  //全局变量
//
////全局变量
//struct Stu s3;
//
//int main()
//{
//	//创建结构体变量
//	struct Stu s1;
//	struct Stu s2;
//
//	return 0;
//}

