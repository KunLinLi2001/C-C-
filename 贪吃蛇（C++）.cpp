//������Ҫ��egeͼ�ο⣡��
#include<iostream>
#include<graphics.h> 
#include<windows.h> 
#include<cstdlib> 
#include<ctime>
using namespace std;

struct position//���������
{
    int x;//��Եĺ�����
    int y;//��Ե�������
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
    	void settail(position *p){tail=p;}//��β����Ҳ��������β��
    	position *gethead() {return head;}
   		void sethead(position *p) {head=p;}
    	snake() //�������ʼ��
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
        	direction=4;//1 2 3 4�������ĸ�����
    	}
    	void setdirection(int a){direction=a;}
    	int getdirection(){return direction;}
    	void move(int x0, int y0, bool &newfood)
		{
        	switch (direction) {
            position *p;
            int xt;
            int yt;
        	case 1://�����ƶ���ʱ������겻�䣬���������30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head->next;
                head->x = xt;
                head->y = yt - 30;
                p = tail->next;
                delete tail;//ɾ��β��ԭ���Ǹ��ط�
                tail = p;//β���ƶ�
                break;
            }
        case 2://�����ƶ���ʱ������겻�䣬����������30
            {
                head->next = new position;
                xt = head->x;
                yt = head->y;
                head = head->next;
                head->x = xt;
                head->y = yt + 30;
                p = tail->next;
                delete tail;//ԭ��ͬ��
                tail = p;
                break;
            }
        case 3://�����ƶ���ʱ�������겻�䣬���������30
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
        case 4://�����ƶ���ʱ�������겻�䣬����������30
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
        if (head->x==x0&&head->y==y0) {//�Ե���
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
		int sum=0;//�����ӵĳ��ȣ�Ҳ���ǵ÷�
		while(p!=head->next)
		{
			sum++;
			if(head->x>0&&head->x<900&&head->y>0&&head->y<900)
			{
				setfillcolor(EGERGB(255, 0, 0));//����Ϳɫ
				bar(p->x-15,p->y-15,p->x+15,p->y+15);//������
				setfillcolor(EGERGB(255, 0, 255));//�������ԵͿɫ
				bar(p->x-13,p->y-13,p->x+13,p->y+13);//��ÿһ���ߵ�����
				p=p->next;
			}
			else//��ײǽ��
			{
	            //setcolor(EGERGB(255, 0, 0));
	            setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	            setfont(100, 0, "����");
	            outtextxy(250, 360, "��Ϸ����");
	            if (sum<10) outtextxy(100, 460, "��ʦ�����ֽ���");
	            if (sum>=10&&sum<20) outtextxy(100,460,"��ʦ��С��ţ��");
	            setfont(70, 0, "����");
	            if (sum>=20&&sum<30)
				outtextxy(250, 460, "��ʦˮƽ����~");
	            if(sum>=30)outtextxy(250, 460, "��ʦ��̫ǿ�ˣ�");
	            Sleep(2000);
	            getch();
	            closegraph();
	            return;			
			}
			int hx,hy;
			hx=head->x;
			hy=head->y;
			position *p2=tail;
			while(p2!=head)//��ײ�����Լ�
			{
				if(hx==p2->x&&hy==p2->y)
				{
					//setcolor(EGERGB(255, 0, 0));
					setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
					setfont(100, 0, "����");
					outtextxy(250, 360, "��Ϸ����");
					if (sum<10) outtextxy(100, 460, "��ʦ�����ֽ���");
					if (sum>=10&&sum<20) outtextxy(100,460,"��ʦ��С��ţ��");
					setfont(70, 0, "����");
					if (sum>=20&&sum<30)
					outtextxy(250, 460, "��ʦˮƽ����~");
					if(sum>=30)outtextxy(250, 460, "��ʦ��̫ǿ�ˣ�");
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
    Sleep(2000);//����ҷ�Ӧʱ��
   // setfillcolor(EGERGB(255, 0, 0));
    snake s1;
    char k;
    bool newfood = 1;
    while(1)
	{
        delay_fps(8);//�����ȶ���
        int fx;
        int fy;
        if (newfood) {
            //����Ĵ�����ʳ�����ʾ
            //���ͣ���������Ϊʲô��30����Ϊÿ��ʳ��or��������30*30�����ص���ɵ�
            L: fx =rand()%30+1;
            fy = rand()%30+1; //̰���ߵ�ʳ�����λ���������
            fx = fx * 30 - 15;//��Ե�޷��γ�900����ͼ
            fy = fy * 30 - 15;
            bool bo = 1;
            position *p=s1.gettail();
            while (p != s1.gethead()->next) {
                if (p->x == fx && p->y == fy) {
                    bo = 0; //ʳ�ﲻ�ܲ������������λ�ã�                  
                    break;
                }
                p = p->next;
            }
            if (!bo) goto L;
            newfood = 0;
        }
        //�ֶ�ģʽ��
        if (kbhit()) {
            k = getch();
            switch (k) {
            case 38://�ϼ�
                if (s1.getdirection() != 2) s1.setdirection(1);
                break; //���ݼ�ֵ�޸Ķ�Ӧ�ķ���
            case 40://�¼�
                if (s1.getdirection() != 1) s1.setdirection(2);
                break;
            case 37://���
                if (s1.getdirection() != 4) s1.setdirection(3);
                break;
            case 39://�Ҽ�
                if (s1.getdirection() != 3) s1.setdirection(4);
                break;
            }
        }
        s1.move(fx, fy, newfood);
        cleardevice();
        s1.show();
        setfillcolor(EGERGB(255, 255, 0));//��ɫ��ʳ��
        bar(fx - 15, fy - 15, fx + 15, fy + 15);//����ʳ��
        //setfillcolor(EGERGB(0, 255, 0));
        //bar(fx - 15, fy - 15, fx + 15, fy + 15);
        Sleep(100);
    }
   
}
