#include<stdio.h>
#include<windows.h>
#include<stdlib.h>                                                          
#include<conio.h>
#define HENG 80
#define SHU 25  //HENG是宽度，SHU是高度
#define TIME 200 //蛇的初始速度
void Gotoxy(int x, int y);
void Food(struct SHE *head);
void FreeShe(struct SHE *head);
void Gameover(void);
void Huitu(struct SHE *head);
int Panduan(struct SHE *head, int x, int y);
int Move(struct SHE *head);
int Fx, Fy;  //食物的位置
int fen;   //得分
int fang; //方向参数
int Tx, Ty;
struct SHE *Link(struct SHE *head);

