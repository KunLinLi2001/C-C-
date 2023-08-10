#include<iostream>
using namespace std;

class Time
{
	private:
		int days;
		int hours;
		int minutes;
	public:
		Time(int d=0,int h=0,int m=0):days(d),hours(h),minutes(m){}
		void Set(int d,int h,int m)
		{
			days=d;
			hours=h;
			minutes=m;
		}
		Time sum(Time &t);
		void show(){cout<<days<<' '<<hours<<' '<<minutes;}
};

Time Time::sum(Time &t)
{
	int d,h,m,h1,m1;
	cin>>d>>h>>m;
	Time a(d,h,m);
	cin>>d>>h>>m;
	Time b(d,h,m);
	m1=a.minutes+b.minutes;
	m=m1%60;
	h1=a.hours+b.hours+m1/60;// m1/60 为分钟溢出的部分
	h=h1%24;
	d=a.days+b.days+h1/24;// h1/24 为小时溢出的部分
	t.Set(d,h,m);
	return t;
}
int main()
{
	Time a;
	a.sum(a);
	a.show();
}
