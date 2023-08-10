#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>//排序算法
struct student
{
	char num[20];
	char name[20];
	char Class[20];
	double a;
	double b;
	double c;
};
typedef struct student student;
int to_average(student s1,student s2)
{
	double a1,a2;
	a1=(s1.a+s1.b+s1.c)/3;
	a2=(s2.a+s2.b+s2.c)/3;
	if(a1<a2) return 1;
	return 0;
}
int to_class(student s1,student s2)
{
	if(strcmp(s1.Class,s2.Class)<0)
	return 1;
	return 0;
}
student s[50];//声明一个全局结构数组，这样在调用函数的时候可以减少传参。
int sum=0;//学生总数
void menu()
{
	puts("1-输入学生信息");
	puts("2-显示所有学生信息");
	puts("3-根据学号查询学生信息");
	puts("4-根据姓名查询学生信息");
	puts("5-根据班级查询学生信息");
	puts("6-添加一条学生信息");
	puts("7-计算总分和平均分并写入文件");
	puts("8-计算每门课程的平均分并写入文件");
	puts("9-计算每个班级的每门课程的平均分");
	puts("10-查询平均分最高的学生");
	puts("11-查询每个班平均分最高的学生");
	puts("12-按照学号查询删除学生信息");
	puts("13-按照平均分大小进行排序");
	puts("14-按照学号查询修改学生信息");
	puts("0-退出程序");
	puts("请输入您的选项：");
}
void save_student()//把学生信息保存到文件里
{
	FILE *fp;
	fp=fopen("StudentMessage.txt","wb");
	if(fp==NULL)
	{
		puts("文件打开失败！");
		return;
	}
	int i;
	student *tem=(student *)malloc(sizeof(student));
	for(i=0;i<sum;i++)
	{
		tem=&s[i];
		fwrite(tem,sizeof(student),1,fp);	
	}
	printf("保存成功！\n");
	fclose(fp);
}
void read_student()//从文件读取学生信息
{
	FILE *fp;
	student *tem=(student *)malloc(sizeof(student));
	fp=fopen("StudentMessage.txt","rb");
	if(fp==NULL)
	{
		puts("文件打开失败！");
		return ;
	}
	while(!feof(fp))
	{
		if(fread(tem,sizeof(student),1,fp)==1)
		{
			s[sum]=*tem;
			sum++;
		}
	}
	printf("成功读取了%d条信息\n",sum);
	fclose(fp);
}
void createstudent()
{
	printf("请输入学生的数量：");
	scanf("%d",&sum);
	int i;
	puts("请输入学生的信息：");
	for(i=0;i<sum;i++)
	{
		printf("第%d位学生的信息：\n",i+1);
		printf("学号：");
		scanf("%s",s[i].num);
		printf("姓名：");
		scanf("%s",s[i].name);
		printf("班级：");
		scanf("%s",s[i].Class);
		printf("语文成绩：");
		scanf("%lf",&s[i].a);
		printf("数学成绩：");
		scanf("%lf",&s[i].b);
		printf("英语成绩：");
		scanf("%lf",&s[i].c);		
	}
	puts("添加结束！");
	save_student();
}
int have_or_not()//判断是否已经有了学生信息
{
	if(!sum)
	{
		printf("目前没有学生信息！\n");
		return 0;
	}
	return 1;
}
void showstudents()
{
	if(!have_or_not()) return;
	int i;
	printf("目前有%d名学生，具体信息如下：\n",sum);
	printf("|--------------------------------信息预览------------------------------------|\n");
	printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	for(i=0;i<sum;i++)
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i].num,s[i].name,s[i].Class,s[i].a,s[i].b,s[i].c,(s[i].a+s[i].b+s[i].c)/3);
	puts("展示结束！");
}
void search(int sec)
{
	int i,j=0;
	student temp[50];
	char com[20];
	printf("请输入想要查询的信息关键词：");
	char tem[20];
	scanf("%s",tem);
	for(i=0;i<sum;i++)
	{
		switch(sec)
		{
			case 1:strcpy(com,s[i].num);break;//学号
			case 2:strcpy(com,s[i].name);break;//姓名
			case 3:strcpy(com,s[i].Class);break;//班级
		}
		if(strcmp(com,tem)==0)
		{
			temp[j]=s[i];
			j++;
		}
	}
	if(j==0)
	{
		printf("没有找到相关的信息！\n");
		return;
	}
	printf("查询到了%d条学生信息\n具体如下\n",j);
	printf("|--------------------------------信息预览------------------------------------|\n");
	printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	for(i=0;i<j;i++)
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",temp[i].num,temp[i].name,temp[i].Class,temp[i].a,temp[i].b,temp[i].c,(temp[i].a+temp[i].b+temp[i].c)/3);
	puts("查询结束！");
}
void addstudent()
{
	printf("目前已有%d条学生信息\n",sum);
	printf("请输入第%d位学生的信息:\n",sum+1);
	printf("学号：");
	scanf("%s",s[sum].num);
	printf("姓名：");
	scanf("%s",s[sum].name);
	printf("班级：");
	scanf("%s",s[sum].Class);
	printf("语文成绩：");
	scanf("%lf",&s[sum].a);
	printf("数学成绩：");
	scanf("%lf",&s[sum].b);
	printf("英语成绩：");
	scanf("%lf",&s[sum].c);	
	puts("添加结束！\n");
	sum++;
	save_student();		
}
void modifystudent()
{
	int i;
	char num[20];
	if(!have_or_not()) return;
	while(1)
	{
		printf("请输入要修改的学生学号(0-退出)：");
		scanf("%s",num);
		if(strcmp(num,"0")==0)
		{
			puts("修改结束！");
			break;
		}
		for(i=0;i<sum;i++)
		{
			if(strcmp(num,s[i].num)==0)
			{
				printf("|--------------------------------信息预览------------------------------------|\n");
				printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
				printf("|----------|----------|----------|----------|----------|----------|----------|\n");	
				printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i].num,s[i].name,s[i].Class,s[i].a,s[i].b,s[i].c,(s[i].a+s[i].b+s[i].c)/3);	
				printf("请输入要修改成的信息\n");
				printf("学号：");
				scanf("%s",s[i].num);
				printf("姓名：");
				scanf("%s",s[i].name);
				printf("班级：");
				scanf("%s",s[i].Class);
				printf("语文成绩：");
				scanf("%lf",&s[i].a);
				printf("数学成绩：");
				scanf("%lf",&s[i].b);
				printf("英语成绩：");
				scanf("%lf",&s[i].c);	
				puts("修改成功！\n");
				break;
			}
		}
		if(i==sum)
		{
			printf("没有相关学生信息，请检查后重新输入！\n");
			continue;
		}		
	}
	save_student();
}
void total_and_average()
{
	FILE *fp;
	fp=fopen("Totalandaverage.txt","w");
	if(fp==NULL)
	{
		printf("文件打开失败！\n");
		return;
	}
	int i;
	char ch[]=" ",sh='\n';
	fputs("顺序为：学号、姓名、班级、三门课成绩、总分、平均成绩",fp);
	fputs("\n",fp);
	for(i=0;i<sum;i++)
	{
		fputs(s[i].num,fp);
		fputs(ch,fp);
		fputs(s[i].name,fp);
		fputs(ch,fp);
		fputs(s[i].Class,fp);
		fputs(ch,fp);
		double Sum=s[i].a+s[i].b+s[i].c;
		double average=Sum/3.0;
		fprintf(fp,"%.2f",s[i].a);
		fputs(ch,fp);
		fprintf(fp,"%.2f",s[i].b);
		fputs(ch,fp);
		fprintf(fp,"%.2f",s[i].c);
		fputs(ch,fp);
		fprintf(fp,"%.2f",Sum);
		fputs(ch,fp);	
		fprintf(fp,"%.2f",average);
		fputs(ch,fp);
		fputc(sh,fp);	
	}
	puts("计算保存成功！\n请在文件中查看具体内容");
	fclose(fp);
}
void course_average()
{
	FILE *fp;
	fp=fopen("courseAverage.txt","w");
	if(fp==NULL)
	{
		printf("文件打开失败！\n");
		return;
	}
	int i;
	double aa=0,bb=0,cc=0;
	for(i=0;i<sum;i++)
	{
		aa+=s[i].a;
		bb+=s[i].b;
		cc+=s[i].c;
	}
	aa/=sum;
	bb/=sum;
	cc/=sum;
	fputs("语文平均分为：",fp);
	fprintf(fp,"%.2f",aa);
	fputs("\n",fp);
	fputs("数学平均分为：",fp);
	fprintf(fp,"%.2f",bb);
	fputs("\n",fp);
	fputs("英语平均分为：",fp);
	fprintf(fp,"%.2f",cc);
	fputs("\n",fp);	
	puts("计算保存成功！\n请在文件中查看具体内容");
	fclose(fp);	
}
void max_average()
{
	student s1[50];
	int i;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_average);
