#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define HENG 80
#define SHU 25  //HENG�ǿ�ȣ�SHU�Ǹ߶�
#define TIME 400 //�ߵĳ�ʼ�ٶ�
int Fx, Fy;  //ʳ���λ��
int fen;   //�÷�
int fang; //�������
int Tx, Ty;//��������
int Panduan(struct SHE *head, int x, int y);
//int temp;    
int Move(struct SHE *head);
void Food(struct SHE *head);
void Gotoxy(int x, int y);
void Huitu(struct SHE *head);
void FreeShe(struct SHE *head);
void Gameover(void);
struct SHE *Link(struct SHE *head);
struct SHE
{
    int x;
    int y;
    struct SHE *next;
};

int main(void)
{
    struct SHE *head = NULL;
    int temp;
    int times = TIME;
    char m;
    do
    {
        fen = 0;
        fang = 2;
        temp = fen;
        times = TIME;
        head = NULL;
        head = (struct SHE *)malloc(sizeof(struct SHE));
        head -> x = 40;
        head -> y = 13;
        head -> next = NULL;
        Food(head);
        while (1)
        {
            Huitu(head);
            Sleep(times);
            if (0 == Move(head))
            {
                FreeShe(head);
                Gameover();
                break;
            }
            if (temp < fen)
            {
                Food(head);
                temp = fen;
                if (times > 50)
                {
                    times -=10;
                }
                else if (times > 20)
                {
                    times -=1;
                }
                else
                    ;
            }
        }
        do
        {
            Gotoxy(19,21);
            printf("�Ƿ������Y/N:");
            scanf(" %c", &m);
            system("cls");
        }
 while (m != 'Y' && m != 'y' && m != 'n' && m != 'N');
    }
 while (m == 'Y' || m == 'y');
    return 0;
}//��ͼ
void Huitu(struct SHE *head)
{
    int flag = 1;
    while (head != NULL)
    {
        Gotoxy(head -> x, head -> y);
        if (flag == 1)
        {
            printf("��");
        }
        else if (flag == 2)
        {
            printf("��");
        }
        else
            ;
        Gotoxy(Tx, Ty);
        printf(" ");
        flag++;
        head = head -> next;
    }
}//���ڹ����ƶ�
void Gotoxy(int x, int y)
{
  COORD coord; 
  coord.X = x; 
  coord.Y = y; 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}//ʳ��λ��
void Food(struct SHE *head)
{
    int flag = 0;
    struct SHE *pr = head;
    do
    {
        srand(GetTickCount());
        Fx = (rand()%40) * 2;
        Fy = (rand()%12) * 2;
        flag = 0;
        pr = head;
        while (pr != NULL) //��ֹʳ��λ���������غ�
        {
            if (pr -> x == Fx && pr -> y == Fy)
            {
                flag = 1;
                break;
            }
            pr = pr -> next;
        }
    }
 while (flag == 1);
    Gotoxy(Fx, Fy);
    printf("��");
}//�����ߵ��ƶ�


int Move(struct SHE *head)
{
    char op;
    int tox, toy, flag;
    if (kbhit())
    {
        op = getch();
        switch (op)
        {
            case 'w':
                if (fang != 3)
                fang = 1;
                break;
            case 'd':
                if (fang != 4)
                fang = 2;
                break;
            case 's':
                if (fang != 1)
                fang = 3;
                break;
            case 'a':
                if (fang != 2)
                fang = 4;
                break;
            default:
                break;
        }
    }	
    switch (fang)
    {
        case 1:
            toy = (head -> y) - 1;
            tox = (head -> x);
            break;
        case 2:
            tox = (head -> x) + 2;
            toy = (head -> y);
            break;
        case 3:
            toy = (head -> y) + 1;
            tox = (head -> x);
            break;
        case 4:
            tox = (head -> x) - 2;
            toy = (head -> y);
            break;
        default:
            break;
	}
 while (flag == 1);
    Gotoxy(Fx, Fy);
    printf("��");
};//�����ߵ��ƶ�
flag = Panduan(head,tox,toy);
   if(flag == 0)
   {
	   return 0;//��Ϸ����
   }


