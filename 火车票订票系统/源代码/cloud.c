//********************
//      cloud.c
//********************
#include <stdio.h>
#include <string.h>
#include "structure.h"
#include <stdlib.h>
void cloud(node *head,book *Head)
{	
	char ch[10];
	lili:

	printf("��ȷ��Ҫͬ��������Ϣ��(y/n):");
		
		//ch=getch();//�Ե�
		scanf("%s",ch);/////////////////////////////ͬ����֪��Ϊʲô��ch��bug emmmmmm 
		
		if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
		return ;
		else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
		{	
			FILE *fp1,*fp2;
				node *p;
				int n=0; 
				p=head->next;
				fp1=fopen("����Ϣ.txt","wb");
				if(fp1==NULL)
				{
					printf("������Ϣ���ļ���ʧ��\n����ʧ�ܣ�\n");
					goto lala;
				}
				
				if(p==NULL)
				{
					printf("û�л���Ϣ��\n");	
					fclose(fp1);
					goto lala ;
				}
			
				
				while(p!=NULL)
				{
					fwrite(p,sizeof(node),1,fp1);
					n++; 
					p=p->next;
				}
				
				fclose(fp1); 
				printf("�ɹ�������%d������Ϣ��\n",n);
				
				lala:				
				n=0; 
				book *q;
				fp2=fopen("��Ʊ��Ϣ.txt","wb");
				if(fp2==NULL)
				{
					printf("����Ʊ��Ϣ���ļ���ʧ��\n����ʧ�ܣ�\n");
					if(fp1!=NULL)
					fclose(fp1);
					return ;
				}
				q=Head->next;
					if(q==NULL)
					{
						printf("û�й�Ʊ��Ϣ��\n");	
						return ;
					}
			
					while(q!=NULL)
					{
						fwrite(q,sizeof(book),1,fp2);
						n++; 
						q=q->next;
					}
					fclose(fp2); 
					printf("�ɹ�������%d����Ʊ��Ϣ��\n",n);
		}
		else
		{
			printf("�жϴ���������������룡\n");
			goto lili;
		}
		
	
}
