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
		printf("û�й�Ʊ����Ϣ����\n");
		(*a)=1;
	}

	else
	{
		printf("|--------------------------------------��Ʊ��ԱԤ��---------------------------------------------------|\n");
		printf("|��Ʊ���|  ���֤�� |  ����  |���д�|��������|�������|����ʱ��|��վʱ��|��Ʊ��|����Ʊ��|�ܹ�����|\n");
		printf("|--------|-----------|--------|--------|--------|--------|--------|--------|--------|--------|--------|\n");
		while(p!=NULL)
		{
			printf("|%-8s|%-11s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|%-8d|\n",p->Num,p->id,p->name,p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->booknum,p->price*p->booknum);
			p=p->next;
		}
		
	}
	
}
