#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	fstream fp1,fp2;
	cout<<"1-����U�����ɼ�"<<endl<<"2-�����������ɼ�"<<endl<<"3-���������˳ɼ�"<<endl<<"������Ҫ���еĲ�����";
	int n;
	cin>>n;
	switch(n)
	{
		case 1:
			fp1.open("�U����.txt",ios::in);
		case 2:
			fp1.open("������.txt",ios::in);
		case 3:
			fp1.open("������.txt",ios::in);
	}
	cin.clear();
	fp2.open("�ɼ����.txt",ios::out);
	int score;
	double sum_easy=0,sum_hard=0;
	int num=0;
	double xuefen,sum_xuefen=0;
	fp1.seekg(ios::beg);
	while(1)
	{
//		cout<<"����ɼ�(0-�˳�)��";
		fp1>>score;
		cout<<score<<endl;
		if(!score) break;
		sum_easy+=score;
//		cout<<"����ѧ�֣�";
		fp1>>xuefen;
		num++;
		sum_xuefen+=xuefen;
		sum_hard+=(1.0*xuefen*score);
		cout<<"huhu\n";
	}
	double easy,hard;
	easy=1.0*sum_easy/num;
	cout<<"��ƽ����Ϊ��"<<easy<<endl;
	hard=1.0*sum_hard/sum_xuefen;
	cout<<"��Ȩƽ����Ϊ��"<<hard<<endl;
	cout<<"��Ϣ�ѱ����ڳɼ�����ļ���"<<endl;
	fp2<<"��ƽ����Ϊ��"<<easy<<endl;
	fp2<<"��Ȩƽ����Ϊ��"<<hard<<endl;
	fp1.close();
	fp2.close();
}
