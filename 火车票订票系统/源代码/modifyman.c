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
	
	printf("目前所有的乘车人信息如下：\n");
	showman(Head,a);
	if(flag) return ;
	
	lili:
		
	printf("您确定要修改信息吗？(y/n):");
	
	scanf("%s",ch);
	
	if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
	return ;
	else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
	{	
		while(1)
		{
			
			haha:
			 
			p=Head->next;
			printf("输入您要修改的车票序号(0-退出):"); 
			scanf("%s",num);
			if(strcmp(num,"0")==0) return;
			while(p!=NULL)
			{
				if(strcmp(p->Num,num)==0)
			    {
					printf("输入更改的火车信息\n"); 
					
                    //下面这段while(1)完美解决了如果修改的车票序号和原来本有的车票序号相同重复的问题！！！ 
					while(1)
					{	
					    huhu:
					    	
						printf("车票序号(0-返回上一级)：");
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
								printf("此车票序号已存在！请重新输入！\n");
								goto huhu;
							}
							q=q->next;
						}
						if(q==NULL)//说明想修改的车票序号和历史版本没有冲突
						{
							strcpy(p->Num,num);
							break;
						} 
					}
					//上面这段while(1)完美解决了如果修改的车票序号和原来本有的车票序号相同重复的问题！！！ 

					char ID[20];
					id:
					printf("身份证号(0-返回上一级):");
					scanf("%s",ID); 
					if(strcmp(ID,"0")==0)
					{
						printf("\n");
						goto huhu;
					}
				
					
					char NAME[10];
					name:
					printf("姓名(0-返回上一级):");
					scanf("%s",NAME); 
					if(strcmp(NAME,"0")==0)
					{
						printf("\n");
						goto id;
					}

					
					printf("目前所有可修改成的车票信息如下：\n");
						showtrain(head,a);
						if(flag) return ;
						
					hhhhh:
						
					r=head->next;
					printf("火车列次(0-返回上一级):");
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
						printf("没有相关火车列次，请检查后重新输入！\n");
						goto hhhhh;
					}
					
					
					
					strcpy(STARTCITY,r->startcity);
					strcpy(REACHCITY,r->reachcity);
					strcpy(STARTTIME,r->starttime);
					strcpy(REACHTIME,r->reachtime);
					PRICE=r->price;
					printf("相关的出发城市、到达城市、出发时间、到站时间、火车票价均已同步完毕\n");
					
					
					
					kun:	
					printf("购买票数(-1-返回上一级):"); 
					scanf("%d",&booknum);
					if(booknum<0)
					{
						if(booknum==-1)
						{
							printf("\n");
							goto hhhhh;
						}
						printf("购买票数不能为负数！\n\n");
						goto kun;
					}
					if(booknum>r->ticketnum+p->booknum)
					{
						printf("票已不足！请重新选择票数\n\n");
						goto kun; 
					}
					old_booknum=p->booknum;//这是修改前定的票数
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
					
					printf("修改成功！\n");
					break; 
				}
				p=p->next;
			}
			if(p==NULL)//代表已经遍历到末尾了 
			{
				printf("未查询到有关购票信息，请检查后重新输入。\n\n");
				continue;
			}
		}
	}
	else
	{
		printf("判断错误！请检查后重新输入！\n\n");
		goto lili;
	}
} 
