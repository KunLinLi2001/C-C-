//运行需要有ege图形库！！
#include<iostream>
#include<graphics.h> 
#include<windows.h> 
#include<cstdlib> 
#include<ctime>
using namespace std;

struct position//蛇身的链表
{
    int x;//相对的横坐标
    int y;//相对的纵坐标
    position *next;
};

class snake
{
    private: 
		int direction;
    public: 
		position *tail;
    	position *head;
    	position *gettail(){return tail;}
    	void settail(position *p){tail=p;}//蛇尾——也就是链表尾部
    	position *gethead() {return head;}
   		void sethead(position *p) {head=p;}
    	snake() //将蛇身初始化
		{
        	tail=new position;
        	head=new position;
        	head->x=75;
        	head->y=15;
        	tail->x=15;
        	tail->y=15;
        	tail->next=new position;
        	tail->next->x=45;
        	tail->next->y=15;
        	tail->next->next=head;
        	direction=4;//1 2 3 4代表了四个方向
    	}
    	void setdirection(int a){direction=a;}
    	int getdirection(){return direction;}
    	void move(int x0, int y0, bool &newfood)
		{
        	switch (direction) {
            position *p;
            int xt;
            int yt;
        	case 1://向上移动的时候横坐标不变，纵坐标减少30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head->next;
                head->x = xt;
                head->y = yt - 30;
                p = tail->next;
                delete tail;//删掉尾部原本那个地方
                tail = p;//尾部移动
                break;
            }
        case 2://向下移动的时候横坐标不变，纵坐标增加30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head->next;
                head->x = xt;
                head->y = yt + 30;
                p = tail->next;
                delete tail;//原理同上
                tail = p;
                break;
            }
        case 3://向左移动的时候纵坐标不变，横坐标减少30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head-> next;
                head->x = xt - 30;
                head->y = yt;
                p = tail->next;
                delete tail;
                tail = p;
                break;
            }
        case 4://向右移动的时候纵坐标不变，横坐标增加30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head->next;
                head->x = xt + 30;
                head->y = yt;
                p = tail->next;
                delete tail;
                tail = p;
                break;
            }
        }
        if (head->x==x0&&head->y==y0) {//吃到了
            newfood = 1;
            switch (direction) {
                int xt;
                int yt;
            case 1:
                {
                    head->next = new position;
                    xt = head->x;
                    yt = head->y;
                    head = head->next;
                    head->x = xt;
                    head->y = yt - 30;
                    break;
                }
            case 2:
                {
                    head->next = new position;
                    xt = head->x;
                    yt = head->y;
                    head = head->next;
                    head->x = xt;
                    head->y = yt + 30;
                    break;
                }
            case 3:
                {
                    head->next = new position;
                    xt = head->x;
                    yt = head->y;
                    head = head->next;
                    head->x = xt - 30;
                    head->y = yt;
                    break;
                }
            case 4:
                {
                    head->next = new position;
                    xt = head->x;
                    yt = head->y;
                    head = head->next;
                    head->x = xt + 30;
                    head->y = yt;
                    break;
                }
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
	            closegraph();
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
					closegraph();
					return;	
				}
				p2=p2->next;
			}
		}
	}
};

int main() {
	srand(time(0));	
    initgraph(900, 900);
    Sleep(2000);//给玩家反应时间
   // setfillcolor(EGERGB(255, 0, 0));
    snake s1;
    char k;
    bool newfood = 1;
    while(1)
	{
        delay_fps(8);//增加稳定性
        int fx;
        int fy;
        if (newfood) {
            //下面的代码是食物的显示
            //解释：下面坐标为什么是30，因为每个食物or蛇身子是30*30个像素点组成的
            L: fx =rand()%30+1;
            fy = rand()%30+1; //贪吃蛇的食物产生位置是随机的
            fx = fx * 30 - 15;//边缘无法形成900像素图
            fy = fy * 30 - 15;
            bool bo = 1;
            position *p=s1.gettail();
            while (p != s1.gethead()->next) {
                if (p->x == fx && p->y == fy) {
                    bo = 0; //食物不能产生在蛇身体的位置；                  
                    break;
                }
                p = p->next;
            }
            if (!bo) goto L;
            newfood = 0;
        }
        //手动模式：
        if (kbhit()) {
            k = getch();
            switch (k) {
            case 38://上键
                if (s1.getdirection() != 2) s1.setdirection(1);
                break; //根据键值修改对应的方向
            case 40://下键
                if (s1.getdirection() != 1) s1.setdirection(2);
                break;
            case 37://左键
                if (s1.getdirection() != 4) s1.setdirection(3);
                break;
            case 39://右键
                if (s1.getdirection() != 3) s1.setdirection(4);
                break;
            }
        }
        s1.move(fx, fy, newfood);
        cleardevice();
        s1.show();
        setfillcolor(EGERGB(255, 255, 0));//黄色的食物
        bar(fx - 15, fy - 15, fx + 15, fy + 15);//画出食物
        //setfillcolor(EGERGB(0, 255, 0));
        //bar(fx - 15, fy - 15, fx + 15, fy + 15);
        Sleep(100);
    }
   
}
