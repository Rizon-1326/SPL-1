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
#define pos gotoxy_custom(30,x++)
#define ln  printf(".......................");
using namespace std;

void delay(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

COORD coord= {0,0};

void gotoxy_custom(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    int timer = 0;
    int t=30;
    clock_t begin = clock();
    int time_spent;

    while(1)
    {
        time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

        gotoxy_custom(15,10);
        cout<<"timer::"<<t-time_spent<<".00"<<endl;
        system("cls");
    }
    return 0;
}
