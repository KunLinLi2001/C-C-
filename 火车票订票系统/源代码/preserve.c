//********************
//     preserve.c
//********************
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include <string.h>
void showtrain(node *head,int *a);
void preserve(node *head,book *Head)
{
	node *s[10];
	char city[10],ch[2],Num[5];
	int i=0,j,flag=0,*a;
	a=&flag;//flagΪ���жϻ������Ƿ�Ϊ�յ� 
	
	node *p=head->next;
	book *q=Head,*ren,*r=Head;
	
	printf("Ŀǰ���еĳ�Ʊ��Ϣ���£�\n");
	showtrain(head,a);//����showtrainչʾ���л� 
	if(flag) return;//flag=1����û�л���Ϣ 
	
	 
	
	
	while(1)
	{
			
			lalala:
			
			i=0;
			printf("����Ҫȥ�ĳ���(0-�˳�)��");
			scanf("%s",city);
			if(strcmp(city,"0")==0)
			return ;
			
			p=head->next;//ÿ�ζ�Ҫ���°�����ŵ�ͷ��������
			while(p!=NULL)
			{
				if(strcmp(city,p->reachcity)==0)
				{
					s[i]=p;
					i++;
				}
				p=p->next;
			}
			if(i==0)
			{
				printf("û�ж�Ӧ�Ļ�Ʊ��Ϣ���������������\n\n");
				goto lalala;
			}
			printf("��صĻ�Ʊ����\n");
			printf("|------------------------��ƱԤ��------------------------------|\n");
			printf("|���д�|��������|�������|����ʱ��|��վʱ��|��Ʊ��|ʣ��Ʊ��|\n");
			printf("|--------|--------|--------|--------|--------|--------|--------|\n");
			for(j=0;j<i;j++)
			printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			
			ning:
				
			printf("��ҪԤ����Ʊ��(y/n)(0-������һ��)\n");
			
			scanf("%s",ch);
			if(strcmp(ch,"0")==0)
			{
				printf("\n");
				goto lalala;
			}
			
			
			if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
			return ;
			
			else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
			{
				
				aa:					
				printf("�������˵���Ϣ��\n");
				
				Num:	
				printf("�������(0-������һ��)��");
				scanf("%s",Num);
				if(strcmp(Num,"0")==0)
				{
					printf("\n");
					goto ning;//58��
				}
				
				r=Head->next;
				while(r!=NULL)
				{
					if(strcmp(r->Num,Num)==0)
					{
						printf("����Ѵ��ڣ����������룡\n\n");
						goto aa;
					}

					r=r->next;
				} 
				
				ren=(book *)malloc(sizeof(book));//��ʱ��ӵ��˵Ľṹ�� 
				
				strcpy(ren->Num,Num);
				
				id:
				printf("���֤��(0-������һ��)��");
				scanf("%s",ren->id);				
				if(strcmp(ren->id,"0")==0)
				{
					printf("\n");
					goto Num;
				}		
				
				
				name:
				printf("����(0-������һ��)��");
				scanf("%s",ren->name);
				if(strcmp(ren->name,"0")==0)
				{
					printf("\n");
					goto id;
				}
				
				kun:
				
				printf("ѡ��ҪԤ���ĳ���(0-������һ��)��");
				scanf("%s",ren->num);
				if(strcmp(ren->num,"0")==0)
				{
					printf("\n");
					goto name;
				}
				
				while(q->next!=NULL)
				q=q->next;//�Ѵ洢����Ϣ�����������β��
				
				for(j=0;j<i;j++)
				{
					if(strcmp(ren->num,s[j]->num)==0)
					{	
						booknum:
						printf("������ҪԤ����Ʊ��(-1-������һ��)��");
						scanf("%d",&ren->booknum);
						if(ren->booknum==-1)
						{
							printf("\n");
							goto kun;
						}
						if(ren->booknum<0)
						{
							printf("Ʊ������Ϊ������\n\n");
							goto booknum;
						}
						if(s[j]->ticketnum - ren->booknum<0)
						{
							printf("Ʊ�Ѳ��㣡������ѡ��\n\n");
							goto booknum; 
						}
						s[j]->ticketnum -= ren->booknum;
						strcpy(ren->startcity,s[j]->startcity);
						strcpy(ren->reachcity,s[j]->reachcity);
						strcpy(ren->starttime,s[j]->starttime);
						strcpy(ren->reachtime,s[j]->reachtime);
						ren->price=s[j]->price;
						
						//��Ա����β��
						ren->next=NULL;
						q->next=ren;
						q=ren;
						break;
					}
					
				}
				if(j==i)
				{
					printf("δ��ѯ����س��Σ�������ѡ��\n\n");
					goto kun; 
				}
				//free(ren);
			}
			else
			{
				printf("�жϴ������������룡\n\n");
				goto ning;
			}
			printf("Ԥ���ɹ���\n\n");
	}
}
