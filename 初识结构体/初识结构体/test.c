#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Stu
{
	char name[20];
	int age;
	char tele[12];
	char sex[5];
}Stu;

void Print1(Stu tmp)
{
	printf("name: %s\n", tmp.name);
	printf("age:  %d\n", tmp.age);
	printf("tele: %s\n", tmp.tele);
	printf("sex:  %s\n", tmp.sex);
}

void Print2(Stu* ps)
{
	printf("name: %s\n", ps->name);
	printf("age : %d\n", ps->age);
	printf("tele: %s\n", ps->tele);
	printf("sex : %s\n", ps->sex);
}

int main()
{
	Stu s = { "张三", 20 , "13798452721", "男" };
	Print1(s);
	Print2(&s);  //传地址
	return 0;
}



//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//
//struct T
//{
//	char ch[10];
//	struct S s;  //结构体可以嵌套
//	char* pc;
//};
//
//int main()
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe",{100,'w',"hello world",3.14},arr };
//	printf("%s\n", t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello world
//	printf("%lf\n", t.s.d);//3.14000
//	printf("%s\n", t.pc);//hello bit
//	return 0;
//}


//////struct - 结构体关键字  Stu - 结构体标签 struct Stu - 结构体类型
////struct Stu
////{
////    //成员变量
////    char name[20];
////    short age;
////    char tele[12];
////    char sex[5];
////}s1, s2, s3;  // 结构体变量(全局变量)
//
//typedef struct Stu   // typedef - 类型重命名
//{
//    //成员变量
//    char name[20];
//    short age;
//    char tele[12];
//    char sex[5];
//}Stu;
//
//int main()
//{
//    struct Stu s1;  //创建结构体变量(局部变量)
//    Stu s2;
//    return 0;
//}