#include<stdio.h>
#include<windows.h>
#include<stdlib.h>                                                          
#include<conio.h>
#define HENG 80
#define SHU 25  //HENG�ǿ�ȣ�SHU�Ǹ߶�
#define TIME 200 //�ߵĳ�ʼ�ٶ�
void Gotoxy(int x, int y);
void Food(struct SHE *head);
void FreeShe(struct SHE *head);
void Gameover(void);
void Huitu(struct SHE *head);
int Panduan(struct SHE *head, int x, int y);
int Move(struct SHE *head);
int Fx, Fy;  //ʳ���λ��
int fen;   //�÷�
int fang; //�������
int Tx, Ty;
struct SHE *Link(struct SHE *head);

