//********************
//      main.c
//********************

#include <stdio.h>
#include "structure.h"
#include <stdlib.h>
#include <string.h>


int main(void) 
{
	char n[10];
	int flag = 0, *a;
	a = &flag;
	node *head = NULL; //建立火车链表的头部指针
	book *Head = NULL; //建立人火车链表的头指针
	head = (node*)malloc(sizeof(node));
	Head = (book*)malloc(sizeof(book));
	head->next = 0;
	Head->next = NULL;
	//memset将指针内容清零
	//memset(head, 0, sizeof(node));
	//memset(Head,0,sizeof(book));
	Head->next = NULL;
	while (1) {
		flag = 0;
		menu();
		printf("请输入0~9的数字选择操作内容：");
		scanf("%s", n);
		system("cls");
		//printf("\n");
		if(strcmp(n,"0")==0)
		{
			printf("感谢您的使用！\nThanks！\n");
			system("pause");
			return 0;
		}
		else if(strcmp(n,"1")==0)
			addtrain(head);
		else if(strcmp(n,"2")==0)
			searchtrain(head);
		else if(strcmp(n,"3")==0)
			preserve(head, Head);
		else if(strcmp(n,"4")==0)
			modifytrain(head);	
		else if(strcmp(n,"5")==0)
			modifyman(head,Head);	
		else if(strcmp(n,"6")==0)
			showtrain(head, a);
		else if(strcmp(n,"7")==0)
			showman(Head, a);
		else if(strcmp(n,"8")==0)
			read(head,Head);
		else if(strcmp(n,"9")==0)
			cloud(head, Head);
		else
			printf("请检查信息是否正确！\n");
		system("pause");
		system("cls");
	}

}
