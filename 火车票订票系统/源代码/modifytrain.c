//********************
//      modify.c
//********************
#include <stdio.h>
#include "structure.h" 
#include <string.h>
void showtrain(node *head,int *a);
void modifytrain(node *head)
{
	node *p,*q;
	char num[10],ch[2],Num[10];
	int flag=0,*a;
	a=&flag; 
	
	printf("Ŀǰ���еĳ�Ʊ��Ϣ���£�\n");
	showtrain(head,a);
	if(flag) return ;
	
	lili:
		
	printf("��ȷ��Ҫ�޸���Ϣ��(y/n):");
	
	//ch=getch();//�Ե�
	scanf("%s",ch);
	
	if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
	return ;
	else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
	{	
		while(1)
		{
			
			haha:
			 
			p=head->next;
			printf("������Ҫ�޸ĵĳ��κ�(0-�˳�):"); 
			scanf("%s",num);
			if(strcmp(num,"0")==0) return;
			while(p!=NULL)
			{
				if(strcmp(p->num,num)==0)
			    {
					printf("������ĵĻ���Ϣ\n"); 

					Num:
                    //�������while(1)�������������޸ĵĳ��κź�ԭ�����еĳ��κ���ͬ�ظ������⣡���� 
					while(1)
					{	
					    huhu:
					    	
						printf("���κ�(0-������һ��)��");
						scanf("%s",Num);
						if(strcmp(num,"0")==0) goto haha;
						q=head->next;
						while(q!=NULL)
						{
							if(strcmp(Num,q->num)==0&&strcmp(Num,num)!=0)
							{
								printf("�˳��κ��Ѵ��ڣ����������룡\n");
								goto huhu;
							}
							q=q->next;
						}
						if(q==NULL)
						{
							strcpy(p->num,num);
							break;
						} 
					}
					//�������while(1)�������������޸ĵĳ��κź�ԭ�����еĳ��κ���ͬ�ظ������⣡���� 
					
					startcity:
			    	printf("��������(0-������һ��):");
			    	scanf("%s",p->startcity); 
					if(strcmp(p->startcity,"0")==0)
					{
						printf("\n");
						goto Num;
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
						printf("Ʊ�۲���Ϊ������\n\n");
						goto price;
					}
										
					ticketnum:
					printf("��Ʊ��(-1-������һ��):");
					scanf("%d",&p->ticketnum);
					if(p->ticketnum==-1)
					{
						printf("\n");
						goto price;
					}
					if(p->ticketnum<0)
					{
						printf("��Ʊ������Ϊ������\n\n");
						goto ticketnum;
					}
					
					printf("�޸ĳɹ���\n");
					break; 
				}
				p=p->next;
			}
			if(p==NULL)//�����Ѿ�������ĩβ�� 
			{
				printf("δ��ѯ���йس��Σ�������������롣\n");
				continue;
			}
		}
	}
	else
	{
		printf("�жϴ������������룡\n");
		goto lili;
	}
	
} 
