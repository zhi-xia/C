#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>

struct PeoInfo
{
	char name[MAX_NAME]; //名字
	int age;  //年龄
	char sex[MAX_SEX];  //性别
	char tele[MAX_TELE];  //电话
	char addr[MAX_ADDR];  //地址
};

struct Contact
{
	struct PeoInfo data[MAX];  //存放一个信息
	int size;  //记录当前已有的元素个数
};


//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);