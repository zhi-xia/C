//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}



////传递地址
//void test(int* x)
//{
//	*x = 1024;
//	printf("test函数内部 x=%d\n", *x);
//}
//
//int main()
//{
//	int x = 1;
//	printf("调用test前 x=%d\n", x);
//	test(&x);
//	printf("调用test后 x=%d\n", x);
//	return 0;
//}



//void loveYou(int n)
//{
//    int i = 1;                              // 执行 1 次
//    while (i <= n)                          // 执行 3001 次（多一次判断）
//    {
//        i++;                                // 执行 3000 次
//        printf("I Love You %d\n", i);       // 执行 3000 次
//    }
//    printf("I Love You More Than %d\n", n); // 执行 1 次
//}
////时间复杂度：T(n) = 3n + 3
//
//int main()
//{
//    loveYou(3000);
//    return 0;
//}