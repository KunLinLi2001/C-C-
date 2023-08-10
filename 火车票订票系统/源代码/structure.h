//********************
//    structure.h
//********************

struct train//火车的信息 
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

struct man//个人的信息 
{
	char Num[10];//个人的订单的那个序号 以便区分不同信息 
	
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
