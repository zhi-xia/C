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
//	//返回1表示小端
//	//返回0表示大端
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
//	//返回1表示小端
//	//返回0表示大端
//	return u.c;
//}
//
//int main()
//{
//	//int a = 0x11223344;
//	//低地址---------------->高地址
//	//...[][][][11][22][33][44][][][]... 大端字节序存储模式
//	//...[][][][44][33][22][11][][][]... 小端字节序存储模式
//	int ret = check_sys();
//	if (1 == ret)
//		printf("小端\n");
//	else
//		printf("大端\n");
//
//	return 0;
//}



////联合 - 联合体 - 共同体
////联合体是公用一块内存空间的
////内存大小至少是最大成员的大小
////当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数的整数倍
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4个字节
//	//都是相同的地址
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}


////枚举类型
//enum Sex
//{
//	//枚举的可能取值 - 常量
//	//可以初始化，但是后面不能修改
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
//	//在内存中是 22 03 04
//	return 0;
//}



////位段 - 二进制位
////位段可以很好的节省空间，但是跨平台有问题存在
//struct S
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//	//int e : 33; err 不能超过类型大小32
//};
////47bit - 占6个字节
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
////传值 - 是结构体类型的拷贝，占空间比较大
//void Print1(struct S tmp)
//{
//	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
//}
////传址 - 传的是地址，空间开销比较小
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
//	//offsetof - 宏  可以求出偏移量
//	printf("%d\n", offsetof(struct S, c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}



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

