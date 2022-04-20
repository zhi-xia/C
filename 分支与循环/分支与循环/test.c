#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>





////使用（辗转相除法）求最大公约数
//int Divisor(int m, int n)
//{
//	int r = 0;
//
//	if (m % n == 0)
//	{
//		return n;
//	}
//
//	while (r = m % n)
//	{
//		m = n;
//		n = r;
//	}
//
//	return n;
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//
//	scanf("%d%d", &m, &n);
//	r = Divisor(m, n);
//	printf("%d与%d的最大公约数是%d\n", m, n, r);
//
//	return 0;
//}




////算法实现从大到小排序
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//
//	if (a < b)
//	{
//		int tmp = a;  //创建一个临时变量保存a的值 temporary
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//
//	printf("%d %d %d", a ,b, c);
//	return 0;
//}



//死循环打印5
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}


//8，10，12，14，16
//int sum(int a)
//{
//	int c = 0;
//	static int b = 3;
//	c += 1;
//	b += 2;
//	return (a + b + c);
//}
//
//int main()
//{
//	int i;
//	int a = 2;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d,", sum(a));
//	}
//	return 0;
//}



////二分查找练习
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,8,9,10,11 };
//	int sz = sizeof(arr) / sizeof(arr[0]);  //计算数组大小
//	int k = 0;  //要查找的数
//	int left = 0;  //左下标
//	int right = sz - 1;  //右下标
//	printf("请输入要查找的数:>");
//	scanf("%d", &k);
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;  //中间元素下标
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("找不到");
//	}
//
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		//if (password == "123456") // == 不能用来判断两个字符串是否相等，应该使用一个库函数 -- strcmp
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均错误，退出程序...\n");
//	}
//	return 0;
//}



////welcome to bit!!!!!!
////####################
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(100); //睡眠函数需要引入头文件 <Windows.h>
//		left++;
//		right--;
//		if (left <= right)
//		{
//		system("cls"); //清空屏幕函数需要引入头文件 <stdlib.h>
//		}
//	}
//	return 0;
//}



////二分查找算法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,8,9,10,11 };
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]); //计算数组元素个数
//	int left = 0; //左下标
//	int right = sz - 1; //右下标
//	int ch = 0;
//	
//	printf("请输入要找到数:>");
//	scanf("%d", &k);
//	while(left <= right)
//	{
//		int mid = (left + right) / 2; //计算中间元素下标
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//顺序查找
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(int);
//	printf("请输入要查找的数字:>");
//	scanf("%d", &n);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == n)
//		{
//			printf("您要找的数在arr[%d]", i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("找不到\n");
//	return 0;
//}



////计算1！+2！+…+10!
//int main()
//{
//	int i = 0;
//	int	n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}



////计算n的阶乘
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int count = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		count *= i;
//	}
//	printf("%d的阶乘是：%d", n,count);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	do
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	while (i < 10);
//	return 0;
//}



//int main()
//{
//	int x,y;
//	for (x = 0, y = 0;x < 2 && y < 5;++x, y++)
//		printf("hehe\n");
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//for循环的内容可以省略，但是不能随便省略，有可能出现意想不到的情况。
//		for (j = 0; j < 10; j++)
//			printf("hehe\n");
//	}
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//建议for语句的循环控制变量采用“左闭右开”写法，但不是一定要这样写
//	//i < 10  循环10次
//	for (i = 0;i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



////for循环 输出1-10
//int main()
//{
//	int i = 0;
//	//   初始化   判断   调整
//	for (i = 1;i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}



//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}



//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);
//	//输入缓冲区里面有123456\n
//	//scanf只读取了123456   缓冲区还剩\n
//	//getchar();  //将\n取走，清空输入缓冲区，下面的getchar才能正常等待
//	//使用while循环清空输入缓冲区
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("请确认(Y/N):>");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功");
//		printf("密码是：%s", password);
//	}
//	else
//		printf("确认失败");
//	return 0;
//}



//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}



//作业
//int main()
//{
//	int a, b, c;
//	printf("输入三角形的三个边：");
//	scanf("%d %d %d", &a, &b, &c);
//	if (a <= 0 || b <= 0 || c <= 0)
//		printf("不是三角形");
//	else if (a == b && a == c && b == c)
//		printf("这个三角形为等边三角形");
//	else if (a == b || a == c || b == c)
//		printf("这个三角形为等腰三角形");
//	else
//		printf("这个三角形为一般三角形");
//	return 0;
//}


//int main()
//{
//	int ch = 0;
//	//ctrl + z
//	//EOD - end of file -> -1
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}



//int main()
//{
//	//getchar可以用int类型保存
//	int ch = getchar();
//	putchar(ch);
//	printf("%d\n", sizeof(ch));
//	return 0;
//}



//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;  //continue 是用于结束本次循环的，也就是本次和循环中continue后面的代码不再执行。
//	printf("%d ", i);
//	i++;
//	}
//	return 0;
//}



//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n) //switch 允许嵌套使用
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0;
//}



//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		//即使是最后一个case也要写break，以免以后要加case时，前面没有break。
//		break;
//	default:
//		printf("输入错误\n");
//		break;
//	}
//	return 0;
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日");
//		break;
//	case 6:
//	case 7:
//		printf("休息日");
//		break;
//	}
//
//	//case 1:
//	//	printf("星期一");
//	//	break;
//	//case 2:
//	//	printf("星期二");
//	//	break;
//	//case 3:
//	//	printf("星期三");
//	//	break;
//	//case 4:
//	//	printf("星期四");
//	//	break;
//	//case 5:
//	//	printf("星期五");
//	//	break;
//	//case 6:
//	//	printf("星期六");
//	//	break;
//	//case 7:
//	//	printf("星期天");
//	//	break;
//	//}
//	return 0;
//}


////输出100以内的奇数
//int main()
//{
//	int i = 0;
//	while (i < 100)
//	{
//		if (1 == i % 2)
//		{
//			printf("%d ", i);
//		}
//		i++;
//	}
//	return 0;
//}


//int main()
//{
//	int num = 4;
//	if (5 == num)
//	{
//		printf("hehe\n");
//	}
//
//	//if (num = 5) // = 赋值 ==判断相等
//	//{
//	//	printf("hehe\n");
//	//}
//	return 0;
//}