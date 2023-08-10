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
///////////////////////////////////////////////////////////////////////////////////////������
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
			printf("\n                                �����˳����밴������˳�");
			printf("\n\n                                ");
			break;
		default:WRONG(); break;
		}
	}while(x!=5);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////�˵�ģ��
int menu()
{
	int choice;
	system("cls");
printf("                                                                   \n");
printf("                                                                   \n");
printf("                                                                   \n");
printf("                            ��ӭ�������ŵ���Ʊ��ϵͳ               \n");
printf("                        Welcome to Xiamen Subway System            \n");
printf("                                                                   \n");
printf("                                                                   \n");
	   printf("\n\n");
printf("                                 ����ѡ��                        \n");
printf("                            1.¼������·��վ����Ϣ               \n");
printf("                            2.��ѯ��·��վ����Ϣ                 \n");
printf("                            3.��ѯƱ��                           \n");
printf("                            4.ͳ���г�ʱ�̼�������Ϣ             \n");
printf("                            5.�˳�                               \n");
printf("                                                                 \n");
printf("                                   ��ѡ�� ");
    scanf("%d",&choice);
	return choice;
}
/////////////////////////////////////////////////////////////////////////////////////////////////����ģ��
void INPUT()
{
	char a;
	do
	{
	system("cls");
	gets(l);
	printf("\n                   ��ӭ���� ¼�����ʱ����Ϣ ����");
	do
	{
	printf("\n    �½��г���Ϣ?<y/n>       ");
	scanf("%c",&a);
	gets(l);
	if(a!='y'&&a!='n')
		WRONG();
	}while(a!='y'&&a!='n');
	if(a=='n')
	break;
		
		printf("\n---------------------");
		printf("\n¼���%d���г���Ϣ\n",n+1);
		printf("\n�г�              ");
		gets(S[i].code);
		printf("\n����              ");
		gets(S[i].data);
		printf("\n���              ");
		gets(S[i].lp);
		printf("\n�յ�              ");
		gets(S[i].ap);
		printf("\n����ʱ��          ");
		gets(S[i].lt);
		printf("\n����ʱ��          ");
		gets(S[i].at);
		n++;
		i++;
	}while(i<10000);
	WRITE();
	system("cls");
	PRINT();
		getchar();
}
/////////////////////////////////////////////////////////////////////////////////////////////////�ļ���¼ģ��
void WRITE()
{
	FILE *fp,*fp1;
	if((fp=fopen("hchsk.txt","w"))==NULL)
	{
		printf("�޷������ļ�!\n\n");
		getchar();
		return;
	}
	if((fp1=fopen("N.txt","w"))==NULL)
	{
		printf("�޷������ļ�!\n");
		getchar();
		return;
	}
	for(i=0;i<n;i++)
	if(fwrite(&S[i],sizeof(struct Subway),1,fp)==0)
	printf("д������ʧ��!\n\n");
		fprintf(fp1,"%d",n);
		fclose(fp);
		fclose(fp1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////�ļ���ȡģ��
void READ()
{
	FILE *fp,*fp1;
	if((fp=fopen("hchsk.txt","r"))==NULL)
	{
		printf("�޷����ļ�\n");
		getchar();
		return;
	}
	if((fp1=fopen("N.txt","r"))==NULL)
	{
		printf("�޷����ļ�!\n\n");
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
//////////////////////////////////////////////////////////////////////////////////////////////////��ӡģ��
void PRINT()
{
		int i;
		printf("\n              ϵͳ���ص��г���Ϣ����         ");
		printf("\n                                      ");
		printf("\n����      ����       ���     �յ�      ����ʱ��       ����ʱ��          ");
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
/////////////////////////////////////////////////////////////////////////////////////////////////��ѯģ��
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
	printf("\n                ��ӭ���� ��ѯ������·��վ����Ϣ ���� ");
	printf("\n\n                          ��ѡ����ҷ�ʽ    ");
	printf("\n\n        1.�г���Ϣ����    2.��ѯ����        3.���յ��ѯ");
	printf("\n    4.������ѯ          5.���յ�����ڲ�ѯ  6.�����ϼ��˵�");
	printf("\n\n                       ��ѡ��    ");
	scanf("%d",&j);
	gets(l);
	switch(j)
	{
	case 1:
		PRINT();
		break;
	case 2:
		printf("\n            �����복��:   ");
		gets(name1);
		break;
	case 3:
		printf("\n            �������յ�:   ");
		gets(name2);
		break;
	case 4:
		printf("\n            ���������:   ");
		gets(name3);
		break;
	case 5:
		printf("\n            �������յ�:   ");
		gets(name41);
		printf("\n            ����������:   ");
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
				printf("\n                   �� ���� �����г���Ϣ�ɹ�!\n");
				printf("   ����        ����       ���       �յ�      ����ʱ��      ����ʱ��      \n");
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
		printf("\n                         ����ѯ��%d���г���Ϣ���밴���������     ",k);
		gets(l);
	}
	if(j==3)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name2)==0)
			{

				printf("\n                   �� �յ� �����г���Ϣ�ɹ�!\n");
				printf("   ����        ����       ���       �յ�      ����ʱ��      ����ʱ��      \n");
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
		printf("\n                         ����ѯ��%d���г���Ϣ���밴���������     ",k);
		gets(l);
	}
	if(j==4)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].lp,name3)==0)
			{

				printf("\n                   �� ��� �����г���Ϣ�ɹ�!\n");
				printf("   ����        ����       ���       �յ�      ����ʱ��      ����ʱ��      \n");
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
		printf("\n                         ����ѯ��%d���г���Ϣ���밴���������     ",k);
		gets(l);
	}
	if(j==5)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(S[i].ap,name41)==0&&strcmp(S[i].data,name42)==0)
			{

				printf("\n                   �� �յ������ �����г���Ϣ�ɹ�!\n");
				printf("   ����        ����       ���       �յ�      ����ʱ��      ����ʱ��      \n");
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
		printf("\n                        ����ѯ��%d���г���Ϣ���밴���������     ",k);
		gets(l);
	}
	do
	{
		system("cls");
		printf("\n\n                       �������ң�1�����������˵���2��            ");
		choice=getchar();
		gets(l);
		if(choice!='1'&&choice!='2')
		WRONG();
	}while(choice!='1'&&choice!='2');
	}while(choice!='2');
}
void PRICE()
{
	system("cls");//����
	char ch[2][35][30]=
	{ { {"����"},{"���ű�վ"},{"��ˮ·"},{"�������"},{"�������԰"},{"����㳡"},
	    {"����"},{"�ӽ�·"},{"���ִ�"},{"԰��Է"},{"����ѧ��"},{"����"},
		{"��ǰ"},{"���԰"},{"����"},{"��ʯ��"},{"����"},{"����·��"},
		{"����"},{"������·"},{"����"},{"������"},{"��ɽ��԰"},{"��·"}} ,   //24������ 
	  { {"��Ե��"},{"��Ե����"},{"ʪ�ع�԰"},{"����"},{"��������"},{"�ֱ�"},
	    {"����ɽ"},{"����"},{"���԰"},{"�붵"},{"�ŵ�ʯ"},{"����"},
		{"���ڻ�԰"},{"��ͷ"},{"����"},{"���㶫·"},{"��������"},{"������·"},
		{"��ҵ·"},{"����·"},{"���״��"},{"����CBD"},{"«��"},{"����·"},
		{"�̽�·"},{"����ҽԺ"},{"����"},{"��������"},{"������"},{"���Ǳ�"}, //
		{"����"},{"����ɽ"} } };//32������
 	//��ס����Ϊ ch[0][16] �� ch[1][14] �������ַ���
    //��Ҫվ���������ά����yά�ȵ��±��
    char start[30],reach[30];
    printf("�������ĳ����أ�");
    scanf("%s",start);
    printf("��������Ŀ�ĵأ�");
    scanf("%s",reach);
    
    if(strcmp(start,reach)==0)
	//����ĳ�����ͬ ��ô�Ͳ��ý�������Ĳ����ˣ����������ȣ�
    {
		printf("�Բ���,���Ѿ��ڱ�վ�������ٳ����ˡ�\n");
		system("pause");
		return ;
	}

	int x1,x2,y1,y2,num,i;
	//num��������վ�� x1 x2����վ�� y1 y2��������(0��1)
	for(i=0;i<24;i++) //����ά�������ҵ�ƥ����ַ���
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
	for(i=0;i<32;i++) //����ά�������ҵ�ƥ����ַ���
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
		
		//��������ѭ�����ǰ����е���·��������һ�� ʱ�临�Ӷ�ΪO(32+24) 
		//������ȷ������ʼ�ص��������е�λ�ã����������ʽ��ʾ�˳�������������վ���ͼ��˺ö�
		//����ľ��Ǹ��ֿ����Ե�����
		
	if(y1==y2) //����ͬ����·
	{
		if(strcmp(ch[y1][x1],"����")==0)
		printf("����������תվ����\n");
		else if(strcmp(ch[y2][x2],"����")==0)
		printf("���������תվ����\n");
		else
		printf("����Ҫת�ߣ���ֱ��\n");
		num=fabs(x1-x2);
	}
			
	else
	{
		if(strcmp(ch[y1][x1],"����")==0)//����������תվ ���ʱ��y1һ����1 ��Ϊ��תվ����������������� �Ժ���Ϊ����
		{                               //��ʱ��y1������y2 ����y2һ����0 
			printf("����������תվ����\n");
			num=fabs(x2-16);//16Ϊ0������תվλ��
		}
		else if(strcmp(ch[y2][x2],"����")==0)//���������תվ ���ʱ��y2һ����1 ��Ϊ��תվ����������������� �Ժ���Ϊ����
		{                               //��ʱ��y1������y2 ����y2һ����0 
			printf("���������תվ����\n");
			num=fabs(x1-16);
		}
		else //������������תվ �����ڲ�ͬ����·
		{
			printf("��ע�⣺Ҫ������ת��\n");
			if(y1==0)//��������0���� �������1����
			num=fabs(x1-16)+fabs(x2-14);
			if(y2==0)//�������0���� ��������1����
			num=fabs(x2-16)+fabs(x1-14);
		}
	}
	printf("��Ҫ��%dվ\n",num);
    switch(num)
 	{
    	case 1:case 2:case 3: printf("�շ�2Ԫ\n");break;
    	case 4:case 5:case 6: printf("�շ�3Ԫ\n");break;
   		case 7:case 8:case 9: printf("�շ�4Ԫ\n");break;
   		case 10:case 11:case 12: printf("�շ�5Ԫ\n");break;
   	    case 13:case 14:case 15: printf("�շ�6Ԫ\n");break;
  	    case 16:case 17:case 18: printf("�շ�7Ԫ\n");break;
  	    case 19:case 20:case 21:case 22:case 23:case 24:
   	    case 25:case 26:case 27:case 28:case 29:case 30:
  	    case 31:case 32:case 33:case 34:case 35:case 36:
        printf("�շ�8Ԫ\n");break;
    } 
    system("pause");
    
}




