//运行需要有ege图形库！！

#include<stdio.h> 
#include<graphics.h>//ege图形库的绘图库
#include<windows.h> 
#include<stdlib.h> 
#include<time.h>//时间种子用到

struct position//蛇身的链表
{
    int x;//相对的横坐标
    int y;//相对的纵坐标
    struct position *next;
};
typedef struct position position;
int direction=4;
position *head=(position *)malloc(sizeof(position));
position *tail=(position *)malloc(sizeof(position));
int Time=100;//默认难度的移动速 度为100ms

void move(int xx,int yy,int *newfood,int direction)
{
	switch(direction)
	{
		position *p;
		int x0,y0;
		case 1://向上移动的时候横坐标不变，纵坐标减少30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0;
			head->y=y0-30;
			p=tail->next;
			free(tail);//删掉尾部原本那个地方
			tail=p;//尾部移动
			break;
		case 2://向下移动的时候横坐标不变，纵坐标增加30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0;
			head->y=y0+30;
			p=tail->next;
			free(tail);//原理同上
			tail=p;
			break;
		case 3://向左移动的时候纵坐标不变，横坐标减少30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0-30;
			head->y=y0;
			p=tail->next;
			free(tail);//原理同上
			tail=p;
			break;
		case 4://向右移动的时候纵坐标不变，横坐标增加30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0+30;
			head->y=y0;
			p=tail->next;
			free(tail);//原理同上
			tail=p;
			break;					
	}
	if(head->x==xx&&head->y==yy)//吃到了
	{
		*newfood=1;
		switch(direction)
		{
			int x0,y0;
			case 1:
				head->next=(position *)malloc(sizeof(position));
				x0=head->x;
				y0=head->y;
				head=head->next;
				head->x=x0;
				head->y=y0-30;
				break;
			case 2:
				head->next=(position *)malloc(sizeof(position));
				x0=head->x;
				y0=head->y;
				head=head->next;
				head->x=x0;
				head->y=y0+30;
				break;	
			case 3:
				head->next=(position *)malloc(sizeof(position));
				x0=head->x;
				y0=head->y;
				head=head->next;
				head->x=x0-30;
				head->y=y0;
				break;	
			case 4:
				head->next=(position *)malloc(sizeof(position));
				x0=head->x;
				y0=head->y;
				head=head->next;
				head->x=x0+30;
				head->y=y0;
				break;
		}
	}
}
void show()
{
	position *p=tail;
	int sum=0;//蛇增加的长度，也就是得分
	while(p!=head->next)
	{
		sum++;
		if(head->x>0&&head->x<900&&head->y>0&&head->y<900)
		{
			setfillcolor(EGERGB(255, 0, 0));//给蛇涂色
			bar(p->x-15,p->y-15,p->x+15,p->y+15);//画蛇身
			setfillcolor(EGERGB(255, 0, 255));//给方块边缘涂色
			bar(p->x-13,p->y-13,p->x+13,p->y+13);//画每一块蛇的轮廓
			p=p->next;
		}
		else//蛇撞墙了
		{
            //setcolor(EGERGB(255, 0, 0));
            //setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
            setfont(100, 0, "黑体");
            outtextxy(250, 360, "游戏结束");
            if (sum<10) outtextxy(100, 460, "老师，新手进阶");
            if (sum>=10&&sum<20) outtextxy(100,460,"老师，小试牛刀");
            setfont(70, 0, "黑体");
            if (sum>=20&&sum<30)
			outtextxy(250, 460, "老师水平不错~");
            if(sum>=30)outtextxy(250, 460, "老师您太强了！");
            Sleep(2000);
            getch();
            //closegraph();
            
            return;			
		}
		int hx,hy;
		hx=head->x;
		hy=head->y;
		position *p2=tail;
		while(p2!=head)//蛇撞到了自己
		{
			if(hx==p2->x&&hy==p2->y)
			{
				//setcolor(EGERGB(255, 0, 0));
				setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
				setfont(100, 0, "黑体");
				outtextxy(250, 360, "游戏结束");
				if (sum<10) outtextxy(100, 460, "老师，新手进阶");
				if (sum>=10&&sum<20) outtextxy(100,460,"老师，小试牛刀");
				setfont(70, 0, "黑体");
				if (sum>=20&&sum<30)
				outtextxy(250, 460, "老师水平不错~");
				if(sum>=30)outtextxy(250, 460, "老师您太强了！");
				Sleep(2000);
				getch();
				//closegraph();

				return;	
			}
			p2=p2->next;
		}
	}
}
void play(int m)
{
		head->x=75;
		head->y=15;
		tail->x=15;
		tail->y=15;
		tail->next=(position *)malloc(sizeof(position));
		tail=tail->next;
		tail->x=45;
		tail->y=15;
		tail->next=head;
		direction=rand()%4+1;
		//以上为对蛇进行初始化，设置了头和尾，以及中间一节共三节
		srand(time(0));//设置随机种子，保证每次运行随机数不一样
		initgraph(900,900);//创建900 ×900的绘图窗口
		Sleep(2000);//给玩家反应时间
		char direc;
		int food=1;
		while(1)
		{
			int xx,yy;
			if(food)//生成食物位置
			{
				start:
				//解释：下面坐标为什么是30，因为每个食物or蛇身子是30*30个像素点组成的
				xx=rand()%30+1;//1-30随机数
				yy=rand()%30+1;//1-30随机数
				xx=xx*30-15;//边缘无法形成900像素图
				yy=yy*30-15;
				int flag=1;//默认食物和蛇身不重合
				position *p=tail;//定位在尾部
				while(p!=head->next)//遍历蛇身
				{//把每个蛇身都和食物位置作比较
					if(p->x==xx&&p->y==yy)
					{
						flag=0;//代表食物生成在了蛇的身上
						break;
					}
					p=p->next;
				}
				if(!flag) goto start;
				food=0;
			}
			if(kbhit())//判断是否有按键按下
			{
				direc=getch();
				switch(direc)
				{
					case 38://上键的键码
					        if(direction!=2) direction=1;
					        break; //根据键值修改对应的方向
					case 40://下键
					        if(direction!=1) direction=2;
					        break;
					case 37://左键
					        if(direction!=4) direction=3;
					        break;
					case 39://右键
					        if(direction!=3) direction=4;
					        break;				
				}
			}
			move(xx,yy,&food,direction);
			cleardevice();//清屏
			show();
			setfillcolor(EGERGB(255, 255,0));//黄色的食物
			bar(xx-15,yy-15,xx+15,yy+15);//画出食物
			//setfillcolor(EGERGB(0,255,0));
			bar(xx-15,yy-15,xx+15,yy+15);
			if(m==1)
			Sleep(Time);
			if(m==2)
			{
				Time-=1;
				Sleep(Time);
			}
		}
		
}
void menu()
{
	puts("\t你的目标是吃掉更多的豆子，得到更高的分数。\n");
	puts("\t用“上、下、左、右”控制蛇的方向\n");
	puts("\t友情提示：撞到墙壁/头撞到蛇身时，游戏结束\n");
	puts("\t欢迎您的挑战！\n");
}
int mode()
{
	int n;
	printf("\t请选择您要挑战的难度\n");
	printf("\t0-返回上一级\n");
	printf("\t1-新手\n");
	printf("\t2-简单\n");
	printf("\t3-中等\n");
	printf("\t4-困难\n");
	printf("\t5-噩梦\n");
	printf("\t6-地狱\n");
	printf("\t请输入您的选项：");
	scanf("%d",&n);
	switch(n)
	{
		case 1:Time=500;break;
		case 2:Time=300;break;
		case 3:Time=100;break;
		case 4:Time=80;break;
		case 5:Time=50;break;
		case 6:Time=20;break;
		case 0:return Time;
	}
	return Time;
}
int main()
{
	while(1)
	{
		int n,m;
		printf("\t欢迎进入坤坤贪吃蛇！\n");
		printf("\t1-开始游戏\n");
		printf("\t2-游戏说明\n");
		printf("\t3-难度设置\n");
		printf("\t0-退出游戏\n");
		printf("\t请输入您的选项：");
		scanf("%d",&n);
		system("cls");
		switch(n)
		{
			case 1:
				{
					printf("\t1-标准模式(速度恒定，为设置的难度)\n");
					printf("\t2-生存模式(速度随时间逐渐增快)\n");
					printf("\t请选择您的游戏模式：");
					scanf("%d",&m);
					switch(m)
					{
						case 1:play(m);break;
						case 2:Time=500;play(m);break;
					}
				}
			case 2:menu();break;
			case 3:Time=mode();break;
		}
		system("pause");
		system("cls");
	}
	printf("游戏结束！\n");
}
