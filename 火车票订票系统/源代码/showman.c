//********************
//     showman.c
//********************
#include <stdio.h>
#include "structure.h"

void showman(book *Head,int *a)
{
	book *p;
	p=Head->next;
	if(p==NULL)
	{
		printf("没有购票人信息！！\n");
		(*a)=1;
	}

	else
	{
		printf("|--------------------------------------购票人员预览---------------------------------------------------|\n");
		printf("|车票序号|  身份证号 |  姓名  |火车列次|出发城市|到达城市|出发时间|到站时间|火车票价|购买票数|总共花费|\n");
		printf("|--------|-----------|--------|--------|--------|--------|--------|--------|--------|--------|--------|\n");
		while(p!=NULL)
		{
			printf("|%-8s|%-11s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|%-8d|\n",p->Num,p->id,p->name,p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->booknum,p->price*p->booknum);
			p=p->next;
		}
		
	}
	
}
