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
int t=15;
#define pos gotoxy(30,x++)
#define ln  printf(".......................");

using namespace std;
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

void setcolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int timer = 0;
void sett();
void starttyping();
void English();
void Bangla();
void getscore(int accuracy,int speed,int level);
void scorecard();
void help();
void About_me();
string name;

int c=0;
int main();
void console_print(string pin)
{
    int run=pin.size();
    char check[run];

    for(int i=0; i<run; i++)
    {
        if(pin[i]==check[i])
            continue;
        else
        {
            //wrong++;
            break;
        }

    }
}
float random_word(vector <string> big,int level)
{
    int words=0,rigt=0,wrong=0,accuracy,speed;
    int len = big.size();
    float count=0,p=0;
    bool input = false;
    string word,userword;
    int score=0;
    clock_t begin;
    int time_spent;

    int r,letter,ch;

    srand(time(NULL)) ;
    //  x=2;
    //setcolor(12);

    begin=clock();

    while(1)
    {

        time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;
        gotoxy(15,10);
        cout<<"timer::"<<t-time_spent<<".00"<<endl;
        if(time_spent>=t)
        {
            accuracy=(rigt*100)/words;
            speed=(words*60)/t;
            cout<<words<<endl;
            cout<<"Accuracy->"<<accuracy<<endl;
            cout<<"Speed->"<<speed<<"wpm"<<endl;

            if(accuracy>=80&&speed>=35)
                cout<<"Your typing skill is good"<<endl;
            if(accuracy>=80&&speed>=30)
                cout<<"Your typing skill is good but you have to type carefully"<<endl;
            if(accuracy>=60&&speed>=25)
                cout<<"Your typing skill is fairly good ,you have to improve both typing speed and accuracy"<<endl;
            if(accuracy<60&&speed<25)
                cout<<"Your typing skill is bad good ,you have to improve both typing speed and accuracy"<<endl;

            delay(10000);
            getscore(accuracy,speed,level);
            main();
        }
        if(input == false)
        {

            gotoxy(20,3);
            setcolor(25);
            cout<<"....Type the following words...."<<endl;
            gotoxy(36,5) ;
            word = big[rand()%len];
            setcolor(10);
            cout << word << endl;
            words++;
            input = true;

        }
        else
        {
            setcolor(12);
            gotoxy(36,5);
            cin >> userword;
            system("cls");
            if(word == userword)
            {
                gotoxy(31,7);
                ln;
                cout<<endl;
                gotoxy(36,8);
                rigt++;
                cout << "Matched\n";

            }
            else
            {
                wrong++;
                gotoxy(36,8);
                cout << "Unmatched\n";
            }
            input =false;

        }
    }
}
void read_word_by_word(string filename,int level)
{
    system("cls");
    fstream file;
    vector <string> big;
    string word;
    file.open(filename.c_str());
    while(file >> word)
    {
        big.push_back(word);
        //file.close();
    }
    random_word(big,level);
    cout<<endl;
}
fstream readsavefiles, writesavefiles;
fstream userFiles[10];
int totalfiles = 0;

bool check(string name)
{
    string s;
    int tf = totalfiles;
    while(tf--)
    {
        readsavefiles << s;
        if(name == s)
        {
            readsavefiles.close();
            readsavefiles.open("savefile.txt", ios_base::in);
            return true;
        }
    }
    readsavefiles.close();
    readsavefiles.open("savefile.txt", ios_base::in);
    return false;
}

void createFile(string name)
{
    if(!check(name))
    {
        userFiles[totalfiles].open(name+".txt", ios_base::out);
        writesavefiles << name << "\n";
        totalfiles++;
    }
}

int main()
{
    writesavefiles.open("savefile.txt", ios_base::app);
    readsavefiles.open("savefile.txt", ios_base::in);
    time_t t;
    time(&t);
    x=1;
    system("cls");

    setcolor(27) ;
    gotoxy(30,0);
    printf("Welcome to typing test ");
    setcolor(10) ;
    gotoxy(30,1);
    printf("%s",ctime(&t));
    gotoxy(30,2);
    ln pos;
    if(c==0)
    {
        gotoxy(30,3);
        cout<<"Enter typer's name::"<<endl;
        gotoxy(30,4);
        cin>>name;
        createFile(name);
    }
    c++;
    system("cls");
    gotoxy(30,5);
    cout<<"#..MAIN MENU..#"<<endl;
    pos;
    ln
    pos;
    cout<<"1.Start typing"<<endl;
    pos;
    cout<<"2.Scorecard"<<endl;
    pos;
    cout<<"3.Set the time limit::"<<endl;
    pos;
    cout<<"4.Help"<<endl;
    pos;
    cout<<"5.About me"<<endl;
    pos;
    cout<<"0.Exit"<<endl;
    pos;
    cout<<"Enter your choice::"<<endl;
    int ch2;
    gotoxy(30,15);
    cin>>ch2;
    pos;
    switch(ch2)
    {
    case 1:
        starttyping();
        break;
    case 2:
        scorecard();
        break;
    case 3:
        sett();
        main();
    case 4:
        help();
        break;
    case 5:
        About_me();
        break;
    case 0:
        system("cls");
        gotoxy(17,10);
        cout<<"#This project is created by Khandakar Mehedi Hasan#"<<endl;
        delay(1000);
        exit(1);
    default:
        main();
    }

    system("cls");
    // read_word_by_word(name);
}

