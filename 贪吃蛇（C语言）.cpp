//������Ҫ��egeͼ�ο⣡��

#include<stdio.h> 
#include<graphics.h>//egeͼ�ο�Ļ�ͼ��
#include<windows.h> 
#include<stdlib.h> 
#include<time.h>//ʱ�������õ�

struct position//���������
{
    int x;//��Եĺ�����
    int y;//��Ե�������
    struct position *next;
};
typedef struct position position;
int direction=4;
position *head=(position *)malloc(sizeof(position));
position *tail=(position *)malloc(sizeof(position));
int Time=100;//Ĭ���Ѷȵ��ƶ��� ��Ϊ100ms

void move(int xx,int yy,int *newfood,int direction)
{
	switch(direction)
	{
		position *p;
		int x0,y0;
		case 1://�����ƶ���ʱ������겻�䣬���������30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0;
			head->y=y0-30;
			p=tail->next;
			free(tail);//ɾ��β��ԭ���Ǹ��ط�
			tail=p;//β���ƶ�
			break;
		case 2://�����ƶ���ʱ������겻�䣬����������30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0;
			head->y=y0+30;
			p=tail->next;
			free(tail);//ԭ��ͬ��
			tail=p;
			break;
		case 3://�����ƶ���ʱ�������겻�䣬���������30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0-30;
			head->y=y0;
			p=tail->next;
			free(tail);//ԭ��ͬ��
			tail=p;
			break;
		case 4://�����ƶ���ʱ�������겻�䣬����������30
			head->next=(position *)malloc(sizeof(position));
			x0=head->x;
			y0=head->y;
			head=head->next;
			head->x=x0+30;
			head->y=y0;
			p=tail->next;
			free(tail);//ԭ��ͬ��
			tail=p;
			break;					
	}
	if(head->x==xx&&head->y==yy)//�Ե���
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
            //setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
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
            //closegraph();
            
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
		//����Ϊ���߽��г�ʼ����������ͷ��β���Լ��м�һ�ڹ�����
		srand(time(0));//����������ӣ���֤ÿ�������������һ��
		initgraph(900,900);//����900 ��900�Ļ�ͼ����
		Sleep(2000);//����ҷ�Ӧʱ��
		char direc;
		int food=1;
		while(1)
		{
			int xx,yy;
			if(food)//����ʳ��λ��
			{
				start:
				//���ͣ���������Ϊʲô��30����Ϊÿ��ʳ��or��������30*30�����ص���ɵ�
				xx=rand()%30+1;//1-30�����
				yy=rand()%30+1;//1-30�����
				xx=xx*30-15;//��Ե�޷��γ�900����ͼ
				yy=yy*30-15;
				int flag=1;//Ĭ��ʳ��������غ�
				position *p=tail;//��λ��β��
				while(p!=head->next)//��������
				{//��ÿ��������ʳ��λ�����Ƚ�
					if(p->x==xx&&p->y==yy)
					{
						flag=0;//����ʳ�����������ߵ�����
						break;
					}
					p=p->next;
				}
				if(!flag) goto start;
				food=0;
			}
			if(kbhit())//�ж��Ƿ��а�������
			{
				direc=getch();
				switch(direc)
				{
					case 38://�ϼ��ļ���
					        if(direction!=2) direction=1;
					        break; //���ݼ�ֵ�޸Ķ�Ӧ�ķ���
					case 40://�¼�
					        if(direction!=1) direction=2;
					        break;
					case 37://���
					        if(direction!=4) direction=3;
					        break;
					case 39://�Ҽ�
					        if(direction!=3) direction=4;
					        break;				
				}
			}
			move(xx,yy,&food,direction);
			cleardevice();//����
			show();
			setfillcolor(EGERGB(255, 255,0));//��ɫ��ʳ��
			bar(xx-15,yy-15,xx+15,yy+15);//����ʳ��
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
	puts("\t���Ŀ���ǳԵ�����Ķ��ӣ��õ����ߵķ�����\n");
	puts("\t�á��ϡ��¡����ҡ������ߵķ���\n");
	puts("\t������ʾ��ײ��ǽ��/ͷײ������ʱ����Ϸ����\n");
	puts("\t��ӭ������ս��\n");
}
int mode()
{
	int n;
	printf("\t��ѡ����Ҫ��ս���Ѷ�\n");
	printf("\t0-������һ��\n");
	printf("\t1-����\n");
	printf("\t2-��\n");
	printf("\t3-�е�\n");
	printf("\t4-����\n");
	printf("\t5-ج��\n");
	printf("\t6-����\n");
	printf("\t����������ѡ�");
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
		printf("\t��ӭ��������̰���ߣ�\n");
		printf("\t1-��ʼ��Ϸ\n");
		printf("\t2-��Ϸ˵��\n");
		printf("\t3-�Ѷ�����\n");
		printf("\t0-�˳���Ϸ\n");
		printf("\t����������ѡ�");
		scanf("%d",&n);
		system("cls");
		switch(n)
		{
			case 1:
				{
					printf("\t1-��׼ģʽ(�ٶȺ㶨��Ϊ���õ��Ѷ�)\n");
					printf("\t2-����ģʽ(�ٶ���ʱ��������)\n");
					printf("\t��ѡ��������Ϸģʽ��");
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
	printf("��Ϸ������\n");
}
