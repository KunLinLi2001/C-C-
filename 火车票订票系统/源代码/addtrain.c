//********************
//    addtrain.c
//********************
#include<stdlib.h> 
#include<stdio.h>
#include<string.h>
#include "structure.h"
void addtrain(node *head)
{
	node *p,*r,*s;
	char num[10];
	
	r=head;
	//��������β���Ա����β�� 
	while(r->next!=NULL)
	r=r->next;
	
	while(1)
	{
		kunkun://goto����ǵĵص�
		 
		printf("�����복�κ�(0-�˳�):"); 
		scanf("%s",num);
		if(strcmp(num,"0")==0)
		{
			printf("\n��ӽ�����\n");
			break;
		}
		//ÿһ�α���ǰ����������ͷ�� 
		s=head->next;
		
		//�����ж��Ƿ��Ѵ��� 
		while(s)
		{
			if(strcmp(s->num,num)==0)
			{
				printf("���κ�%s�Ѵ��ڣ����������룡\n\n",num);
				goto kunkun;//������ظ��ģ���ֱ����������ѭ������� ��kunkun�� 
			}//goto��䲻�ᳫ�ã���������ֱ�������break+continue���β��� 
			s=s->next;
		}//***һ��ʼ�й���Ƕ��ѭ����break/continueʱ������bug 
		//����Ҫ���������Ϣ 
		p=(node *)malloc(sizeof(node));
		strcpy(p->num,num);
		printf("�������Ϣ\n"); 
		
		startcity:
		printf("��������(0-������һ��):");
		scanf("%s",p->startcity); 
		if(strcmp(p->startcity,"0")==0)
		{
			printf("\n");
			goto kunkun;			
		}
		
		reachcity:			
		printf("��վ����(0-������һ��):");
		scanf("%s",p->reachcity);  
		if(strcmp(p->reachcity,"0")==0)
		{
			printf("\n");
			goto startcity;
		}
		
		
		starttime:
		printf("����ʱ��(0-������һ��):"); 
		scanf("%s",p->starttime);
		if(strcmp(p->starttime,"0")==0)
		{
			printf("\n");
			goto reachcity;
		}
		
		
		
		reachtime:
		printf("��վʱ��(0-������һ��):"); 
		scanf("%s",p->reachtime);
		if(strcmp(p->reachtime,"0")==0)
		{
			printf("\n");
			goto starttime;
		}
		
		
		price:
		printf("��Ʊ��(-1-������һ��):"); 
		scanf("%d",&p->price);
		if(p->price==-1)
		{
			printf("\n");
			goto reachtime;
		}
		
		if(p->price<0)
		{
			printf("��Ʊ�۲���Ϊ������\n\n");
			goto price;
		}
		
		ticketnum:
		printf("ʣ��Ʊ��(-1-������һ��):"); 
		scanf("%d",&p->ticketnum);
		if(p->ticketnum==-1)
		{
			printf("\n");
			goto price;
		}
		
		if(p->ticketnum<0)
		{
			printf("Ʊ������Ϊ������\n\n");
			goto ticketnum;
		}
		
		
		//β�巨 
		p->next=NULL;
		r->next=p;
	//	r=r->next;
		r=p;
		
	
		printf("��ӳɹ���\n");
	} 
} 
