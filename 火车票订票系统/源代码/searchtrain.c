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
		printf("没有火车信息！\n");
		return ;
	}
	
	
	printf("1.通过车次     2.通过出发地\n");
	printf("3.通过目的地   4.通过出发时间\n");
	printf("5.通过到达时间 6.通过票价区间\n");
	while(1)
	{	
		printf("请选择您的查找方式(0-退出)：");
		p=head->next;
		scanf("%d",&n);
		if(n==0)
		{
			printf("查询结束！\n");
			return ;
		}
		else if(n==1)
		{
			printf("请输入车次号：");
			scanf("%s",num);
			while(p!=NULL)
			{
				if(strcmp(num,p->num)==0)
				{
					printf("|------------------------车票预览------------------------------|\n");
					printf("|火车列次|出发城市|到达城市|出发时间|到站时间|火车票价|剩余票数|\n");
					printf("|--------|--------|--------|--------|--------|--------|--------|\n");
					printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",p->num,p->startcity,p->reachcity,p->starttime,p->reachtime,p->price,p->ticketnum);
					break;
				}
				p=p->next;
			}
			if(p==NULL)
			printf("未查询到相关车次！\n");
		}
		else if(n>=2&&n<=5)
		{
			i=0;
			printf("请输入相关信息：");
			scanf("%s",other);
			while(p!=NULL)
			{
				switch(n)
				{
					case 2:
						strcpy(tem,p->startcity);break;//对比和下面的区别 
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
			printf("未查询到相关车次！\n");
			else
			{
				printf("|------------------------车票预览------------------------------|\n");
				printf("|火车列次|出发城市|到达城市|出发时间|到站时间|火车票价|剩余票数|\n");
				printf("|--------|--------|--------|--------|--------|--------|--------|\n");
				for(j=0;j<i;j++)
				printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			}
		}
		else if(n==6)
		{
			linlin:
				
			i=0;	
			printf("输入票价的区间：[a,b]：");
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				printf("格式错误！请重新输入!\n\n");
				goto linlin;
			}
			printf("票价的区间为[%d,%d]\n",a,b); 
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
			printf("未查询到相关车次！\n");
			else
			{
				printf("|------------------------车票预览------------------------------|\n");
				printf("|火车列次|出发城市|到达城市|出发时间|到站时间|火车票价|剩余票数|\n");
				printf("|--------|--------|--------|--------|--------|--------|--------|\n");
				for(j=0;j<i;j++)
				printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8d|%-8d|\n",s[j]->num,s[j]->startcity,s[j]->reachcity,s[j]->starttime,s[j]->reachtime,s[j]->price,s[j]->ticketnum);
			}
		}
		else
		printf("请检查数字是否正确！\n\n");
	}
}
