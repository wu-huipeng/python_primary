#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"starss.h"
extern star *head , *p, *tail;
void query_by_old()
{
	char age[80];			//年龄
	int flag = 0, n = 0;
	printf("请输入要查询明星的年龄：");
	scanf_s("%s", age, 80);
	p = head;
	while (p)
	{
		if (strcmp(p->age, age) == 0)
		{
			if (n == 0)
				puts("\t顶峰榜       姓名       年龄        概况          性格特点           职业\n");
			printf("\t %s   %10s    %5s       %s          %s           %s\n", p->serial_number, p->star_name, p->age, p->survey, p->characters, p->profession);
			flag = 1, n++;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("\n没有符合该年龄的明星");
	getch();
}

void query_by_characters()
{
	char characters[80];		//性格特点
	int flag = 0;
	printf("请输入要查询明星的性格特点：");
	scanf_s("%s", characters, 80);
	p = head;
	while (p)
	{
		if (strcmp(p->characters, characters) == 0)
		{
			puts("\t顶峰榜       姓名       年龄        概况          性格特点           职业\n");
			printf("\t %s   %10s    %5s       %s          %s           %s\n", p->serial_number, p->star_name, p->age, p->survey, p->characters, p->profession);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("\n没有符合该条的明星");
	getch();
}
void query_mode()
{
	int n;
	system("cls");
	printf("\n\n\n\n\t\t----------查询信息-----------");
	printf("\n\n\t\t\t1.根据年龄查询\n\n\t\t\t2.根据性格关键词查询\n\n请输入你的选择：");
	scanf_s("%d", &n);
	if (n == 1) query_by_old();
	else if (n == 2) query_by_characters();
	else printf("输入的选择有误");
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
	printf("请输入需要删除明星的姓名：");
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
		printf("移除成功！");
	else
		printf("不存在该明星！");
	sort();
	getch();
}

void modification_information()
{
	char name[80], new_info[80];
	int alter;
	int n = 0;
	printf("请输入要修改明星的姓名：");
	scanf_s("%s", name, 80);
	printf("请输入要修改的内容(1.明星巅峰榜,2.明星姓名,3.年龄,4.概况,5.性格特点,6.职业)的代号：");
	scanf_s("%d", &alter);
	printf("请输入新的信息:");
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
			default:printf("不存在该代号"); getch();
			}
			break;
		}
		else p = p->next;

	}
	if (n == 0)
		printf("\n没有该明星的信息");
	else
		printf("\n修改成功！！");
	sort();    //排序
	getch();


}

void add_information()
{
	char serial_number[40];				//明星巅峰榜
	char star_name[80];				//明星姓名
	char age[80];			//年龄
	char survey[80];		//概况
	char characters[80];		//性格特点
	char profession[80];
	star *q;//职业
	int i = 0;
	p = (star *)malloc(sizeof(star));
	printf("请输入明星巅峰榜：");
	scanf_s("%s", serial_number, 40);
	printf("请输入明星姓名：");
	scanf_s("%s", star_name, 80);
	printf("请输入明显年龄：");
	scanf_s("%s", age, 80);
	printf("请输入明星概况：");
	scanf_s("%s", survey, 80);
	printf("请输入明星性格特点：");
	scanf_s("%s", characters, 80);
	printf("请输入明星职业：");
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
	sort(p, head, tail);   //排序
}

void show_all_information()
{

	puts("\t顶峰榜       姓名       年龄        概况          性格特点           职业\n");
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
	printf("...............欢迎来到明星管理系统................");
	printf("\n\n");
	printf("\t\t1.显示全部明星信息\n");
	printf("\t\t2.添加新的明星信息\n");
	printf("\t\t3.修改明星信息\n");
	printf("\t\t4.移除明星信息\n");
	printf("\t\t5.查询明星信息\n");
	printf("\t\t6.统计明星总人数\n");
	printf("\t\t7.退出系统\n\n");
	printf("请进行你的选择:");
	scanf_s("%d", n);

	return;
}



void load_data()
{
	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.1");
	strcpy_s(p->star_name, sizeof(p->star_name), "华晨宇");
	strcpy_s(p->age, sizeof(p->age), "24");
	strcpy_s(p->survey, sizeof(p->survey), "狮子座");
	strcpy_s(p->characters, sizeof(p->characters), "开朗乐观");
	strcpy_s(p->profession, sizeof(p->profession), "歌手");

	head = p;
	tail = p;
	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.6");
	strcpy_s(p->star_name, sizeof(p->star_name), "张杰");
	strcpy_s(p->age, sizeof(p->age), "28");
	strcpy_s(p->survey, sizeof(p->survey), "双鱼座");
	strcpy_s(p->characters, sizeof(p->characters), "成熟稳重");
	strcpy_s(p->profession, sizeof(p->profession), "歌手");

	tail->next = p;
	tail = p;

	p = (star *)malloc(sizeof(star));
	strcpy_s(p->serial_number, sizeof(p->serial_number), "NO.4");
	strcpy_s(p->star_name, sizeof(p->star_name), "李易峰");
	strcpy_s(p->age, sizeof(p->age), "24");
	strcpy_s(p->survey, sizeof(p->survey), "巨蟹座");
	strcpy_s(p->characters, sizeof(p->characters), "文质彬彬");
	strcpy_s(p->profession, sizeof(p->profession), "歌手+演员");
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
	printf("明星总人数有：%d(人)", m);
	getch();
}