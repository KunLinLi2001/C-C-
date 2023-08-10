#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>//�����㷨
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
student s[50];//����һ��ȫ�ֽṹ���飬�����ڵ��ú�����ʱ����Լ��ٴ��Ρ�
int sum=0;//ѧ������
void menu()
{
	puts("1-����ѧ����Ϣ");
	puts("2-��ʾ����ѧ����Ϣ");
	puts("3-����ѧ�Ų�ѯѧ����Ϣ");
	puts("4-����������ѯѧ����Ϣ");
	puts("5-���ݰ༶��ѯѧ����Ϣ");
	puts("6-���һ��ѧ����Ϣ");
	puts("7-�����ֺܷ�ƽ���ֲ�д���ļ�");
	puts("8-����ÿ�ſγ̵�ƽ���ֲ�д���ļ�");
	puts("9-����ÿ���༶��ÿ�ſγ̵�ƽ����");
	puts("10-��ѯƽ������ߵ�ѧ��");
	puts("11-��ѯÿ����ƽ������ߵ�ѧ��");
	puts("12-����ѧ�Ų�ѯɾ��ѧ����Ϣ");
	puts("13-����ƽ���ִ�С��������");
	puts("14-����ѧ�Ų�ѯ�޸�ѧ����Ϣ");
	puts("0-�˳�����");
	puts("����������ѡ�");
}
void save_student()//��ѧ����Ϣ���浽�ļ���
{
	FILE *fp;
	fp=fopen("StudentMessage.txt","wb");
	if(fp==NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		return;
	}
	int i;
	student *tem=(student *)malloc(sizeof(student));
	for(i=0;i<sum;i++)
	{
		tem=&s[i];
		fwrite(tem,sizeof(student),1,fp);	
	}
	printf("����ɹ���\n");
	fclose(fp);
}
void read_student()//���ļ���ȡѧ����Ϣ
{
	FILE *fp;
	student *tem=(student *)malloc(sizeof(student));
	fp=fopen("StudentMessage.txt","rb");
	if(fp==NULL)
	{
		puts("�ļ���ʧ�ܣ�");
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
	printf("�ɹ���ȡ��%d����Ϣ\n",sum);
	fclose(fp);
}
void createstudent()
{
	printf("������ѧ����������");
	scanf("%d",&sum);
	int i;
	puts("������ѧ������Ϣ��");
	for(i=0;i<sum;i++)
	{
		printf("��%dλѧ������Ϣ��\n",i+1);
		printf("ѧ�ţ�");
		scanf("%s",s[i].num);
		printf("������");
		scanf("%s",s[i].name);
		printf("�༶��");
		scanf("%s",s[i].Class);
		printf("���ĳɼ���");
		scanf("%lf",&s[i].a);
		printf("��ѧ�ɼ���");
		scanf("%lf",&s[i].b);
		printf("Ӣ��ɼ���");
		scanf("%lf",&s[i].c);		
	}
	puts("��ӽ�����");
	save_student();
}
int have_or_not()//�ж��Ƿ��Ѿ�����ѧ����Ϣ
{
	if(!sum)
	{
		printf("Ŀǰû��ѧ����Ϣ��\n");
		return 0;
	}
	return 1;
}
void showstudents()
{
	if(!have_or_not()) return;
	int i;
	printf("Ŀǰ��%d��ѧ����������Ϣ���£�\n",sum);
	printf("|--------------------------------��ϢԤ��------------------------------------|\n");
	printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	for(i=0;i<sum;i++)
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i].num,s[i].name,s[i].Class,s[i].a,s[i].b,s[i].c,(s[i].a+s[i].b+s[i].c)/3);
	puts("չʾ������");
}
void search(int sec)
{
	int i,j=0;
	student temp[50];
	char com[20];
	printf("��������Ҫ��ѯ����Ϣ�ؼ��ʣ�");
	char tem[20];
	scanf("%s",tem);
	for(i=0;i<sum;i++)
	{
		switch(sec)
		{
			case 1:strcpy(com,s[i].num);break;//ѧ��
			case 2:strcpy(com,s[i].name);break;//����
			case 3:strcpy(com,s[i].Class);break;//�༶
		}
		if(strcmp(com,tem)==0)
		{
			temp[j]=s[i];
			j++;
		}
	}
	if(j==0)
	{
		printf("û���ҵ���ص���Ϣ��\n");
		return;
	}
	printf("��ѯ����%d��ѧ����Ϣ\n��������\n",j);
	printf("|--------------------------------��ϢԤ��------------------------------------|\n");
	printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	for(i=0;i<j;i++)
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",temp[i].num,temp[i].name,temp[i].Class,temp[i].a,temp[i].b,temp[i].c,(temp[i].a+temp[i].b+temp[i].c)/3);
	puts("��ѯ������");
}
void addstudent()
{
	printf("Ŀǰ����%d��ѧ����Ϣ\n",sum);
	printf("�������%dλѧ������Ϣ:\n",sum+1);
	printf("ѧ�ţ�");
	scanf("%s",s[sum].num);
	printf("������");
	scanf("%s",s[sum].name);
	printf("�༶��");
	scanf("%s",s[sum].Class);
	printf("���ĳɼ���");
	scanf("%lf",&s[sum].a);
	printf("��ѧ�ɼ���");
	scanf("%lf",&s[sum].b);
	printf("Ӣ��ɼ���");
	scanf("%lf",&s[sum].c);	
	puts("��ӽ�����\n");
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
		printf("������Ҫ�޸ĵ�ѧ��ѧ��(0-�˳�)��");
		scanf("%s",num);
		if(strcmp(num,"0")==0)
		{
			puts("�޸Ľ�����");
			break;
		}
		for(i=0;i<sum;i++)
		{
			if(strcmp(num,s[i].num)==0)
			{
				printf("|--------------------------------��ϢԤ��------------------------------------|\n");
				printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
				printf("|----------|----------|----------|----------|----------|----------|----------|\n");	
				printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i].num,s[i].name,s[i].Class,s[i].a,s[i].b,s[i].c,(s[i].a+s[i].b+s[i].c)/3);	
				printf("������Ҫ�޸ĳɵ���Ϣ\n");
				printf("ѧ�ţ�");
				scanf("%s",s[i].num);
				printf("������");
				scanf("%s",s[i].name);
				printf("�༶��");
				scanf("%s",s[i].Class);
				printf("���ĳɼ���");
				scanf("%lf",&s[i].a);
				printf("��ѧ�ɼ���");
				scanf("%lf",&s[i].b);
				printf("Ӣ��ɼ���");
				scanf("%lf",&s[i].c);	
				puts("�޸ĳɹ���\n");
				break;
			}
		}
		if(i==sum)
		{
			printf("û�����ѧ����Ϣ��������������룡\n");
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
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	int i;
	char ch[]=" ",sh='\n';
	fputs("˳��Ϊ��ѧ�š��������༶�����ſγɼ����ܷ֡�ƽ���ɼ�",fp);
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
	puts("���㱣��ɹ���\n�����ļ��в鿴��������");
	fclose(fp);
}
void course_average()
{
	FILE *fp;
	fp=fopen("courseAverage.txt","w");
	if(fp==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
	fputs("����ƽ����Ϊ��",fp);
	fprintf(fp,"%.2f",aa);
	fputs("\n",fp);
	fputs("��ѧƽ����Ϊ��",fp);
	fprintf(fp,"%.2f",bb);
	fputs("\n",fp);
	fputs("Ӣ��ƽ����Ϊ��",fp);
	fprintf(fp,"%.2f",cc);
	fputs("\n",fp);	
	puts("���㱣��ɹ���\n�����ļ��в鿴��������");
	fclose(fp);	
}
void max_average()
{
	student s1[50];
	int i;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_average);
//	printf("Ŀǰ��%d��ѧ����������Ϣ���£�\n",sum);
//	printf("|--------------------------------��ϢԤ��------------------------------------|\n");
//	printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
//	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
//	for(i=0;i<sum;i++)
//	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i].num,s1[i].name,s1[i].Class,s1[i].a,s1[i].b,s1[i].c,(s1[i].a+s1[i].b+s1[i].c)/3);
//	puts("չʾ������");
	puts("ƽ������ߵ�ͬѧ��Ϣ���£�");
	printf("|--------------------------------��ϢԤ��------------------------------------|\n");
	printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
	printf("|----------|----------|----------|----------|----------|----------|----------|\n");
	printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i-1].num,s1[i-1].name,s1[i-1].Class,s1[i-1].a,s1[i-1].b,s1[i-1].c,(s1[i-1].a+s1[i-1].b+s1[i-1].c)/3);
}
void sort_average()
{
	FILE *fp;
	fp=fopen("SortbyAverage.txt","w");
	if(fp==NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		return ;
	}
	student s1[50];
	int i;
	for(i=0;i<sum;i++)
	s1[i]=s[i];
	std::sort(s1,s1+sum,to_average);
	fputs("|--------------------------------��ϢԤ��------------------------------------|\n",fp);
	fputs("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n",fp);
	fputs("|----------|----------|----------|----------|----------|----------|----------|\n",fp);
	for(i=0;i<sum;i++)
	fprintf(fp,"|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s1[i].num,s1[i].name,s1[i].Class,s1[i].a,s1[i].b,s1[i].c,(s1[i].a+s1[i].b+s1[i].c)/3);	
	fclose(fp);
	puts("���㱣��ɹ���\n�����ļ��в鿴��������");
}
void delete_student()
{
	while(1)
	{
		int i,j;
		char tem[10];
		printf("��������Ҫɾ����ѧ����ѧ��(0-�˳�)��");
		scanf("%s",tem);
		if(strcmp(tem,"0")==0)
		break;
		for(i=0;i<sum;i++)
		{
			if(strcmp(tem,s[i].num)==0)
			break;//�ҵ���Ҫɾ���Ľ��
		}
		if(i==sum){
			printf("δ�ҵ����ѧ����Ϣ\n����������");
			continue;
		}
		for(j=i+1;j<sum;j++)
		s[j-1]=s[j];//����������ƣ���һ�����Ƶ�ʱ��i+1�Ͱ�ԭ���Ǹ�i�ĸ����˱���ɾ����
		sum--;
		printf("ɾ���ɹ���\n");
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
		if(strcmp(s1[i].Class,s1[i-1].Class)!=0)//����һ���İ༶��һ�� ��j++�洢��һ��ѧ����Ϣ
		//ͬһ�е�ѧ����Ϣ�İ༶��һ����
		{
			strcpy(s[j][k].num,"NULL");//����ǰ��ÿһ������һ����ֹ��ʾ��
			k=0;
			j++;
		}
		s[j][k]=s1[i];//�����е�ѧ���ֵ���ͬ�еĶ�ά������
		k++;
	}
	strcpy(s[j][k].num,"NULL");
//	k=0;i=0;
	//����¼��j+1���༶
//	for(i=0;i<=j;i++)   //�������
//	{
//		for(k=0;strcmp(s[i][k].num,"NULL")!=0;k++)
//		printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i][k].num,s[i][k].name,s[i][k].Class,s[i][k].a,s[i][k].b,s[i][k].c,(s[i][k].a+s[i][k].b+s[i][k].c)/3);
//	}
	//���ϲ����ɹ�����ͬ�༶��ѧ����Ϣ����ͬһ�У���ά���飩������
	student max;
	puts("ÿ���༶ƽ������ߵ�ͬѧ����Ϣ���£�");
	printf("|--------------------------------��ϢԤ��------------------------------------|\n");
	printf("|   ѧ��   |   ����   |   �༶   | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� | ƽ���ɼ� |\n");
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
		printf("�ļ���ʧ�ܣ�\n");
		return ;
	}
	fputs("˳��Ϊ���༶������ƽ���ɼ�����ѧƽ���ɼ���Ӣ��ƽ���ɼ�",fp);
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
		if(strcmp(s1[i].Class,s1[i-1].Class)!=0)//����һ���İ༶��һ�� ��j++�洢��һ��ѧ����Ϣ
		//ͬһ�е�ѧ����Ϣ�İ༶��һ����
		{
			strcpy(s[j][k].num,"NULL");//����ǰ��ÿһ������һ����ֹ��ʾ��
			k=0;
			j++;
		}
		s[j][k]=s1[i];//�����е�ѧ���ֵ���ͬ�еĶ�ά������
		k++;
	}
	strcpy(s[j][k].num,"NULL");
	//	k=0;i=0;
		//����¼��j+1���༶
	//	for(i=0;i<=j;i++)   //�������
	//	{
	//		for(k=0;strcmp(s[i][k].num,"NULL")!=0;k++)
	//		printf("|%-10s|%-10s|%-10s|%-10.2f|%-10.2f|%-10.2f|%-10.2f|\n",s[i][k].num,s[i][k].name,s[i][k].Class,s[i][k].a,s[i][k].b,s[i][k].c,(s[i][k].a+s[i][k].b+s[i][k].c)/3);
	//	}
	//���ϲ����ɹ�����ͬ�༶��ѧ����Ϣ����ͬһ�У���ά���飩������
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
	puts("���㱣��ɹ���\n�����ļ��в鿴��������");
}
int main()
{ 
	int cls;
	while(1)
	{
		if(!sum)//һ��ʼ�Ͷ�ȡһ���ļ������Ϣ
		read_student();
		menu();
		scanf("%d",&cls);
		system("cls");
		switch(cls)
		{
			case 0: printf("��л����ʹ��\nThanks\n");system("pause");return 0;
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