void starttyping()
{
    system("cls");
    gotoxy(30,03);
    cout<<"Choice Language"<<endl;
    gotoxy(30,04);
    setcolor(12);
    cout<<"1.English"<<endl;
    gotoxy(30,05);
    setcolor(13);
    cout<<"2.Bangla"<<endl;
    gotoxy(30,06);
    setcolor(10);
    cout<<"Enter your choice"<<endl;
    int ch;
    gotoxy(30,07);
    cin>>ch;
    switch(ch)
    {
    case 1:
        English();
    case 2:
        Bangla();
    }
}
void English()
{
    system("cls");
    gotoxy(30,03);
    cout << "Choice difficulty level "<<endl;
    pos;
    gotoxy(30,04);
    cout<<"1.Easy"<<endl;
    gotoxy(30,05);
    cout<<"2.Medium"<<endl;
    gotoxy(30,06);
    cout<<"3.Hard"<<endl;
    gotoxy(30,07);
    cout<<"Enter your choice"<<endl;
    int ch3;
    gotoxy(30,8);
    cin>>ch3;
    switch(ch3)
    {
    case 1:
    {
        read_word_by_word("example.txt",ch3);
        break;
    }
    case 2:
    {
        read_word_by_word("example2.txt",ch3);
        break;
    }
    case 3:
    {
        read_word_by_word("example3.txt",ch3);
        break;
    }
    }
}

void Bangla()
{

    system("cls");
    gotoxy(30,03);
    cout << "Choice difficulty level "<<endl;
    gotoxy(30,04);
    cout<<"1.Easy"<<endl;
    gotoxy(30,05);
    cout<<"2.Medium"<<endl;
    gotoxy(30,06);
    cout<<"3.Hard"<<endl;
    gotoxy(30,07);
    cout<<"Enter your choice"<<endl;
    int ch4;
    gotoxy(30,10);
    cin>>ch4;
    switch(ch4)
    {
    case 1:
    {
        read_word_by_word("b_example.txt",ch4);
        break;
    }
    case 2:
    {
        read_word_by_word("b_example2.txt",ch4);
        break;
    }
    case 3:
    {
        read_word_by_word("b_example3.txt",ch4);
        break;
    }
    }
}

void sett()
{
    int ch6;
    system("cls");
    setcolor(11);
    x=5;
    // pos;
    cout<<"Set the time limit for game in minute::"<<endl;
    ln
    cout<<endl;
    cout<<"Press 0 for half minute"<<endl;
    cout<<"Press 1 for 1 minute"<<endl;
    cout<<"Press 2 for 2 minute"<<endl;

    cin>>ch6;
    switch(ch6)
    {
    case 0:
        t=30;
        break;
    case 1:
        t=60;
        break;
    case 2:
        t=120;
        break;
    default:
        main();
    }
}

void getscore(int accuracy,int speed,int level)
{
    // fstream file(name+".txt", ios_base::app);
    fstream file;
    file.open(name+".txt", ios_base::app);
    file << accuracy << " " << speed << " " << level << "\n";
    file.close();
}


void scorecard()
{
    int ch;
    FILE *fp;
    system("cls");
    x=3;
    cout<<"....The scores are...."<<endl;
    ifstream file("file.txt");
    char ck;
    while (file.get(ck))
    {
        cout << ck;
    }
    file.close();
    delay(15000);
    main();
}

void help()
{
    system("cls");
    gotoxy(7,5);
    setcolor(6);
    cout<<"#......Rules of the Test......#";
    gotoxy(7,6);
    cout<<"=>Enter your name as typer name";
    gotoxy(7,7);
    cout<<"=>Set the time limit under option 3 in main menu(default limit is 30 sec)";
    gotoxy(7,8);
    cout<<"=>You can choice Bangla or English language  :";
    gotoxy(7,9);
    cout<<"=>You can see the scorecard by option 2 in main menu";
    gotoxy(7,10);
    cout<<"=>When you finish the time limit the test will be finished";
    delay(15000);
    main();
}
void About_me()
{
    system("cls");
    gotoxy(7,7);
    cout<<"Hello everyone I am Khandakar Mehedi Hasan ,BSSE-13"<<endl;
    cout<<"I think it would be better....thanks..."<<endl;
    delay(10000);
    main();
}



