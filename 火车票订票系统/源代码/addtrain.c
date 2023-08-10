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
	//遍历链表到尾部以便后续尾插 
	while(r->next!=NULL)
	r=r->next;
	
	while(1)
	{
		kunkun://goto语句标记的地点
		 
		printf("请输入车次号(0-退出):"); 
		scanf("%s",num);
		if(strcmp(num,"0")==0)
		{
			printf("\n添加结束！\n");
			break;
		}
		//每一次遍历前都将链表返回头部 
		s=head->next;
		
		//遍历判断是否已存在 
		while(s)
		{
			if(strcmp(s->num,num)==0)
			{
				printf("车次号%s已存在，请重新输入！\n\n",num);
				goto kunkun;//如果有重复的，就直接跳回最外循环的最初 “kunkun” 
			}//goto语句不提倡用，但在这里直接完成了break+continue两次操作 
			s=s->next;
		}//***一开始有关于嵌套循环用break/continue时出现了bug 
		//输入要插入的新信息 
		p=(node *)malloc(sizeof(node));
		strcpy(p->num,num);
		printf("输入火车信息\n"); 
		
		startcity:
		printf("出发城市(0-返回上一级):");
		scanf("%s",p->startcity); 
		if(strcmp(p->startcity,"0")==0)
		{
			printf("\n");
			goto kunkun;			
		}
		
		reachcity:			
		printf("到站城市(0-返回上一级):");
		scanf("%s",p->reachcity);  
		if(strcmp(p->reachcity,"0")==0)
		{
			printf("\n");
			goto startcity;
		}
		
		
		starttime:
		printf("出发时间(0-返回上一级):"); 
		scanf("%s",p->starttime);
		if(strcmp(p->starttime,"0")==0)
		{
			printf("\n");
			goto reachcity;
		}
		
		
		
		reachtime:
		printf("到站时间(0-返回上一级):"); 
		scanf("%s",p->reachtime);
		if(strcmp(p->reachtime,"0")==0)
		{
			printf("\n");
			goto starttime;
		}
		
		
		price:
		printf("火车票价(-1-返回上一级):"); 
		scanf("%d",&p->price);
		if(p->price==-1)
		{
			printf("\n");
			goto reachtime;
		}
		
		if(p->price<0)
		{
			printf("火车票价不能为负数！\n\n");
			goto price;
		}
		
		ticketnum:
		printf("剩余票数(-1-返回上一级):"); 
		scanf("%d",&p->ticketnum);
		if(p->ticketnum==-1)
		{
			printf("\n");
			goto price;
		}
		
		if(p->ticketnum<0)
		{
			printf("票数不能为负数！\n\n");
			goto ticketnum;
		}
		
		
		//尾插法 
		p->next=NULL;
		r->next=p;
	//	r=r->next;
		r=p;
		
	
		printf("添加成功！\n");
	} 
} 
