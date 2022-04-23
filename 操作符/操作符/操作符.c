#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 1;
	int a = (++i) + (++i) + (++i);
	printf("%d\n", i);
	return 0;
}



//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();// 2 - 3 * 4 = -10
//	printf("%d\n", answer);
//	return 0;
//}



//int main()
//{
//	int i = 10;
//	i = i-- - --i * (i - 3) * i++ + ++i;
//	printf("i = %d\n", i);
//	return 0;
//}



//int main()
//{
//	char a = 3;
//	//00000000000000000000000000000011
//	//0000011 - a
//	char b = 127;
//	//00000000000000000000000001111111
//	//01111111 - b
//	char c = a + b;
//	//a、b相加
//	//00000000000000000000000000000011
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010
//	//10000010 - c
//	//11111111111111111111111110000010 - 补码
//	//11111111111111111111111110000001 - 反码
//	//10000000000000000000000001111110 - 原码
//	//-126
//	printf("%d\n", c);
//	return 0;
//}




////创建了一个结构体类型 struct Stu
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[20];
//};
//
//int main()
//{
//	int a = 10;
//	//使用struct Stu 类型创建了s1对象，并初始化
//	struct Stu s1 = { "张三",20,"1920170040" };
//	struct Stu* ps = &s1;
//
//	//结构体指针->成员名
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->id);
//
//	//printf("%s\n", (*ps).name);
//	//printf("%d\n", (*ps).age);
//	//printf("%s\n", (*ps).id);
//	
//	//结构体变量.成员名
//	//printf("%s\n", s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//	return 0;
//}



//int main()
//{
//    int a = 10;
//    int b = 20;
//    int max = 0;
//    //if (a > b)
//    //    max = a;
//    //else
//    //    max = b;
//    max = a > b ? a : b;
//    printf("max = %d\n", max);
//
//
//    //int a = 0;
//    //int b = 0;
//    ////if (a > 5)
//    ////    b = 3;
//    ////else
//    ////    b = -3;
//    ////写成条件运算符
//    //b = a > 5 ? 3 : -3;
//    //printf("b = %d\n", b);
//
//
//    //int i = 0, a = 1, b = 2, c = 3, d = 4;
//    ////i = a++ && ++b && d++;
//    ////   0      /      /
//    //// && 运算符只要前面为假，后面的都不计算了，直接输出0
//    //i = a++ || ++b || d++;
//    ////   1      /      /
//    //// || 运算符只要前面为真，后面的都不计算了，直接输出1
//
//    //printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);  // 1 2 3 4
//
//
//    //int a = 10;
//    //printf("%d\n", ++a);
//    //printf("%d\n", a++);
//    //printf("%d\n", a);
//
//
//    //int a = 0;
//    //// ~ 按位取反
//    ////00000000000000000000000000000000
//    ////11111111111111111111111111111111 - 补码
//    ////11111111111111111111111111111110 - 反码
//    ////10000000000000000000000000000001 - 原码
//    ////-1
//    //printf("%d\n", a);
//    //printf("%d\n", ~a);
//
//    //short s = 0;
//    //int a = 10;
//    //printf("%d\n", sizeof(s = a + 5));
//    //printf("%d\n", s);
//
//    return 0;
//}