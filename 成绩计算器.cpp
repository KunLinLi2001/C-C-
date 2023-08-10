#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	fstream fp1,fp2;
	cout<<"1-计算璘公公成绩"<<endl<<"2-计算宁宝宝成绩"<<endl<<"3-计算其他人成绩"<<endl<<"请输入要进行的操作：";
	int n;
	cin>>n;
	switch(n)
	{
		case 1:
			fp1.open("璘公公.txt",ios::in);
		case 2:
			fp1.open("宁宝宝.txt",ios::in);
		case 3:
			fp1.open("其他人.txt",ios::in);
	}
	cin.clear();
	fp2.open("成绩结果.txt",ios::out);
	int score;
	double sum_easy=0,sum_hard=0;
	int num=0;
	double xuefen,sum_xuefen=0;
	fp1.seekg(ios::beg);
	while(1)
	{
//		cout<<"输入成绩(0-退出)：";
		fp1>>score;
		cout<<score<<endl;
		if(!score) break;
		sum_easy+=score;
//		cout<<"输入学分：";
		fp1>>xuefen;
		num++;
		sum_xuefen+=xuefen;
		sum_hard+=(1.0*xuefen*score);
		cout<<"huhu\n";
	}
	double easy,hard;
	easy=1.0*sum_easy/num;
	cout<<"简单平均分为："<<easy<<endl;
	hard=1.0*sum_hard/sum_xuefen;
	cout<<"加权平均分为："<<hard<<endl;
	cout<<"信息已保存在成绩结果文件里"<<endl;
	fp2<<"简单平均分为："<<easy<<endl;
	fp2<<"加权平均分为："<<hard<<endl;
	fp1.close();
	fp2.close();
}
