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
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

void setcolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
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
int t=10;
int c=0;
float random_word(vector <string> big,int level);
void read_word_by_word(string filename,int level);
/*void console_print(string pin)
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
}*/

int main()
{
    time_t t;
    time(&t);
    setcolor(11) ;
    gotoxy(30,3);
    cout<<"Welcome to typing test"<<endl;
    setcolor(10) ;
    gotoxy(30,2);
    printf("%s",ctime(&t));
    int x=1;
    setcolor(13) ;
    pos;
    ln pos;
    if(c==0)
    {
        cout<<"Enter player's name::"<<endl;
        gotoxy(30,4);
        cin>>name;
    }
    c++;
    system("cls");
    pos;
    ln pos;
    gotoxy(30,4);
    cout<<"#..MAIN MENU..#"<<endl;
    pos;
    ln
    pos;
    cout<<"1.startgame"<<endl;
    pos;
    cout<<"2.scorecard"<<endl;
    pos;
    cout<<"3.Set the time limit::"<<endl;
    pos;
    cout<<"4.Help"<<endl;
    pos;
    cout<<"5.About me"<<endl;
    pos;
    cout<<"0.exit"<<endl;
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
    x=2;
    // pos;
    //setcolor(12);

    begin=clock();

    while(1)
    {

        time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

        if(time_spent>=t)
            break;
        if(input == false)
        {

            gotoxy(20,3);
            cout<<"....Type the following character...."<<endl;
            gotoxy(36,5) ;
            word = big[rand()%len];
            setcolor(10);
            cout << word << endl;
            words++;
            input = true;

        }
        else
        {
            // pos;
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
    accuracy=(rigt*100)/words;
    speed=(words*60)/t;
    cout<<words<<endl;
    cout<<"Accuracy->"<<accuracy<<endl;
    cout<<"Speed->"<<speed<<"wpm"<<endl;

    getscore(accuracy,speed,level);

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
    //cout<<big;
    random_word(big,level);
    cout<<endl;


}

void starttyping()
{
    system("cls");
    gotoxy(30,03);
    cout<<"Choice Language"<<endl;
    gotoxy(30,04);
    cout<<"1.English"<<endl;
    gotoxy(30,05);
    cout<<"2.Bangla"<<endl;
    gotoxy(30,06);
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
    cout<<"2.Midium"<<endl;
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
    //pos;
    ln
    //pos;
    cout<<endl;
    cout<<"press 0 for half minute"<<endl;
    cout<<"press 1 for 1 minute"<<endl;
    cout<<"press 2 for 2 minute"<<endl;

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
    FILE *fp;
    fp=fopen("file.txt","a");
    pos;
    if(fp==NULL)
        printf("error in opening file");
    fprintf(fp,"\nname=%s   accuracy=%d    speed=%d    level=%d",name,accuracy,speed,level);
    fclose(fp);
    pos;
    printf("scorecard updated");
}


void scorecard()
{
    int ch;
    FILE *fp;
    system("cls");
    x=3;
    cout<<"....The scores are...."<<endl;
    fp=fopen("file.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
       cout<<ch;
    }
    main();
}

void help()
{
    system("cls");
    gotoxy(7,5);
    setcolor(6);
    cout<<"#......Rules of the Game......#"<<endl;
    gotoxy(7,6);
    cout<<"=>Enter your name as player name"<<endl;
    gotoxy(7,7);
    cout<<"=>Set the time limit under option 3 in main menu(default limit is 30 sec)"<<endl;
    gotoxy(7,8);
    cout<<"=>select the level and get started :"<<endl;
    gotoxy(7,9);
    cout<<"=>Characters are displayed and you have to type them as fast as you can.."<<endl;
    gotoxy(7,10);
    cout<<"=>Avoid incorrect typing otherwise game will be over.."<<endl;
    delay(5000);
    main();
}
void About_me()
{
    system("cls");
    gotoxy(7,7);
    cout<<"Hello everyone I am Khandakar Mehedi Hasan ,BSSE-13"<<endl;
    printf(".I think it would be better....thanks...");
    main();
}

