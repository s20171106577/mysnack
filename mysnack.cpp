#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define HENG 80
#define SHU 25  //HENG�ǿ�ȣ�SHU�Ǹ߶�
struct SHE
#define TIME 400 //�ߵĳ�ʼ�ٶ�
int Fx, Fy;  //ʳ���λ��
int fen;   //�÷�
int fang; //�������
int Tx, Ty;//��������
{
    int x;
    int y;
    struct SHE *next;
};
void Food(struct SHE *head);
int Move(struct SHE *head);
void Gotoxy(int x, int y);
void Huitu(struct SHE *head);
struct SHE *Link(struct SHE *head);
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
		void FreeShe(struct SHE *head);
		void Gameover(void);
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

      