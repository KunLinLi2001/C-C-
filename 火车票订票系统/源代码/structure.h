//********************
//    structure.h
//********************

struct train//�𳵵���Ϣ 
{
	char num[10];
	char startcity[10];
	char reachcity[10];
	char starttime[10];
	char reachtime[10];
	int price;
	int ticketnum;
	struct train *next;
};

struct man//���˵���Ϣ 
{
	char Num[10];//���˵Ķ������Ǹ���� �Ա����ֲ�ͬ��Ϣ 
	
	char id[20];
	char name[10];
	int booknum;
	struct man *next;
	
	char num[10];
	char startcity[10];
	char reachcity[10];
	char starttime[10];
	char reachtime[10];
	int price;
	 
};

typedef struct train node;
typedef struct man book;

void menu();
void addtrain(node *head);
void searchtrain(node *head);
void preserve(node *head,book *Head);
void modifytrain(node *head);
void modifyman(node *head,book *Head);
void showman(book *Head,int *a);
void showtrain(node *head,int *a);
void cloud(node *head,book *Head);
void read(node *head,book *Head);
