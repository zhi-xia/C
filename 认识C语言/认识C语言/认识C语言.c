#include <stdio.h>			
#include <string.h>



////利用结构体类型--创建一个该类型的结构体变量
//struct Book
//{
//	char name[20];
//	short price;
//};
//
//int main()
//{
//	struct Book b1 = { "C语言程序设计",55 };
//	struct Book* pb1 = &b1;
//
//	//printf("%s\n", pb1->name);
//	//printf("%d元\n", pb1->price);
//
//	//printf("书名：%s\n", (*pb1).name);
//	//printf("价格：%d元\n", (*pb1).price);
//
//	printf("书名：%s\n", b1.name);
//	printf("价格：%d元\n", b1.price);
//	//修改数字变量内容
//	b1.price = 15;
//	printf("修改后的价格：%d元\n", b1.price);
//	//修改字符串变量内容
//	//使用 -- strcpy(需要被修改的变量，内容)函数 -- 替换原来的内容
//	strcpy(b1.name,"C++");
//	printf("修改后的书名：%s\n", b1.name);
//	
//	return 0;
//}

////初识指针
//int main()
//{
//	char ch = 'w';
//	char* pch = &ch;
//	*pch = 'a';
//	printf("%c\n", ch);
//	printf("%d\n", sizeof(pch));//指针变量在64位操作系统中占8个字节
//	return 0;
//}



//int main()
//{
//	int a = 10;//4个字节
//	//有一种变量是用来存放地址的--指针变量
//	int* p = &a; //取a的地址
//	printf("&a = %p\n", &a); //%p 用来打印地址
//	printf(" p = %p\n", p);
//	printf("*p = %d\n", *p);// * -- 解引用操作符
//	*p = 20; //会循着地址修改数据
//	printf("*p = %d\n", *p);
//	printf(" a = %d\n", a);
//	//a 的地址 0000006D1F75FC54
//	return 0;
//}



////函数定义
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
////宏的定义
//#define MAX(X,Y) (X>Y?X:Y)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数的实现
//	int max = Max(a, b);
//	printf("max = %d\n", max);
//	//宏的实现
//	max = MAX(a, b);  //会被编译器解析成(a>b?a:b)
//	printf("max = %d\n", max);
//	return 0;
//}




//#define MAX 100 //#define 定义标识符常量
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
//	//static 修饰局部变量，局部变量生命周期变长
//	//static 修饰全局变量，改变了变量的作用域，让静态的全局变量只能在自己所在的源文件内部使用
//	//其他源文件无法使用
//	//extern -- 声明外部符号
//	extern int g_val;
//	printf("g_val = %d\n", g_val);
//	//全局变量g_val2被static修饰了，无法从外部引用。
//	//extern int g_val2;
//	//printf("g_val2 = %d\n", g_val2);
//	//static 修饰函数跟全局变量相似，也是无法被其他源文件所调用
//	extern int Add(int, int);
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
//}



//void test()
//{
//	//int a = 1; 非静态的变量每次都会被销毁
//	//static 修饰局部变量，局部变量生命周期变长
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
//	//typedef - 类型定义 - 类型重定义
//	typedef int i;
//	int a = 10;
//	i b = 20;
//	printf("a = %d\nb = %d", a, b);
//	return 0;
//}



//int main()
//{
//	//register int a = 0;//建议把a定义成寄存器变量，提高访问速度，具体情况取决于编译器。
//	int a = -1;//int(signed int)定义的变量是有符号的，
//	printf("a = %d\n", a);
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 111;
//	int max = 0;
//	//条件运算符（三目运算符）
//	max = a > b ? a : b;
//	printf("%d\n", max);
//	return 0;
//}



//int main()
//{
//	//强制类型转换  （类型）
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



////求最大值函数
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
//	printf("最大值是：%d\n",max);
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
//	//计算数组大小
//	printf("%d\n", sizeof(arr));
//	//计算数组元素个数
//	int sz = sizeof(arr) / sizeof(int);
//	printf("%d\n", sz);
//	return 0;
//}



//int main()
//{
//	int a = 23;
//	//移位操作符
//	int b = a << 9;
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}



//int main()
//{
//	//定义一个数组，用来存储相同类型数据
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for(int i=0;i<10;i++)
//	printf("%d\n", arr1[i]);
//	return 0;
//}



////定义一个求和函数
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
//	printf("加入比特");
//	while (line<=2000)
//	{
//	printf("敲一行代码：%d\n", line);
//	line++;
//	}
//	printf("好offer");
//	return 0;
//}




//int main()
//{
//	int input = 0;
//	printf("加入比特\n");
//	printf("你要好好学习吗？ >:");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("好offer");
//	else
//		printf("卖红薯");
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
//	//strlen()求字符串长度
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//随机值
//	printf("%d\n", strlen(arr3));//3
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abc";//将字符串存储到数组里面
//	char arr2[] = { 'a','b','c','\0'};//字符串结尾有隐藏的\0，表示字符串结束。
//	char arr3[] = { 'a','b','c',0};
//	printf("%s\n", arr1);//打印字符串用%s
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
//	//枚举常量
//	enum Sex man = male;
//	printf("%d\n", male);//0
//	printf("%d\n", female);//1
//	printf("%d\n", secret);//2
//	return 0;
//}



//求和
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