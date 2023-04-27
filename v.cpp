#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<ctime>
#include<vector>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>
//#include<graphics.h>
static int x=1;
#define pos gotoxy(30,x++)
#define ln  printf(".......................");
using namespace std;
void delay(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int timer = 0;int t=30;clock_t begin;
    int time_spent;

   // srand(time(NULL)) ;

    //setcolor(12);
int main(){
    begin=clock();

    while(1)
    {

        time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;
         gotoxy(15,10);
        cout<<"timer::"<<t-time_spent<<".00"<<endl;
        system("cls");
    }
}