//	printf("目前有%d名学生，具体信息如下：\n",sum);
//	printf("|--------------------------------信息预览------------------------------------|\n");
//	printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
//	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
//	for(i=0;i<sum;i++)
//	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i].num,s1[i].name,s1[i].Class,s1[i].a,s1[i].b,s1[i].c,(s1[i].a+s1[i].b+s1[i].c)/3);
//	puts("展示结束！");
	puts("平均分最高的同学信息如下：");
	printf("|--------------------------------信息预览------------------------------------|\n");
	printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i-1].num,s1[i-1].name,s1[i-1].Class,s1[i-1].a,s1[i-1].b,s1[i-1].c,(s1[i-1].a+s1[i-1].b+s1[i-1].c)/3);
}
void sort_average()
{
	FILE *fp;
	fp=fopen("SortbyAverage.txt","w");
	if(fp==NULL)
	{
		puts("文件打开失败！");
		return ;
	}
	student s1[50];
	int i;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_average);
	fputs("|--------------------------------信息预览------------------------------------|\n",fp);
	fputs("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n",fp);
	fputs("|----------|----------|----------|----------|----------|----------|----------|\n",fp);
	for(i=0;i<sum;i++)
	fprintf(fp,"|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i].num,s1[i].name,s1[i].Class,s1[i].a,s1[i].b,s1[i].c,(s1[i].a+s1[i].b+s1[i].c)/3);	
	fclose(fp);
	puts("计算保存成功！\n请在文件中查看具体内容");
}
void delete_student()
{
	while(1)
	{
		int i,j;
		char tem[10];
		printf("输入您想要删除的学生的学号(0-退出)：");
		scanf("%s",tem);
		if(strcmp(tem,"0")==0)
		break;
		for(i=0;i<sum;i++)
		{
			if(strcmp(tem,s[i].num)==0)
			break;//找到了要删除的结点
		}
		if(i==sum){
			printf("未找到相关学生信息\n请重新输入");
			continue;
		}
		for(j=i+1;j<sum;j++)
		s[j-1]=s[j];//数组逐个左移（第一个左移的时候i+1就把原来那个i的覆盖了变向删除）
		sum--;
		printf("删除成功！\n");
	}
	save_student();
}
void max_class_average()
{
	student s1[50];
	int i,j,k;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_class);
	student s[10][20];
	j=0;k=1;
	s[0][0]=s1[0];
	for(i=1;i<sum;i++)
	{
		if(strcmp(s1[i].Class,s1[i-1].Class)!=0)//和上一个的班级不一样 就j++存储下一行学生信息
		//同一行的学生信息的班级是一样的
		{
			strcpy(s[j][k].num,"NULL");//换行前把每一行增加一个中止提示符
			k=0;
			j++;
		}
		s[j][k]=s1[i];//把所有的学生分到不同行的二维数组里
		k++;
	}
	strcpy(s[j][k].num,"NULL");
