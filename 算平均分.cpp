#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	while(1)
	{
		int n;
			double sum=0,score,ave;
			cout<<"输入小组里面有几个人:";
			
			cin>>n;
			cout<<"输入每个人打的分：\n";
			for(int i=1;i<=n;i++)
			{
				printf("第%d个同学打的分为：",i);
				cin>>score;
				sum+=score;
			}
			ave=sum/n;
			cout<<"平均分为："<<ave<<endl<<endl;
	}
	
}
