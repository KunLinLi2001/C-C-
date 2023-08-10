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
		printf("û�л���Ϣ����\n");
		(*a)=1;
	}
	else
	{
		printf("|--------------------------------��ƱԤ��------------------------------------|\n");
		printf("| ���д� | �������� | ������� | ����ʱ�� | ��վʱ�� | ��Ʊ�� | ʣ��Ʊ�� |\n");
		printf("|----------|----------|----------|----------|----------|----------|----------|\n");
		while(p!=NULL)
		{
			printf("|%-10s|%-10s|%-10s|%-10s|%-10s|%-10d|%-10d|\n",p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->ticketnum);
			p=p->next;
		}
		
	}
	
}
