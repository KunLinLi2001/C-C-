//********************
//      modifyman.c
//********************
#include <stdio.h>
#include "structure.h" 
#include <string.h>
void showman(book *Head,int *a);
void showtrain(node *head,int *a);
void modifyman(node *head,book *Head)
{
	book *p,*q;
	node *r;
	char num[10],ch[2],Num[10],NUM[10],STARTCITY[10],REACHCITY[10],STARTTIME[10],REACHTIME[10];
	int flag=0,*a,booknum,old_booknum,PRICE;
	a=&flag; 
	
	printf("Ŀǰ���еĳ˳�����Ϣ���£�\n");
	showman(Head,a);
	if(flag) return ;
	
	lili:
		
	printf("��ȷ��Ҫ�޸���Ϣ��(y/n):");
	
	scanf("%s",ch);
	
	if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
	return ;
	else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
	{	
		while(1)
		{
			
			haha:
			 
			p=Head->next;
			printf("������Ҫ�޸ĵĳ�Ʊ���(0-�˳�):"); 
			scanf("%s",num);
			if(strcmp(num,"0")==0) return;
			while(p!=NULL)
			{
				if(strcmp(p->Num,num)==0)
			    {
					printf("������ĵĻ���Ϣ\n"); 
					
                    //�������while(1)�������������޸ĵĳ�Ʊ��ź�ԭ�����еĳ�Ʊ�����ͬ�ظ������⣡���� 
					while(1)
					{	
					    huhu:
					    	
						printf("��Ʊ���(0-������һ��)��");
						scanf("%s",Num);
						if(strcmp(Num,"0")==0)
						{
							printf("\n");
							goto haha; 
						}
						q=Head->next;
						while(q!=NULL)
						{
							if(strcmp(Num,q->Num)==0&&strcmp(Num,num)!=0)
							{
								printf("�˳�Ʊ����Ѵ��ڣ����������룡\n");
								goto huhu;
							}
							q=q->next;
						}
						if(q==NULL)//˵�����޸ĵĳ�Ʊ��ź���ʷ�汾û�г�ͻ
						{
							strcpy(p->Num,num);
							break;
						} 
					}
					//�������while(1)�������������޸ĵĳ�Ʊ��ź�ԭ�����еĳ�Ʊ�����ͬ�ظ������⣡���� 

					char ID[20];
					id:
					printf("���֤��(0-������һ��):");
					scanf("%s",ID); 
					if(strcmp(ID,"0")==0)
					{
						printf("\n");
						goto huhu;
					}
				
					
					char NAME[10];
					name:
					printf("����(0-������һ��):");
					scanf("%s",NAME); 
					if(strcmp(NAME,"0")==0)
					{
						printf("\n");
						goto id;
					}

					
					printf("Ŀǰ���п��޸ĳɵĳ�Ʊ��Ϣ���£�\n");
						showtrain(head,a);
						if(flag) return ;
						
					hhhhh:
						
					r=head->next;
					printf("���д�(0-������һ��):");
					scanf("%s",num); 
					if(strcmp(num,"0")==0)
					{
						printf("\n");
						goto name;
					}
					
					while(r!=NULL)
					{
						if(strcmp(r->num,num)==0)
						{
							strcpy(NUM,num);
							break;
						}
						r=r->next;
					}
					if(r==NULL)
					{
						printf("û����ػ��дΣ�������������룡\n");
						goto hhhhh;
					}
					
					
					
					strcpy(STARTCITY,r->startcity);
					strcpy(REACHCITY,r->reachcity);
					strcpy(STARTTIME,r->starttime);
					strcpy(REACHTIME,r->reachtime);
					PRICE=r->price;
					printf("��صĳ������С�������С�����ʱ�䡢��վʱ�䡢��Ʊ�۾���ͬ�����\n");
					
					
					
					kun:	
					printf("����Ʊ��(-1-������һ��):"); 
					scanf("%d",&booknum);
					if(booknum<0)
					{
						if(booknum==-1)
						{
							printf("\n");
							goto hhhhh;
						}
						printf("����Ʊ������Ϊ������\n\n");
						goto kun;
					}
					if(booknum>r->ticketnum+p->booknum)
					{
						printf("Ʊ�Ѳ��㣡������ѡ��Ʊ��\n\n");
						goto kun; 
					}
					old_booknum=p->booknum;//�����޸�ǰ����Ʊ��
					p->booknum=booknum;
					r->ticketnum=r->ticketnum+old_booknum-booknum;
					strcpy(p->id,ID);
					strcpy(p->name,NAME);
					strcpy(p->num,NUM);
					strcpy(p->startcity,STARTCITY);
					strcpy(p->reachcity,REACHCITY);
					strcpy(p->starttime,STARTTIME);
					strcpy(p->reachtime,REACHTIME);
					p->price=PRICE;
					
					printf("�޸ĳɹ���\n");
					break; 
				}
				p=p->next;
			}
			if(p==NULL)//�����Ѿ�������ĩβ�� 
			{
				printf("δ��ѯ���йع�Ʊ��Ϣ��������������롣\n\n");
				continue;
			}
		}
	}
	else
	{
		printf("�жϴ���������������룡\n\n");
		goto lili;
	}
} 
