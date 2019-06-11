#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"starss.h"

//#include"fu.c"
star *head = NULL, *p, *tail = NULL;
int main(void)
{
	int n = 0;
	
	load_data();
	sort();
	while (1)
	{
		system("cls");
		login_interface(&n);

		switch (n)
		{
		case 1:	show_all_information(); break;
		case 2: add_information(); break;
		case 3: modification_information(); break;
		case 4: remove_information(); break;
		case 5: query_mode(); break;
		case 6: statistics(); break;
		case 7:exit(0);
		default:printf("您的选择有误,请按照代号重新选择。"); getch();
		}

	}
	return 0;
}