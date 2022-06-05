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
	char name[MAX_NAME]; //����
	int age;  //����
	char sex[MAX_SEX];  //�Ա�
	char tele[MAX_TELE];  //�绰
	char addr[MAX_ADDR];  //��ַ
};

struct Contact
{
	struct PeoInfo data[MAX];  //���һ����Ϣ
	int size;  //��¼��ǰ���е�Ԫ�ظ���
};


//��������
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);