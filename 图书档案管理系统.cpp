#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//这是一个图书档案管理系统


struct book
{
	char num[10];//书籍序号
	char name[20];//书名
	char writer[20];//作者
	char publisher[20];//出版社
	int price;//价格
};

int number=0;//定义全局变量,代表图书的数量

void menu()//菜单界面
{
	 puts("\n"); 
		puts("\t|-----------------------------|");
		puts("\t|------------主页-------------|");
		puts("\t|-----------------------------|");
		puts("\t|\t0:退出系统            |");
		puts("\t|\t1:添加书籍信息        |");
		puts("\t|\t2:查询书籍信息        |");
		puts("\t|\t3:将书籍信息排序      |");
		puts("\t|\t4:修改书籍信息        |");
		puts("\t|\t5:删除书籍信息        |");
		puts("\t|\t6:显示所有书籍信息    |"); 
		puts("\t|-----------------------------|");
		printf("\n");
}
/**************************************1:添加书籍信息********************************************************/
void addbook(struct book *s)
{
	char num[10],name[20],writer[20],publisher[20];//待添加的书籍序号、书名、作者、出版社
	int price;//待添加的价格
	printf("请输入书籍的信息：\n");
	printf("书籍序号：");
	scanf("%s",num);//待添加的书籍序号
	printf("书名：");
	scanf("%s",name);//待添加的书名
	printf("作者：");
	scanf("%s",writer);//待添加的作者
	printf("出版社：");
	scanf("%s",publisher);//待添加的出版社
	printf("价格：");
	scanf("%d",&price);//待添加的价格
	strcpy(s[number].num,num);//strcpy为字符串的赋值函数
	strcpy(s[number].name,name);
	strcpy(s[number].writer,writer);
	strcpy(s[number].publisher,publisher);
	s[number].price=price;
	number++;//为了下次添加书做准备 同时标明又多了一本书
}
/**************************************2:查询书籍信息*******************************************************/
void search(struct book *s)
{
	printf("1-通过书籍序号 2-通过书名\n3-通过作者 4-通过出版社\n");
	printf("请选择您的查询方式：");
	int n,i,j=0;
	char tem[20];
	struct book a[20];
	scanf("%d",&n);
	printf("输入您想要查询的信息：");
	scanf("%s",tem);
	
	switch(n)
	{
		case 1:
			for(i=0;i<number;i++)
			{
				if(strcmp(s[i].num,tem)==0)
				{
					a[j]=s[i];
					j++;
				}
			}
			break;
		case 2:
			for(i=0;i<number;i++)
			{
				if(strcmp(s[i].name,tem)==0)
				{
					a[j]=s[i];
					j++;
				}
			}
			break;
		case 3:
			for(i=0;i<number;i++)
			{
				if(strcmp(s[i].writer,tem)==0)
				{
					a[j]=s[i];
					j++;
				}
			}
			break;
		case 4:
			for(i=0;i<number;i++)
			{
				if(strcmp(s[i].publisher,tem)==0)
				{
					a[j]=s[i];
					j++;
				}
			}
			break;
	}
	if(j==0) 
	{
		printf("没有查询到相关信息\n");
		return ;
	}
	
	printf("一共有%d本书籍,具体书籍如下：\n",j);
		printf("|--------------------------------书籍预览----------------------------------|\n");
		printf("|   书籍序号   |     书名     |     作者     |    出版社    |     价格     |\n");
		printf("|--------------|--------------|--------------|--------------|--------------|\n");
		for(i=0;i<j;i++)
		printf("|%-14s|%-14s|%-14s|%-14s|%-14d|\n",s[i].num,s[i].name,s[i].writer,s[i].publisher,s[i].price);
		
}
/**************************************3:将书籍信息排序*****************************************************/
//使用的冒泡排序法  
void bubble1(struct book *s)//字符串从小到大排序
{
	int i,j;
	struct book tem;
	for(i=1;i<number;i++)
	{
		for(j=0;j<number-i;j++)
		{
			if(strcmp(s[j].num,s[j+1].num)>0)
			{
				tem=s[j+1];
				s[j+1]=s[j];
				s[j]=tem;
			}
		}
	}
}
void bubble2(struct book *s)//价格从小到大排序
{
	int i,j;
	struct book tem;
	for(i=1;i<number;i++)
	{
		for(j=0;j<number-i;j++)
		{
			if(s[j].price>s[j+1].price)
			{
				tem=s[j];
				s[j]=s[j+1];
				s[j+1]=tem;
			}
		}
	}
}
void sort(struct book *s)
{	
	printf("1-按照序号 2-按照价格");
	printf("请选择您的排序方式：\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:bubble1(s);break;
		case 2:bubble2(s);break;
	}
	printf("排序成功！\n");
}
//使用的冒泡排序法
/**************************************4:修改书籍信息******************************************************/
void modify(struct book *s)
{
	char num[10],name[20],writer[20],publisher[20];//待修改的书籍序号、书名、作者、出版社
	
	printf("请输入想要修改的书籍序号：");
	char tem[10];
	int i,price;
	
	scanf("%s",tem);
	
	for(i=0;i<number;i++)
	{
		if(strcmp(tem,s[i].num)==0)
		{
			printf("请输入书籍的信息：\n");
			printf("书籍序号：");
			scanf("%s",num);
			
			printf("书名：");
			scanf("%s",name);
			printf("作者：");
			scanf("%s",writer);
			printf("出版社：");
			scanf("%s",publisher);
			printf("价格：");
			scanf("%d",&price);
			strcpy(s[i].num,num);
			strcpy(s[i].name,name);
			strcpy(s[i].writer,writer);
			strcpy(s[i].publisher,publisher);
			s[i].price=price;
			printf("修改成功！\n");
			break;
		}
	}
}
/**************************************5:删除书籍信息 *****************************************************/
void Delete(struct book *s)
{
	int i,j;
	char tem[10];
	printf("输入您想要删除的书的序号：");
	scanf("%s",tem);
	for(i=0;i<number;i++)
	{
		if(strcmp(tem,s[i].num)==0)
		break;//找到了要删除的结点
	}
	if(i==number){
		printf("未找到相关书籍信息\n");
		return ;
	}
	
	for(j=i+1;j<number;j++)
	s[j-1]=s[j];//数组逐个左移（第一个左移的时候i+1就把原来那个i的覆盖了变向删除）
	number--;
	printf("删除成功！\n");
}
/**************************************6:显示书籍信息 *****************************************************/
void showbook(struct book *s)
{
	int i;
	printf("一共有%d本书籍,具体书籍如下：\n",number);
	printf("|--------------------------------书籍预览----------------------------------|\n");
	printf("|   书籍序号   |     书名     |     作者     |    出版社    |     价格     |\n");
	printf("|--------------|--------------|--------------|--------------|--------------|\n");
	for(i=0;i<number;i++)
	printf("|%-14s|%-14s|%-14s|%-14s|%-14d|\n",s[i].num,s[i].name,s[i].writer,s[i].publisher,s[i].price);
}

int main(void)
{
	int n;//n为菜单的选项
	struct book s[50];	//定义结构体数组(指针) 
	while(1)
	{
		menu();//菜单函数
		printf("请输入0~6的数字选择操作内容：");
		scanf("%d",&n);
		system("cls");//清屏
		switch(n)//switch 选择要进行的操作
		{
			case 0:
				printf("感谢您的使用！\nThanks！\n");
				system("pause");
				return 0;
			case 1: addbook(s);break;
			case 2: search(s);break;
			case 3: sort(s);break;
			case 4: modify(s);break;
			case 5: Delete(s);break;
			case 6: showbook(s);break;
			default: printf("请检查信息是否正确！\n");break;
		}
		system("pause");//暂停
		system("cls");//清屏
	}
}
