#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>





////ʹ�ã�շת������������Լ��
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
//	printf("%d��%d�����Լ����%d\n", m, n, r);
//
//	return 0;
//}




////�㷨ʵ�ִӴ�С����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//
//	if (a < b)
//	{
//		int tmp = a;  //����һ����ʱ��������a��ֵ temporary
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



//��ѭ����ӡ5
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


//8��10��12��14��16
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



////���ֲ�����ϰ
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,8,9,10,11 };
//	int sz = sizeof(arr) / sizeof(arr[0]);  //���������С
//	int k = 0;  //Ҫ���ҵ���
//	int left = 0;  //���±�
//	int right = sz - 1;  //���±�
//	printf("������Ҫ���ҵ���:>");
//	scanf("%d", &k);
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;  //�м�Ԫ���±�
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
//			printf("�ҵ��ˣ��±���%d", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("�Ҳ���");
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
//		printf("����������:>");
//		scanf("%s", password);
//		//if (password == "123456") // == ���������ж������ַ����Ƿ���ȣ�Ӧ��ʹ��һ���⺯�� -- strcmp
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("��������������˳�����...\n");
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
//		Sleep(100); //˯�ߺ�����Ҫ����ͷ�ļ� <Windows.h>
//		left++;
//		right--;
//		if (left <= right)
//		{
//		system("cls"); //�����Ļ������Ҫ����ͷ�ļ� <stdlib.h>
//		}
//	}
//	return 0;
//}



////���ֲ����㷨
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,8,9,10,11 };
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]); //��������Ԫ�ظ���
//	int left = 0; //���±�
//	int right = sz - 1; //���±�
//	int ch = 0;
//	
//	printf("������Ҫ�ҵ���:>");
//	scanf("%d", &k);
//	while(left <= right)
//	{
//		int mid = (left + right) / 2; //�����м�Ԫ���±�
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
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}


//˳�����
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(int);
//	printf("������Ҫ���ҵ�����:>");
//	scanf("%d", &n);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == n)
//		{
//			printf("��Ҫ�ҵ�����arr[%d]", i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("�Ҳ���\n");
//	return 0;
//}



////����1��+2��+��+10!
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



////����n�Ľ׳�
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
//	printf("%d�Ľ׳��ǣ�%d", n,count);
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
//		//forѭ�������ݿ���ʡ�ԣ����ǲ������ʡ�ԣ��п��ܳ������벻���������
//		for (j = 0; j < 10; j++)
//			printf("hehe\n");
//	}
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//����for����ѭ�����Ʊ������á�����ҿ���д����������һ��Ҫ����д
//	//i < 10  ѭ��10��
//	for (i = 0;i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



////forѭ�� ���1-10
//int main()
//{
//	int i = 0;
//	//   ��ʼ��   �ж�   ����
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
//	printf("����������:>");
//	scanf("%s", password);
//	//���뻺����������123456\n
//	//scanfֻ��ȡ��123456   ��������ʣ\n
//	//getchar();  //��\nȡ�ߣ�������뻺�����������getchar���������ȴ�
//	//ʹ��whileѭ��������뻺����
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("��ȷ��(Y/N):>");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�");
//		printf("�����ǣ�%s", password);
//	}
//	else
//		printf("ȷ��ʧ��");
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



//��ҵ
//int main()
//{
//	int a, b, c;
//	printf("���������ε������ߣ�");
//	scanf("%d %d %d", &a, &b, &c);
//	if (a <= 0 || b <= 0 || c <= 0)
//		printf("����������");
//	else if (a == b && a == c && b == c)
//		printf("���������Ϊ�ȱ�������");
//	else if (a == b || a == c || b == c)
//		printf("���������Ϊ����������");
//	else
//		printf("���������Ϊһ��������");
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
//	//getchar������int���ͱ���
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
//			continue;  //continue �����ڽ�������ѭ���ģ�Ҳ���Ǳ��κ�ѭ����continue����Ĵ��벻��ִ�С�
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
//		switch (n) //switch ����Ƕ��ʹ��
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
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		//��ʹ�����һ��caseҲҪдbreak�������Ժ�Ҫ��caseʱ��ǰ��û��break��
//		break;
//	default:
//		printf("�������\n");
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
//		printf("������");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��");
//		break;
//	}
//
//	//case 1:
//	//	printf("����һ");
//	//	break;
//	//case 2:
//	//	printf("���ڶ�");
//	//	break;
//	//case 3:
//	//	printf("������");
//	//	break;
//	//case 4:
//	//	printf("������");
//	//	break;
//	//case 5:
//	//	printf("������");
//	//	break;
//	//case 6:
//	//	printf("������");
//	//	break;
//	//case 7:
//	//	printf("������");
//	//	break;
//	//}
//	return 0;
//}


////���100���ڵ�����
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
//	//if (num = 5) // = ��ֵ ==�ж����
//	//{
//	//	printf("hehe\n");
//	//}
//	return 0;
//}