#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<algorithm>

#define F for(i=0;i<n;i++)
#define ENTER "��������Ҫ���������"

void bucket(int n,int *p);
void choose(int n,int *p);
void bubble(int n,int *p);
void quick (int n,int *p); 

using namespace std;
int main()
{
	int n,m,*p=NULL; 
	while(1)
	{
		cout<<"���������ֵĸ���:";
		cin>>m;
		p=(int *) malloc(m*sizeof(int)); 
	    cout<<"0.�˳�����"<<endl<<"1.Ͱ����"<<endl
		<<"2.ѡ������"<<endl
	    <<"3.ð������"<<endl<<"4.��������"<<endl;
	    cout<<"��ѡ��Ҫ���еĲ���:";
	    cin>>n;
	    switch(n)
	    {
	    	case 0: cout<<"���������ллʹ�ã�";return 0;
	    	case 1: bucket(m,p);break;
	    	case 2: choose(m,p);break;
	    	case 3: bubble(m,p);break;
	    	case 4: quick(m,p);break;
		}
		
	    system("pause");
	    system("cls");
	
	}
 } 

void bucket(int n,int *p)
{
	int max,min,i,t,j;
	char ch;
	while(1)
	{
		cout<<"�������������ݷ�Χ��(����0-10)"<<endl;
	    cin>>min>>ch>>max;
	    if(ch=='-'&&max>=min) break;
	    else cout<<"��ʽ��������������"<<endl;
	}
	p=(int *) malloc((max+1)*sizeof(int));
	for(i=0;i<=max;i++)
	p[i]=0;
	cout<<ENTER<<endl;
	F//�궨��forѭ�� 
	{
		cin>>t;
		p[t]++;
	}
	for(i=0;i<=max;i++)
	for(j=1;p[i]>=j;j++)
		cout<<i<<' ';
}

void choose(int n,int *p)
{
	int i,tem,j,index;
	cout<<ENTER<<endl;
	F cin>>p[i];
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(p[j]<p[index])
			index=j;
		}
		tem=p[i];
		p[i]=p[index];
		p[index]=tem;
	}
	F cout<<p[i]<<' ';
}
void bubble(int n,int *p)
{
	int i,j,tem;
	cout<<ENTER<<endl;//ENTER�궨��һ�仰 
	F cin>>p[i];
	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	{
		if(p[j]>p[j+1])
		{
			tem=p[j];
			p[j]=p[j+1];
			p[j+1]=tem;
		}
	}
	F cout<<p[i]<<' ';
}
void quick(int n,int *p)
{
	int i;
	cout<<ENTER<<endl;
	F cin>>p[i];
	sort(p,p+n);
	F cout<<p[i]<<' ';
}
