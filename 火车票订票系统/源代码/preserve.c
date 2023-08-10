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
	a=&flag;//flag为了判断火车链表是否为空的 
	
	node *p=head->next;
	book *q=Head,*ren,*r=Head;
	
	printf("目前所有的车票信息如下：\n");
	showtrain(head,a);//调用showtrain展示所有火车 
	if(flag) return;//flag=1代表没有火车信息 
	
	 
	
	
	while(1)
	{
			
			lalala:
			
			i=0;
			printf("输入要去的城市(0-退出)：");
			scanf("%s",city);
			if(strcmp(city,"0")==0)
			return ;
			
			p=head->next;//每次都要重新把链表放到头部来遍历
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
				printf("没有对应的火车票信息！请检查后重新输入\n\n");
				goto lalala;
			}
			printf("相关的火车票如下\n");
			printf("|------------------------车票预览------------------------------|\n");
			printf("|火车列次|出发城市|到达城市|出发时间|到站时间|火车票价|剩余票数|\n");
			printf("|--------|--------|--------|--------|--------|--------|--------|\n");
			for(j=0;j<i;j++)
			printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			
			ning:
				
			printf("您要预订车票吗？(y/n)(0-返回上一级)\n");
			
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
				printf("请输入人的信息：\n");
				
				Num:	
				printf("订单序号(0-返回上一级)：");
				scanf("%s",Num);
				if(strcmp(Num,"0")==0)
				{
					printf("\n");
					goto ning;//58行
				}
				
				r=Head->next;
				while(r!=NULL)
				{
					if(strcmp(r->Num,Num)==0)
					{
						printf("序号已存在！请重新输入！\n\n");
						goto aa;
					}

					r=r->next;
				} 
				
				ren=(book *)malloc(sizeof(book));//临时添加的人的结构体 
				
				strcpy(ren->Num,Num);
				
				id:
				printf("身份证号(0-返回上一级)：");
				scanf("%s",ren->id);				
				if(strcmp(ren->id,"0")==0)
				{
					printf("\n");
					goto Num;
				}		
				
				
				name:
				printf("姓名(0-返回上一级)：");
				scanf("%s",ren->name);
				if(strcmp(ren->name,"0")==0)
				{
					printf("\n");
					goto id;
				}
				
				kun:
				
				printf("选择要预定的车次(0-返回上一级)：");
				scanf("%s",ren->num);
				if(strcmp(ren->num,"0")==0)
				{
					printf("\n");
					goto name;
				}
				
				while(q->next!=NULL)
				q=q->next;//把存储人信息的链表遍历到尾端
				
				for(j=0;j<i;j++)
				{
					if(strcmp(ren->num,s[j]->num)==0)
					{	
						booknum:
						printf("请输入要预定的票数(-1-返回上一级)：");
						scanf("%d",&ren->booknum);
						if(ren->booknum==-1)
						{
							printf("\n");
							goto kun;
						}
						if(ren->booknum<0)
						{
							printf("票数不能为负数！\n\n");
							goto booknum;
						}
						if(s[j]->ticketnum - ren->booknum<0)
						{
							printf("票已不足！请重新选择\n\n");
							goto booknum; 
						}
						s[j]->ticketnum -= ren->booknum;
						strcpy(ren->startcity,s[j]->startcity);
						strcpy(ren->reachcity,s[j]->reachcity);
						strcpy(ren->starttime,s[j]->starttime);
						strcpy(ren->reachtime,s[j]->reachtime);
						ren->price=s[j]->price;
						
						//人员链表尾插
						ren->next=NULL;
						q->next=ren;
						q=ren;
						break;
					}
					
				}
				if(j==i)
				{
					printf("未查询到相关车次！请重新选择\n\n");
					goto kun; 
				}
				//free(ren);
			}
			else
			{
				printf("判断错误！请重新输入！\n\n");
				goto ning;
			}
			printf("预订成功！\n\n");
	}
}
