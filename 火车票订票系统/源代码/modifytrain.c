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
	
	printf("目前所有的车票信息如下：\n");
	showtrain(head,a);
	if(flag) return ;
	
	lili:
		
	printf("您确定要修改信息吗？(y/n):");
	
	//ch=getch();//吃掉
	scanf("%s",ch);
	
	if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
	return ;
	else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
	{	
		while(1)
		{
			
			haha:
			 
			p=head->next;
			printf("输入您要修改的车次号(0-退出):"); 
			scanf("%s",num);
			if(strcmp(num,"0")==0) return;
			while(p!=NULL)
			{
				if(strcmp(p->num,num)==0)
			    {
					printf("输入更改的火车信息\n"); 

					Num:
                    //下面这段while(1)完美解决了如果修改的车次号和原来本有的车次号相同重复的问题！！！ 
					while(1)
					{	
					    huhu:
					    	
						printf("车次号(0-返回上一级)：");
						scanf("%s",Num);
						if(strcmp(num,"0")==0) goto haha;
						q=head->next;
						while(q!=NULL)
						{
							if(strcmp(Num,q->num)==0&&strcmp(Num,num)!=0)
							{
								printf("此车次号已存在！请重新输入！\n");
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
					//上面这段while(1)完美解决了如果修改的车次号和原来本有的车次号相同重复的问题！！！ 
					
					startcity:
			    	printf("出发城市(0-返回上一级):");
			    	scanf("%s",p->startcity); 
					if(strcmp(p->startcity,"0")==0)
					{
						printf("\n");
						goto Num;
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
						printf("票价不能为负数！\n\n");
						goto price;
					}
										
					ticketnum:
					printf("火车票数(-1-返回上一级):");
					scanf("%d",&p->ticketnum);
					if(p->ticketnum==-1)
					{
						printf("\n");
						goto price;
					}
					if(p->ticketnum<0)
					{
						printf("火车票数不能为负数！\n\n");
						goto ticketnum;
					}
					
					printf("修改成功！\n");
					break; 
				}
				p=p->next;
			}
			if(p==NULL)//代表已经遍历到末尾了 
			{
				printf("未查询到有关车次，请检查后重新输入。\n");
				continue;
			}
		}
	}
	else
	{
		printf("判断错误！请重新输入！\n");
		goto lili;
	}
	
} 
