#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI=3.1415926;
class point
{
	protected:
		double X;
		double Y;
	public:
		point(double xx=0,double yy=0):X(xx),Y(yy){}
		double get_x(){return X;}
		double get_y(){return Y;}
		double get_angel(){return 180/PI*atan2(Y,X);}
		double get_r(){return sqrt(X*X+Y*Y);}
};

int main()
{
	
	double x,y;
	cout<<"请输入x与y:";
	cin>>x>>y;
	while(x>0&&y>=0)
	{
		point a(x,y);
		printf("直角坐标为(%.2f,%.2f)\n",a.get_x(),a.get_y());
		printf("极坐标为(%.2f,%.2f)\n",a.get_angel(),a.get_r());
		cout<<"请输入x与y:";
		cin>>x>>y;
	}
	cout<<"感谢使用！\n";
}