/////////////////////////////////////////////////////////////////////////////////////////////////ͳ��ģ��
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
		printf("\n\n                                ��ӭ���� ͳ�Ƶ������� ����\n");
		printf("\n                                        ��ѡ��ͳ�Ʒ�ʽ      ");
		printf("\n\n                                1.���յ�ͳ��ÿ�յĳ�����                 ");
		printf("\n                                2.�����ͳ��ÿ�յĳ�����                 ");
		printf("\n                                       ��ѡ��    ");
		scanf("%d",&t);
		gets(l);
		switch(t)
		{
		case 1:
			printf("\n              �������յ㣺     ");
			gets(name1);
			break;
		case 2:
			printf("\n              ��������㣺     ");
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
					printf("\n\n                              �� �յ� ͳ���г���Ϣ�ɹ�\n");
					break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].ap,name1)==0)
					++k;
			}
		    printf("\n                           ����ѯ��%d���г���Ϣ���밴���������     ",k);
			gets(l);
		}
		if(t==2)
		{
			k=0;
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].lp,name1)==0)
				{
					printf("\n\n                               �� ��� ͳ���г���Ϣ�ɹ�\n");
					break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(strcmp(S[i].lp,name1)==0)
					k++;
			}
			printf("\n                           ����ѯ��%d���г���Ϣ���밴���������     ",k);
			gets(l);
		}
		do
		{
			system("cls");
			printf("\n\n                         ����ͳ�ƣ�1�����������˵���2��           ");
			choice=getchar();
			gets(l);
			if(choice!='1'&&choice!='2')
				WRONG();
		}while(choice!='1'&&choice!='2');
	}while(choice!='2');
}
/////////////////////////////////////////////////////////////////////////////////////////////////����ģ��
void WRONG()
{
	system("cls");
	printf("\n\n                                 ��������밴���������        ");
	gets(l);
	getchar();
}