//	k=0;i=0;
	//最后记录有j+1个班级
//	for(i=0;i<=j;i++)   //输出检验
//	{
//		for(k=0;strcmp(s[i][k].num,"NULL")!=0;k++)
//		printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i][k].num,s[i][k].name,s[i][k].Class,s[i][k].a,s[i][k].b,s[i][k].c,(s[i][k].a+s[i][k].b+s[i][k].c)/3);
//	}
	//以上操作成功把相同班级的学生信息放在同一行（二维数组）矩阵里
	student max;
	puts("每个班级平均分最高的同学的信息如下：");
	printf("|--------------------------------信息预览------------------------------------|\n");
	printf("|   学号   |   姓名   |   班级   | 语文成绩 | 数学成绩 | 英语成绩 | 平均成绩 |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");	
	for(i=0;i<=j;i++)
	{
		max=s[i][0];
		for(k=1;strcmp(s[i][k].num,"NULL")!=0;k++)
		{
			if((max.a+max.b+max.c)<(s[i][k].a+s[i][k].b+s[k][0].c))
			max=s[i][k];
		}
		printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",max.num,max.name,max.Class,max.a,max.b,max.c,(max.a+max.b+max.c)/3);
	}
}
void course_class_average()
{
	FILE *fp;
	fp=fopen("courseAverageofClass.txt","w");
	if(fp==NULL)
	{
		printf("文件打开失败！\n");
		return ;
	}
	fputs("顺序为：班级、语文平均成绩、数学平均成绩、英语平均成绩",fp);
	fputs("\n",fp);
	student s1[50];
	int i,j,k;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_class);
	student s[10][20];
	j=0;k=1;
	s[0][0]=s1[0];
	for(i=1;i<sum;i++)
	{
		if(strcmp(s1[i].Class,s1[i-1].Class)!=0)//和上一个的班级不一样 就j++存储下一行学生信息
		//同一行的学生信息的班级是一样的
		{
			strcpy(s[j][k].num,"NULL");//换行前把每一行增加一个中止提示符
			k=0;
			j++;
		}
		s[j][k]=s1[i];//把所有的学生分到不同行的二维数组里
		k++;
	}
	strcpy(s[j][k].num,"NULL");
	//	k=0;i=0;
		//最后记录有j+1个班级
	//	for(i=0;i<=j;i++)   //输出检验
	//	{
	//		for(k=0;strcmp(s[i][k].num,"NULL")!=0;k++)
	//		printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i][k].num,s[i][k].name,s[i][k].Class,s[i][k].a,s[i][k].b,s[i][k].c,(s[i][k].a+s[i][k].b+s[i][k].c)/3);
	//	}
	//以上操作成功把相同班级的学生信息放在同一行（二维数组）矩阵里
	student ss;
	for(i=0;i<=j;i++)
	{
		strcpy(ss.Class,s[i][0].Class);
		ss.a=0;ss.b=0;ss.c=0;
		for(k=0;strcmp(s[i][k].num,"NULL")!=0;k++)
		{
			ss.a+=s[i][k].a;
			ss.b+=s[i][k].b;
			ss.c+=s[i][k].c;
		}
		ss.a/=k;ss.b/=k;ss.c/=k;
		fputs(ss.Class,fp);
		fputs(" ",fp);
		fprintf(fp,"%.2f",ss.a);
		fputs(" ",fp);
		fprintf(fp,"%.2f",ss.b);
		fputs(" ",fp);
		fprintf(fp,"%.2f",ss.c);
		fputs("\n",fp);		
	}
	fclose(fp);
	puts("计算保存成功！\n请在文件中查看具体内容");
}
int main()
{ 
	int cls;
	while(1)
	{
		if(!sum)//一开始就读取一下文件里的信息
		read_student();
		menu();
		scanf("%d",&cls);
		system("cls");
		switch(cls)
		{
			case 0: printf("感谢您的使用\nThanks\n");system("pause");return 0;
			case 1: createstudent();break;
			case 2: showstudents();break;
			case 3: search(1);break;
			case 4: search(2);break;
			case 5: search(3);break;
			case 6: addstudent();break;
			case 7: total_and_average();break;
			case 8: course_average();break;
			case 9: course_class_average();break;
			case 10: max_average();break;
			case 11: max_class_average();break;
			case 12: delete_student();break;
			case 13: sort_average();break;
			case 14: modifystudent();break;
		}
		system("pause");
		system("cls");
	}
}
