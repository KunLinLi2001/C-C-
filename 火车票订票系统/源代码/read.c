//********************
//      read.c
//********************
#include <stdio.h> 
#include <string.h>
#include "structure.h" 
#include <stdlib.h>
void read(node *head,book *Head)
{
	node *p=head,*q;
	char ch[10];
	lili:
			
		printf("��ȷ��Ҫ��ȡ�浵��(y/n):");
		
		//ch=getch();//�Ե�
		scanf("%s",ch);/////////////////////////////ͬ����֪��Ϊʲô��ch��bug emmmmmm 
		
		if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
		return ;
		else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
		{	
			int n=0;
				FILE *fp1;
				fp1=fopen("����Ϣ.txt","rb");
				if(fp1==NULL)
				{
					printf("������Ϣ���ļ���ʧ��\n��ȡʧ�ܣ�\n");
					goto xiayibu;
				}

				
				while(!feof(fp1))
				{
					q=(node*)malloc(sizeof(node));
					if(fread(q,sizeof(node),1,fp1)==1)
					{
						q->next=NULL;
						p->next=q;
						p=q;
						n++;
					}	
				}
				if(!n)
				printf("δ����Ҫ����Ļ���Ϣ��\n");
				else
				printf("������%d������Ϣ\n",n);
				fclose(fp1);
				
				xiayibu:
					
					n=0;
					FILE *fp2;
					fp2=fopen("��Ʊ��Ϣ.txt","rb");
					if(fp2==NULL)
					{
						printf("����Ʊ��Ϣ���ļ���ʧ��\n��ȡʧ�ܣ�\n");
						if(fp1!=NULL)
						fclose(fp1);
						
						return;
					}
					book *m=Head,*r;
					
					while(!feof(fp2))
					{
						r=(book*)malloc(sizeof(book));
						if(fread(r,sizeof(book),1,fp2)==1)
						{
							r->next=NULL;
							m->next=r;
							m=r;
							n++;
						}
					}
					if(!n)
					printf("δ����Ҫ����Ĺ�Ʊ��Ϣ��\n");
					else
					printf("������%d����Ʊ��Ϣ\n",n);
					fclose(fp2);
		}
		else
		{
			printf("�жϴ���������������룡\n");
			goto lili;
		}
	
}
