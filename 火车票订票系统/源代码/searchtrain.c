//********************
//    searchtrain.c
//******************** 
#include <stdio.h> 
#include <string.h>
#include "structure.h"
void searchtrain(node *head)
{
	int n,a,b,i,j;
	node *p,*s[10];
	char num[5],other[10],tem[10];
	
	if(head->next==NULL)
	{
		printf("û�л���Ϣ��\n");
		return ;
	}
	
	
	printf("1.ͨ������     2.ͨ��������\n");
	printf("3.ͨ��Ŀ�ĵ�   4.ͨ������ʱ��\n");
	printf("5.ͨ������ʱ�� 6.ͨ��Ʊ������\n");
	while(1)
	{	
		printf("��ѡ�����Ĳ��ҷ�ʽ(0-�˳�)��");
		p=head->next;
		scanf("%d",&n);
		if(n==0)
		{
			printf("��ѯ������\n");
			return ;
		}
		else if(n==1)
		{
			printf("�����복�κţ�");
			scanf("%s",num);
			while(p!=NULL)
			{
				if(strcmp(num,p->num)==0)
				{
					printf("|------------------------��ƱԤ��------------------------------|\n");
					printf("|���д�|��������|�������|����ʱ��|��վʱ��|��Ʊ��|ʣ��Ʊ��|\n");
					printf("|--------|--------|--------|--------|--------|--------|--------|\n");
					printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->ticketnum);
					break;
				}
				p=p->next;
			}
			if(p==NULL)
			printf("δ��ѯ����س��Σ�\n");
		}
		else if(n>=2&&n<=5)
		{
			i=0;
			printf("�����������Ϣ��");
			scanf("%s",other);
			while(p!=NULL)
			{
				switch(n)
				{
					case 2:
						strcpy(tem,p->startcity);break;//�ԱȺ���������� 
						//tem=p->startcity;break;
					case 3:
						strcpy(tem,p->reachcity);break;
					case 4:
						strcpy(tem,p->starttime);break;
					case 5:
						strcpy(tem,p->reachtime);break;
				}
				
				if(strcmp(other,tem)==0)
				{
					s[i]=p;
					i++;
				}
				p=p->next;
			}
			if(i==0)
			printf("δ��ѯ����س��Σ�\n");
			else
			{
				printf("|------------------------��ƱԤ��------------------------------|\n");
				printf("|���д�|��������|�������|����ʱ��|��վʱ��|��Ʊ��|ʣ��Ʊ��|\n");
				printf("|--------|--------|--------|--------|--------|--------|--------|\n");
				for(j=0;j<i;j++)
				printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			}
		}
		else if(n==6)
		{
			linlin:
				
			i=0;	
			printf("����Ʊ�۵����䣺[a,b]��");
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				printf("��ʽ��������������!\n\n");
				goto linlin;
			}
			printf("Ʊ�۵�����Ϊ[%d,%d]\n",a,b); 
			p=head->next;
			while(p!=NULL)
			{
				if(p->price>=a&&p->price<=b)
				{
					s[i]=p;
					i++;
				}
				p=p->next;
			}
			
			if(i==0)
			printf("δ��ѯ����س��Σ�\n");
			else
			{
				printf("|------------------------��ƱԤ��------------------------------|\n");
				printf("|���д�|��������|�������|����ʱ��|��վʱ��|��Ʊ��|ʣ��Ʊ��|\n");
				printf("|--------|--------|--------|--------|--------|--------|--------|\n");
				for(j=0;j<i;j++)
				printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			}
		}
		else
		printf("���������Ƿ���ȷ��\n\n");
	}
}
