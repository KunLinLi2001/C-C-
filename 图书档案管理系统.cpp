#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����һ��ͼ�鵵������ϵͳ


struct book
{
	char num[10];//�鼮���
	char name[20];//����
	char writer[20];//����
	char publisher[20];//������
	int price;//�۸�
};

int number=0;//����ȫ�ֱ���,����ͼ�������

void menu()//�˵�����
{
	 puts("\n"); 
		puts("\t|-----------------------------|");
		puts("\t|------------��ҳ-------------|");
		puts("\t|-----------------------------|");
		puts("\t|\t0:�˳�ϵͳ            |");
		puts("\t|\t1:����鼮��Ϣ        |");
		puts("\t|\t2:��ѯ�鼮��Ϣ        |");
		puts("\t|\t3:���鼮��Ϣ����      |");
		puts("\t|\t4:�޸��鼮��Ϣ        |");
		puts("\t|\t5:ɾ���鼮��Ϣ        |");
		puts("\t|\t6:��ʾ�����鼮��Ϣ    |"); 
		puts("\t|-----------------------------|");
		printf("\n");
}
/**************************************1:����鼮��Ϣ********************************************************/
void addbook(struct book *s)
{
	char num[10],name[20],writer[20],publisher[20];//����ӵ��鼮��š����������ߡ�������
	int price;//����ӵļ۸�
	printf("�������鼮����Ϣ��\n");
	printf("�鼮��ţ�");
	scanf("%s",num);//����ӵ��鼮���
	printf("������");
	scanf("%s",name);//����ӵ�����
	printf("���ߣ�");
	scanf("%s",writer);//����ӵ�����
	printf("�����磺");
	scanf("%s",publisher);//����ӵĳ�����
	printf("�۸�");
	scanf("%d",&price);//����ӵļ۸�
	strcpy(s[number].num,num);//strcpyΪ�ַ����ĸ�ֵ����
	strcpy(s[number].name,name);
	strcpy(s[number].writer,writer);
	strcpy(s[number].publisher,publisher);
	s[number].price=price;
	number++;//Ϊ���´��������׼�� ͬʱ�����ֶ���һ����
}
/**************************************2:��ѯ�鼮��Ϣ*******************************************************/
void search(struct book *s)
{
	printf("1-ͨ���鼮��� 2-ͨ������\n3-ͨ������ 4-ͨ��������\n");
	printf("��ѡ�����Ĳ�ѯ��ʽ��");
	int n,i,j=0;
	char tem[20];
	struct book a[20];
	scanf("%d",&n);
	printf("��������Ҫ��ѯ����Ϣ��");
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
		printf("û�в�ѯ�������Ϣ\n");
		return ;
	}
	
	printf("һ����%d���鼮,�����鼮���£�\n",j);
		printf("|--------------------------------�鼮Ԥ��----------------------------------|\n");
		printf("|   �鼮���   |     ����     |     ����     |    ������    |     �۸�     |\n");
		printf("|--------------|--------------|--------------|--------------|--------------|\n");
		for(i=0;i<j;i++)
		printf("|%-14s|%-14s|%-14s|%-14s|%-14d|\n",s[i].num,s[i].name,s[i].writer,s[i].publisher,s[i].price);
		
}
/**************************************3:���鼮��Ϣ����*****************************************************/
//ʹ�õ�ð������  
void bubble1(struct book *s)//�ַ�����С��������
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
void bubble2(struct book *s)//�۸��С��������
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
	printf("1-������� 2-���ռ۸�");
	printf("��ѡ����������ʽ��\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:bubble1(s);break;
		case 2:bubble2(s);break;
	}
	printf("����ɹ���\n");
}
//ʹ�õ�ð������
/**************************************4:�޸��鼮��Ϣ******************************************************/
void modify(struct book *s)
{
	char num[10],name[20],writer[20],publisher[20];//���޸ĵ��鼮��š����������ߡ�������
	
	printf("��������Ҫ�޸ĵ��鼮��ţ�");
	char tem[10];
	int i,price;
	
	scanf("%s",tem);
	
	for(i=0;i<number;i++)
	{
		if(strcmp(tem,s[i].num)==0)
		{
			printf("�������鼮����Ϣ��\n");
			printf("�鼮��ţ�");
			scanf("%s",num);
			
			printf("������");
			scanf("%s",name);
			printf("���ߣ�");
			scanf("%s",writer);
			printf("�����磺");
			scanf("%s",publisher);
			printf("�۸�");
			scanf("%d",&price);
			strcpy(s[i].num,num);
			strcpy(s[i].name,name);
			strcpy(s[i].writer,writer);
			strcpy(s[i].publisher,publisher);
			s[i].price=price;
			printf("�޸ĳɹ���\n");
			break;
		}
	}
}
/**************************************5:ɾ���鼮��Ϣ *****************************************************/
void Delete(struct book *s)
{
	int i,j;
	char tem[10];
	printf("��������Ҫɾ���������ţ�");
	scanf("%s",tem);
	for(i=0;i<number;i++)
	{
		if(strcmp(tem,s[i].num)==0)
		break;//�ҵ���Ҫɾ���Ľ��
	}
	if(i==number){
		printf("δ�ҵ�����鼮��Ϣ\n");
		return ;
	}
	
	for(j=i+1;j<number;j++)
	s[j-1]=s[j];//����������ƣ���һ�����Ƶ�ʱ��i+1�Ͱ�ԭ���Ǹ�i�ĸ����˱���ɾ����
	number--;
	printf("ɾ���ɹ���\n");
}
/**************************************6:��ʾ�鼮��Ϣ *****************************************************/
void showbook(struct book *s)
{
	int i;
	printf("һ����%d���鼮,�����鼮���£�\n",number);
	printf("|--------------------------------�鼮Ԥ��----------------------------------|\n");
	printf("|   �鼮���   |     ����     |     ����     |    ������    |     �۸�     |\n");
	printf("|--------------|--------------|--------------|--------------|--------------|\n");
	for(i=0;i<number;i++)
	printf("|%-14s|%-14s|%-14s|%-14s|%-14d|\n",s[i].num,s[i].name,s[i].writer,s[i].publisher,s[i].price);
}

int main(void)
{
	int n;//nΪ�˵���ѡ��
	struct book s[50];	//����ṹ������(ָ��) 
	while(1)
	{
		menu();//�˵�����
		printf("������0~6������ѡ��������ݣ�");
		scanf("%d",&n);
		system("cls");//����
		switch(n)//switch ѡ��Ҫ���еĲ���
		{
			case 0:
				printf("��л����ʹ�ã�\nThanks��\n");
				system("pause");
				return 0;
			case 1: addbook(s);break;
			case 2: search(s);break;
			case 3: sort(s);break;
			case 4: modify(s);break;
			case 5: Delete(s);break;
			case 6: showbook(s);break;
			default: printf("������Ϣ�Ƿ���ȷ��\n");break;
		}
		system("pause");//��ͣ
		system("cls");//����
	}
}
