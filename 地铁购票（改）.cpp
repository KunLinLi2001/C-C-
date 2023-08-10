#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int menu();
void INPUT();
void WRITE();
void READ();
void PRINT();
void SEARCH();
void SELECT();
void PRICE();
void WRONG();
struct Subway
{
	char code[10];
	char data[10];
	char lp[10];
	char ap[10];
	char lt[10];
	char at[10];
	char price[10];
}S[10000];
int i=0;
int n=0;
char l[20];
///////////////////////////////////////////////////////////////////////////////////////主函数
int main()
{
	int x;
	do
	{
		x=menu();
		switch(x)
		{
		case 1:INPUT(); break;
		case 2:SEARCH(); break;
		case 3:PRICE(); break;
		case 4:SELECT(); break;
		case 5:
			system("cls");
			printf("\n                                正在退出，请按任意键退出");
			printf("\n\n                                ");
			break;
		default:WRONG(); break;
		}
	}while(x!=5);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////菜单模块
int menu()
{
	int choice;
	system("cls");
printf("                                                                   \n");
printf("                                                                   \n");
printf("                                                                   \n");
printf("                            欢迎进入厦门地铁票务系统               \n");
printf("                        Welcome to Xiamen Subway System            \n");
printf("                                                                   \n");
printf("                                                                   \n");
	   printf("\n\n");
printf("                                 输入选项                        \n");
printf("                            1.录入新线路、站点信息               \n");
printf("                            2.查询线路及站点信息                 \n");
printf("                            3.查询票价                           \n");
printf("                            4.统计列车时刻及车次信息             \n");
printf("                            5.退出                               \n");
printf("                                                                 \n");
printf("                                   请选择： ");
    scanf("%d",&choice);
	return choice;
}
/////////////////////////////////////////////////////////////////////////////////////////////////输入模块
void INPUT()
{
	char a;
	do
	{
	system("cls");
	gets(l);
	printf("\n                   欢迎进入 录入地铁时刻信息 界面");
	do
	{
	printf("\n    新建列车信息?<y/n>       ");
	scanf("%c",&a);
	gets(l);
	if(a!='y'&&a!='n')
		WRONG();
	}while(a!='y'&&a!='n');
	if(a=='n')
	break;
		
		printf("\n---------------------");
		printf("\n录入第%d趟列车信息\n",n+1);
		printf("\n列车              ");
		gets(S[i].code);
		printf("\n日期              ");
		gets(S[i].data);
		printf("\n起点              ");
		gets(S[i].lp);
		printf("\n终点              ");
		gets(S[i].ap);
		printf("\n开车时间          ");
		gets(S[i].lt);
		printf("\n到达时间          ");
		gets(S[i].at);
		n++;
		i++;
	}while(i<10000);
	WRITE();
	system("cls");
	PRINT();
		getchar();
}
/////////////////////////////////////////////////////////////////////////////////////////////////文件记录模块
void WRITE()
{
	FILE *fp,*fp1;
	if((fp=fopen("hchsk.txt","w"))==NULL)
	{
		printf("无法创建文件!\n\n");
		getchar();
		return;
	}
	if((fp1=fopen("N.txt","w"))==NULL)
	{
		printf("无法创建文件!\n");
		getchar();
		return;
	}
	for(i=0;i<n;i++)
	if(fwrite(&S[i],sizeof(struct Subway),1,fp)==0)
	printf("写入数据失败!\n\n");
		fprintf(fp1,"%d",n);
		fclose(fp);
		fclose(fp1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////文件读取模块
void READ()
{
	FILE *fp,*fp1;
	if((fp=fopen("hchsk.txt","r"))==NULL)
	{
		printf("无法打开文件\n");
		getchar();
		return;
	}
	if((fp1=fopen("N.txt","r"))==NULL)
	{
		printf("无法打开文件!\n\n");
		getchar();
		return;
	}
	fscanf(fp1,"%d",&n);
	fclose(fp1);
	for(i=0;i<n;i++)
	{
		fread(&S[i],sizeof(struct Subway),1,fp);
	}
	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////打印模块
void PRINT()
{
		int i;
		printf("\n              系统记载的列车信息如下         ");
		printf("\n                                      ");
		printf("\n车次      日期       起点     终点      开车时间       到达时间          ");
		for(i=0;i<n;i++)
		{
			printf("\n%s%13s%10s%10s%12s%15s\n",S[i].code,S[i].data,S[i].lp,S[i].ap,S[i].lt,S[i].at);
			if(i>1&&i%10==0)
			{
		printf("\t");
		system("pause");
			}
		}

		system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////查询模块
void SEARCH()
{
	char name1[10];
	char name2[10];
	char name3[10];
	char name41[10];
	char name42[10];
	char choice;
	int j,k;
	READ();
	do
	{
	system("cls");
	printf("\n                欢迎进入 查询地铁线路及站点信息 界面 ");
	printf("\n\n                          请选择查找方式    ");
	printf("\n\n        1.列车信息汇总    2.查询车次        3.按终点查询");
	printf("\n    4.按起点查询          5.按终点和日期查询  6.返回上级菜单");
	printf("\n\n                       请选择：    ");
	scanf("%d",&j);
	gets(l);
	switch(j)
	{
	case 1:
		PRINT();
		break;
	case 2:
		printf("\n            请输入车次:   ");
		gets(name1);
		break;
	case 3:
		printf("\n            请输入终点:   ");
		gets(name2);
		break;
	case 4:
		printf("\n            请输入起点:   ");
		gets(name3);
		break;
	case 5:
		printf("\n            请输入终点:   ");
		gets(name41);
		printf("\n            请输入日期:   ");
		gets(name42);
		break;
	case 6:
		break;
	default:
		WRONG();
		break;
	}
	k=0;
	if(j==2)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].code,name1)==0)
			{
				printf("\n                   按 车次 查找列车信息成功!\n");
				printf("   车次        日期       起点       终点      开车时间      到达时间      \n");
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].code,name1)==0)
			{
				printf("%s%13s%10s%10s%12s%15s%11s\n",S[i].code,S[i].data,S[i].lp,S[i].ap,S[i].lt,S[i].at,S[i].price);
				k++;
			}
		}
		printf("\n                         共查询到%d趟列车信息，请按任意键返回     ",k);
		gets(l);
	}
	if(j==3)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name2)==0)
			{

				printf("\n                   按 终点 查找列车信息成功!\n");
				printf("   车次        日期       起点       终点      开车时间      到达时间      \n");
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name2)==0)
			{
				printf("%s%13s%10s%10s%12s%15s%11s\n",S[i].code,S[i].data,S[i].lp,S[i].ap,S[i].lt,S[i].at,S[i].price);
				k++;
			}
		}
		printf("\n                         共查询到%d趟列车信息，请按任意键返回     ",k);
		gets(l);
	}
	if(j==4)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].lp,name3)==0)
			{

				printf("\n                   按 起点 查找列车信息成功!\n");
				printf("   车次        日期       起点       终点      开车时间      到达时间      \n");
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].lp,name3)==0)
			{
				printf("%s%13s%10s%10s%12s%15s%11s\n",S[i].code,S[i].data,S[i].lp,S[i].ap,S[i].lt,S[i].at,S[i].price);
				k++;
			}
		}
		printf("\n                         共查询到%d趟列车信息，请按任意键返回     ",k);
		gets(l);
	}
	if(j==5)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name41)==0&&strcmp(S[i].data,name42)==0)
			{

				printf("\n                   按 终点和日期 查找列车信息成功!\n");
				printf("   车次        日期       起点       终点      开车时间      到达时间      \n");
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name41)==0&&strcmp(S[i].data,name42)==0)
			{
				printf("%s%13s%10s%10s%12s%15s%11s\n",S[i].code,S[i].data,S[i].lp,S[i].ap,S[i].lt,S[i].at,S[i].price);
				k++;
			}
		}
		printf("\n                        共查询到%d趟列车信息，请按任意键返回     ",k);
		gets(l);
	}
	do
	{
		system("cls");
		printf("\n\n                       继续查找（1），返回主菜单（2）            ");
		choice=getchar();
		gets(l);
		if(choice!='1'&&choice!='2')
		WRONG();
	}while(choice!='1'&&choice!='2');
	}while(choice!='2');
}
void PRICE()
{
	system("cls");//清屏
	char ch[2][35][30]=
	{ { {"岩内"},{"厦门北站"},{"天水路"},{"集美大道"},{"集美软件园"},{"诚毅广场"},
	    {"官任"},{"杏锦路"},{"杏林村"},{"园博苑"},{"集美学村"},{"高崎"},
		{"殿前"},{"火炬园"},{"塘边"},{"乌石浦"},{"吕厝"},{"莲花路口"},
		{"莲坂"},{"湖滨东路"},{"文灶"},{"将军祠"},{"中山公园"},{"镇海路"}} ,   //24个城市 
	  { {"五缘湾"},{"五缘湾南"},{"湿地公园"},{"高林"},{"金融中心"},{"林边"},
	    {"观音山"},{"何厝"},{"软件园"},{"岭兜"},{"古地石"},{"蔡塘"},
		{"中孚花园"},{"江头"},{"吕厝"},{"育秀东路"},{"体育中心"},{"湖滨中路"},
		{"建业路"},{"东渡路"},{"海沧大道"},{"海沧CBD"},{"芦坑"},{"马青路"},
		{"翁角路"},{"长庚医院"},{"新垵村"},{"马銮中心"},{"马銮西"},{"马銮北"}, //
		{"东孚"},{"天竺山"} } };//32个城市
 	//记住吕厝为 ch[0][16] 和 ch[1][14] 这两个字符串
    //想要站数差就是三维数组y维度的下标差
    char start[30],reach[30];
    printf("输入您的出发地：");
    scanf("%s",start);
    printf("输入您的目的地：");
    scanf("%s",reach);
    
    if(strcmp(start,reach)==0)
	//输入的城市相同 那么就不用进行下面的操作了（包括了吕厝）
    {
		printf("对不起,你已经在本站，不用再乘座了。\n");
		system("pause");
		return ;
	}

	int x1,x2,y1,y2,num,i;
	//num代表经过的站数 x1 x2代表车站号 y1 y2代表几号线(0或1)
	for(i=0;i<24;i++) //在三维数组里找到匹配的字符串
	{
		if(strcmp(start,ch[0][i])==0)
		{
			x1=i;
			y1=0;
		}
		if(strcmp(reach,ch[0][i])==0)
		{
			x2=i;
			y2=0;
		}
	}
	for(i=0;i<32;i++) //在三维数组里找到匹配的字符串
		{
			if(strcmp(start,ch[1][i])==0)
			{
				x1=i;
				y1=1;
			}
			if(strcmp(reach,ch[1][i])==0)
			{
				x2=i;
				y2=1;
			}
		}
		
		//上面两个循环就是把所有的线路都遍历了一遍 时间复杂度为O(32+24) 
		//遍历后确定了起始地点在数组中的位置，以坐标的形式表示了出来，这样计算站点差就简单了好多
		//下面的就是各种可能性的罗列
		
	if(y1==y2) //在相同的线路
	{
		if(strcmp(ch[y1][x1],"吕厝")==0)
		printf("出发地在中转站吕厝\n");
		else if(strcmp(ch[y2][x2],"吕厝")==0)
		printf("到达地在中转站吕厝\n");
		else
		printf("不需要转线，可直达\n");
		num=fabs(x1-x2);
	}
			
	else
	{
		if(strcmp(ch[y1][x1],"吕厝")==0)//出发地在中转站 这个时候y1一定是1 因为中转站在数组里出现了两次 以后者为最终
		{                               //这时候y1不等于y2 所以y2一定是0 
			printf("出发地在中转站吕厝\n");
			num=fabs(x2-16);//16为0号线中转站位置
		}
		else if(strcmp(ch[y2][x2],"吕厝")==0)//到达地在中转站 这个时候y2一定是1 因为中转站在数组里出现了两次 以后者为最终
		{                               //这时候y1不等于y2 所以y2一定是0 
			printf("到达地在中转站吕厝\n");
			num=fabs(x1-16);
		}
		else //他俩都不在中转站 而且在不同的线路
		{
			printf("请注意：要到吕厝转线\n");
			if(y1==0)//出发地在0号线 到达地在1号线
			num=fabs(x1-16)+fabs(x2-14);
			if(y2==0)//到达地在0号线 出发地在1号线
			num=fabs(x2-16)+fabs(x1-14);
		}
	}
	printf("需要坐%d站\n",num);
    switch(num)
 	{
    	case 1:case 2:case 3: printf("收费2元\n");break;
    	case 4:case 5:case 6: printf("收费3元\n");break;
   		case 7:case 8:case 9: printf("收费4元\n");break;
   		case 10:case 11:case 12: printf("收费5元\n");break;
   	    case 13:case 14:case 15: printf("收费6元\n");break;
  	    case 16:case 17:case 18: printf("收费7元\n");break;
  	    case 19:case 20:case 21:case 22:case 23:case 24:
   	    case 25:case 26:case 27:case 28:case 29:case 30:
  	    case 31:case 32:case 33:case 34:case 35:case 36:
        printf("收费8元\n");break;
    } 
    system("pause");
    
}




