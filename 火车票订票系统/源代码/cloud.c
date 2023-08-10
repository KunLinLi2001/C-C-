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

	printf("您确定要同步保存信息吗？(y/n):");
		
		//ch=getch();//吃掉
		scanf("%s",ch);/////////////////////////////同样不知道为什么用ch有bug emmmmmm 
		
		if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
		return ;
		else if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
		{	
			FILE *fp1,*fp2;
				node *p;
				int n=0; 
				p=head->next;
				fp1=fopen("火车信息.txt","wb");
				if(fp1==NULL)
				{
					printf("“火车信息”文件打开失败\n保存失败！\n");
					goto lala;
				}
				
				if(p==NULL)
				{
					printf("没有火车信息！\n");	
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
				printf("成功保存了%d个火车信息！\n",n);
				
				lala:				
				n=0; 
				book *q;
				fp2=fopen("购票信息.txt","wb");
				if(fp2==NULL)
				{
					printf("“购票信息”文件打开失败\n保存失败！\n");
					if(fp1!=NULL)
					fclose(fp1);
					return ;
				}
				q=Head->next;
					if(q==NULL)
					{
						printf("没有购票信息！\n");	
						return ;
					}
			
					while(q!=NULL)
					{
						fwrite(q,sizeof(book),1,fp2);
						n++; 
						q=q->next;
					}
					fclose(fp2); 
					printf("成功保存了%d个购票信息！\n",n);
		}
		else
		{
			printf("判断错误！请检查后重新输入！\n");
			goto lili;
		}
		
	
}
