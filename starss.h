#pragma once
#ifndef _HEAD_H_
#define _HEAD_H_



typedef  struct star
{
	char serial_number[40];			//明星巅峰榜
	char star_name[80];				//明星姓名
	char age[80];					//年龄
	char survey[80];				//概况
	char characters[80];			//性格特点
	char profession[80];			//职业
	struct star *next;
}star;



void statistics();
void query_mode();
//void query_by_old();
//void query_by_characters();
void remove_information();
void modification_information();
void add_information();
void show_all_information();
void login_interface(int *n);
//void sort();
void load_data();

#endif // !_HEAD_H_