/////////////////////////////////////////////////////////////////////////////////////////////////统计模块
void SELECT()
{
	char name1[10];
	char name2[10];
	int t,k;
	char choice;
	READ();
	do
	{
		system("cls");
		printf("\n\n                                欢迎进入 统计地铁车次 界面\n");
		printf("\n                                        请选择统计方式      ");
		printf("\n\n                                1.按终点统计每日的车次数                 ");
		printf("\n                                2.按起点统计每日的车次数                 ");
		printf("\n                                       请选择：    ");
		scanf("%d",&t);
		gets(l);
		switch(t)
		{
		case 1:
			printf("\n              请输入终点：     ");
			gets(name1);
			break;
		case 2:
			printf("\n              请输入起点：     ");
			gets(name2);
			break;
		default:
			WRONG();
			break;
		}
		if(t==1)
		{
			k=0;
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].ap,name1)==0)
				{
					printf("\n\n                              按 终点 统计列车信息成功\n");
					break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].ap,name1)==0)
					++k;
			}
		    printf("\n                           共查询到%d趟列车信息，请按任意键返回     ",k);
			gets(l);
		}
		if(t==2)
		{
			k=0;
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].lp,name1)==0)
				{
					printf("\n\n                               按 起点 统计列车信息成功\n");
					break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].lp,name1)==0)
					k++;
			}
			printf("\n                           共查询到%d趟列车信息，请按任意键返回     ",k);
			gets(l);
		}
		do
		{
			system("cls");
			printf("\n\n                         继续统计（1），返回主菜单（2）           ");
			choice=getchar();
			gets(l);
			if(choice!='1'&&choice!='2')
				WRONG();
		}while(choice!='1'&&choice!='2');
	}while(choice!='2');
}
/////////////////////////////////////////////////////////////////////////////////////////////////纠错模块
void WRONG()
{
	system("cls");
	printf("\n\n                                 输入错误，请按任意键返回        ");
	gets(l);
	getchar();
}
