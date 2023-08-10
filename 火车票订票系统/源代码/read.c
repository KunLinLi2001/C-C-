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
			
		printf("您确定要读取存档吗？(y/n):");
		
		//ch=getch();//吃掉
		scanf("%s",ch);/////////////////////////////同样不知道为什么用ch有bug emmmmmm 
		
		if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
		return ;
		else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
		{	
			int n=0;
				FILE *fp1;
				fp1=fopen("火车信息.txt","rb");
				if(fp1==NULL)
				{
					printf("“火车信息”文件打开失败\n读取失败！\n");
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
				printf("未发现要导入的火车信息！\n");
				else
				printf("导入了%d个火车信息\n",n);
				fclose(fp1);
				
				xiayibu:
					
					n=0;
					FILE *fp2;
					fp2=fopen("购票信息.txt","rb");
					if(fp2==NULL)
					{
						printf("“购票信息”文件打开失败\n读取失败！\n");
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
					printf("未发现要导入的购票信息！\n");
					else
					printf("导入了%d个购票信息\n",n);
					fclose(fp2);
		}
		else
		{
			printf("判断错误！请检查后重新输入！\n");
			goto lili;
		}
	
}
