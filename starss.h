#pragma once
#ifndef _HEAD_H_
#define _HEAD_H_



typedef  struct star
{
	char serial_number[40];			//�����۷��
	char star_name[80];				//��������
	char age[80];					//����
	char survey[80];				//�ſ�
	char characters[80];			//�Ը��ص�
	char profession[80];			//ְҵ
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