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
	node *head = NULL; //�����������ͷ��ָ��
	book *Head = NULL; //�����˻������ͷָ��
	head = (node*)malloc(sizeof(node));
	Head = (book*)malloc(sizeof(book));
	head->next = 0;
	Head->next = NULL;
	//memset��ָ����������
	//memset(head, 0, sizeof(node));
	//memset(Head,0,sizeof(book));
	Head->next = NULL;
	while (1) {
		flag = 0;
		menu();
		printf("������0~9������ѡ��������ݣ�");
		scanf("%s", n);
		system("cls");
		//printf("\n");
		if(strcmp(n,"0")==0)
		{
			printf("��л����ʹ�ã�\nThanks��\n");
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
			printf("������Ϣ�Ƿ���ȷ��\n");
		system("pause");
		system("cls");
	}

}
