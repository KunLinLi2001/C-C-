//********************
//     showtrain.c
//********************
#include <stdio.h>
#include "structure.h"

void showtrain(node *head,int *a)
{
	node *p;
	p=head->next;
	if(p==NULL)
	{
		printf("没有火车信息！！\n");
		(*a)=1;
	}
	else
	{
		printf("|--------------------------------车票预览------------------------------------|\n");
		printf("| 火车列次 | 出发城市 | 到达城市 | 出发时间 | 到站时间 | 火车票价 | 剩余票数 |\n");
		printf("|----------|----------|----------|----------|----------|----------|----------|\n");
		while(p!=NULL)
		{
			printf("|%-10s|%-10s|%-10s|%-10s|%-10s|%-10d|%-10d|\n",p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->ticketnum);
			p=p->next;
		}
		
	}
	
}
