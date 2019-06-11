#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"starss.h"
extern star *head , *p, *tail;
void query_by_old()
{
	char age[80];			//����
	int flag = 0, n = 0;
	printf("������Ҫ��ѯ���ǵ����䣺");
	scanf_s("%s", age, 80);
	p = head;
	while (p)
	{
		if (strcmp(p->age, age) == 0)
		{
			if (n == 0)
				puts("\t�����       ����       ����        �ſ�          �Ը��ص�           ְҵ\n");
			printf("\t %s   %10s    %5s       %s          %s           %s\n", p->serial_number, p->star_name, p->age, p->survey, p->characters, p->profession);
			flag = 1, n++;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("\nû�з��ϸ����������");
	getch();
}

void query_by_characters()
{
	char characters[80];		//�Ը��ص�
	int flag = 0;
	printf("������Ҫ��ѯ���ǵ��Ը��ص㣺");
	scanf_s("%s", characters, 80);
	p = head;
	while (p)
	{
		if (strcmp(p->characters, characters) == 0)
		{
			puts("\t�����       ����       ����        �ſ�          �Ը��ص�           ְҵ\n");
			printf("\t %s   %10s    %5s       %s          %s           %s\n", p->serial_number, p->star_name, p->age, p->survey, p->characters, p->profession);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("\nû�з��ϸ���������");
	getch();
}
void query_mode()
{
	int n;
	system("cls");
	printf("\n\n\n\n\t\t----------��ѯ��Ϣ-----------");
	printf("\n\n\t\t\t1.���������ѯ\n\n\t\t\t2.�����Ը�ؼ��ʲ�ѯ\n\n���������ѡ��");
	scanf_s("%d", &n);
	if (n == 1) query_by_old();
	else if (n == 2) query_by_characters();
	else printf("�����ѡ������");
	getch();
}


void sort()
{
	star *q1 = NULL, *q2 = NULL, *q3 = NULL;
	int i = 0, flag = 0;
	p = head;

	while (p->next)
	{
		q1 = p->next;
		if (strcmp(p->serial_number, q1->serial_number) > 0 && strlen(p->serial_number) == strlen(q1->serial_number) || strlen(p->serial_number) > strlen(q1->serial_number))
		{
			flag = 1;
			q2 = q1->next;
			if (i == 0)
				head = q1;
			else
				q3->next = q1;
			p->next = q2;
			q1->next = p;
		}

		if (flag == 1)
			q3 = q1, p = q1->next;
		else
			q3 = p, p = p->next;
		if (p->next == NULL) tail = p, tail->next = NULL;
		flag = 0;
		i = 1;

	}
}


void remove_information()
{
	char name[80];
	int i = 0, flag = 0;
	printf("��������Ҫɾ�����ǵ�������");
	scanf_s("%s", name, 80);
	p = head;
	while (p)
	{

		if (strcmp(p->star_name, name) == 0)
		{
			flag = 1;
			if (i == 0) head = p->next;
			else tail->next = p->next;
			break;
		}
		else
		{
			tail = p;
			i++;
			p = p->next;
		}

	}
	if (flag == 1)
		printf("�Ƴ��ɹ���");
	else
		printf("�����ڸ����ǣ�");
	sort();
	getch();
}

void modification_information()
{
	char name[80], new_info[80];
	int alter;
	int n = 0;
	printf("������Ҫ�޸����ǵ�������");
	scanf_s("%s", name, 80);
	printf("������Ҫ�޸ĵ�����(1.�����۷��,2.��������,3.����,4.�ſ�,5.�Ը��ص�,6.ְҵ)�Ĵ��ţ�");
	scanf_s("%d", &alter);
	printf("�������µ���Ϣ:");
	scanf_s("%s", new_info, 80);
	p = head;
	while (p)
	{
		if (strcmp(p->star_name, name) == 0)
		{
			n = 1;
			switch (alter)
			{
			case 1:strcpy_s(p->serial_number, sizeof(p->serial_number), new_info); break;
			case 2:strcpy_s(p->star_name, sizeof(p->star_name), new_info); break;
			case 3:strcpy_s(p->age, sizeof(p->age), new_info); break;
			case 4:strcpy_s(p->survey, sizeof(p->survey), new_info); break;
			case 5:strcpy_s(p->characters, sizeof(p->characters), new_info); break;
			case 6:strcpy_s(p->profession, sizeof(p->profession), new_info); break;
			default:printf("�����ڸô���"); getch();
			}
			break;
		}
		else p = p->next;

	}
	if (n == 0)
		printf("\nû�и����ǵ���Ϣ");
	else
		printf("\n�޸ĳɹ�����");
	sort();    //����
	getch();


}

void add_information()
{
	char serial_number[40];				//�����۷��
	char star_name[80];				//��������
	char age[80];			//����
	char survey[80];		//�ſ�
	char characters[80];		//�Ը��ص�
	char profession[80];
	star *q;//ְҵ
	int i = 0;
	p = (star *)malloc(sizeof(star));
	printf("�����������۷��");
	scanf_s("%s", serial_number, 40);
	printf("����������������");
	scanf_s("%s", star_name, 80);
	printf("�������������䣺");
	scanf_s("%s", age, 80);
	printf("���������Ǹſ���");
	scanf_s("%s", survey, 80);
	printf("�����������Ը��ص㣺");
	scanf_s("%s", characters, 80);
	printf("����������ְҵ��");
	scanf_s("%s", profession, 80);

	strcpy_s(p->serial_number, sizeof(p->serial_number), serial_number);
	strcpy_s(p->star_name, sizeof(p->star_name), star_name);
	strcpy_s(p->age, sizeof(p->age), age);
	strcpy_s(p->survey, sizeof(p->survey), survey);
	strcpy_s(p->characters, sizeof(p->characters), characters);
	strcpy_s(p->profession, sizeof(p->profession), profession);
	tail->next = p;
	tail = p;
	tail->next = NULL;
	sort(p, head, tail);   //����
}

void show_all_information()
{

	puts("\t�����       ����       ����        �ſ�          �Ը��ص�           ְҵ\n");
	p = head;
	while (p)
	{
		printf("\t %s   %10s    %5s       %s          %s           %s\n", p->serial_number, p->star_name, p->age, p->survey, p->characters, p->profession);

		p = p->next;
	}
	getch();
}

void login_interface(int *n)
{

	printf("\n\n\n");
	printf("...............��ӭ�������ǹ���ϵͳ................");
	printf("\n\n");
	printf("\t\t1.��ʾȫ��������Ϣ\n");
	printf("\t\t2.����µ�������Ϣ\n");
	printf("\t\t3.�޸�������Ϣ\n");
	printf("\t\t4.�Ƴ�������Ϣ\n");
	printf("\t\t5.��ѯ������Ϣ\n");
	printf("\t\t6.ͳ������������\n");
	printf("\t\t7.�˳�ϵͳ\n\n");
	printf("��������ѡ��:");
	scanf_s("%d", n);

	return;
}



void load_data()
{
	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.1");
	strcpy_s(p->star_name, sizeof(p->star_name), "������");
	strcpy_s(p->age, sizeof(p->age), "24");
	strcpy_s(p->survey, sizeof(p->survey), "ʨ����");
	strcpy_s(p->characters, sizeof(p->characters), "�����ֹ�");
	strcpy_s(p->profession, sizeof(p->profession), "����");

	head = p;
	tail = p;
	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.6");
	strcpy_s(p->star_name, sizeof(p->star_name), "�Ž�");
	strcpy_s(p->age, sizeof(p->age), "28");
	strcpy_s(p->survey, sizeof(p->survey), "˫����");
	strcpy_s(p->characters, sizeof(p->characters), "��������");
	strcpy_s(p->profession, sizeof(p->profession), "����");

	tail->next = p;
	tail = p;

	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.4");
	strcpy_s(p->star_name, sizeof(p->star_name), "���׷�");
	strcpy_s(p->age, sizeof(p->age), "24");
	strcpy_s(p->survey, sizeof(p->survey), "��з��");
	strcpy_s(p->characters, sizeof(p->characters), "���ʱ��");
	strcpy_s(p->profession, sizeof(p->profession), "����+��Ա");
	tail->next = p;
	tail = p;
	tail->next = NULL;

}
void statistics() {
	int m = 0;
	p = head;
	while (p)
	{
		m++;
		p = p->next;
	}
	printf("�����������У�%d(��)", m);
	getch();
}