#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	while(1)
	{
		int n;
			double sum=0,score,ave;
			cout<<"����С�������м�����:";
			
			cin>>n;
			cout<<"����ÿ���˴�ķ֣�\n";
			for(int i=1;i<=n;i++)
			{
				printf("��%d��ͬѧ��ķ�Ϊ��",i);
				cin>>score;
				sum+=score;
			}
			ave=sum/n;
			cout<<"ƽ����Ϊ��"<<ave<<endl<<endl;
	}
	
}
