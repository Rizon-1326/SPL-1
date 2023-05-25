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
#include<graphics.h>
static int x=1;
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

void setTextColor(int ForgC)
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
void sett();
int c_timer;
void starttyping();
void English();
void Another_language();
void read_word_by_word(string filename);
void getscore(string tarikh,int accuracy,int speed);
void scorecard();
void help();
void About_me();
void Graphical_viewOfSpeed();
void Graphical_viewOfAccuracy();
void Block_diagramOfSpeed();
void Block_diagramOfAccuracy();
int main();

void createFile(string name);
bool check(string name);
fstream readsavefiles, writesavefiles;
fstream userFiles[10];
int totalfiles = 0;

int accuracy,speed;

void gotoxy(int x,int y);
string lines;
string input="",output;
vector<char>v;
vector<int>redflag;
int j=0,k=0;
vector<string> words;
void makeDecision1(string input);
void makeDecision2(string input,char letter);
string name;
int character=0,wrcharacter=0,shobdo=0;
int resultAccuracy(int characte,int wrcharacter);
int resultSpeed(int shobdo);
string tarikh;

int c=0;

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
    //readsavefiles.close();
    //readsavefiles.open("savefile.txt", ios_base::in);
    //return false;
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

void toMain()
{
    setTextColor(3);
    cout<<"Press 1 for main menu"<<endl;
    int again;
    cin>>again;
    if(again==1)main();
}

void starttyping()
{
    English();
    return;
}


void English()
{
    system("cls");
    gotoxy(30,03);
    cout << "Choice The text "<<endl;
    pos;
    gotoxy(30,04);
    setcolor(1);
    cout<<"1.The first President of South Africa to be elected in ..."<<endl;
    gotoxy(30,05);
    setcolor(2);
    cout<<"2.Sheikh Mujibwas a leading figure as the leader of ..."<<endl;
    gotoxy(30,06);
    setcolor(3);
    cout<<"3.it was founded at the end of the 13th century in northwestern ..."<<endl;
    gotoxy(30,07);
    setcolor(4);
    cout<<"Enter your choice"<<endl;
    int ch3;
    gotoxy(30,8);
    ch3 = rand()%3;
    switch(ch3)
    {
    case 0:
    {
        read_word_by_word("Mandela.txt");
        break;
    }
    case 1:
    {
        read_word_by_word("Bangabandhu.txt");
        break;
    }
    case 2:
    {
        read_word_by_word("Ottoman.txt");
        break;
    }
    }
}

void Another_language()
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
        read_word_by_word("b_example.txt");
        break;
    }
    case 2:
    {
        read_word_by_word("b_example2.txt");
        break;
    }
    case 3:
    {
        read_word_by_word("b_example3.txt");
        break;
    }
    }
}

void read_word_by_word(string filename)
{

    vector <string> big;
    string word;
    int AC,SP;
    //file.open(filename.c_str());
    ////->->
    cout<<"Set time limit"<<endl;
    sett();

    ifstream file(filename);

    gotoxy(0,00);

    if (file.is_open())
    {
        while (getline(file, lines))
        {
            // Process the line here
            output += lines ;
        }
        cout << output;
        file.close();
    }

    while (getline(file, lines))
    {
        istringstream iss(lines);

        string word;

        while (iss >> word)
        {
            words.push_back(word);
        }

    }

    auto start = chrono::high_resolution_clock::now();
    int elapsed_time = 0;
    string typedSoFar = "";
    int k_time=c_timer;
    while (elapsed_time<k_time)
    {
        auto current_time = chrono::high_resolution_clock::now(); //get the current time
        auto duration = chrono::duration_cast<chrono::seconds>(current_time - start);
        elapsed_time = duration.count(); //update the elapsed time

        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        // Extract the date components
        int year = localTime->tm_year + 1900;
        int month = localTime->tm_mon + 1;
        int day = localTime->tm_mday;
        // Print the current date
        gotoxy(30, 05);
        setTextColor(13);
        cout << "Today's date is: " << year << "-" << month << "-" << day <<endl;

        tarikh=to_string(year)+".";
        tarikh=tarikh+to_string(month)+".";
        tarikh=tarikh+to_string(day);

        if(elapsed_time==c_timer)
        {
            //cout<<character<<" "<<wrcharacter<<endl;
            accuracy=resultAccuracy(character,wrcharacter);
            speed=resultSpeed(shobdo);
            gotoxy(30,07);
            setcolor(1);
            cout<<"Accuracy is:"<<accuracy<<"%"<<endl;
            setcolor(3);
            cout<<"Speed is:"<<speed<<"wpm"<<endl;
            getscore(tarikh,accuracy,speed);
            Sleep(3000);
            system("cls");
            gotoxy(30,05);
            toMain();
            setTextColor(3);

        }

        for (int i = 0; i <= 255; i++)
        {

            if (GetAsyncKeyState(i) == -32767)
            {


                if (GetAsyncKeyState(VK_SPACE) & 0x8000)
                {

                    char letter=' ' ;
                    shobdo++;
                    input += letter;
                    gotoxy(00, 0);
                    if(output[j]==letter)
                    {
                        makeDecision1(input);
                    }
                    else
                    {
                        makeDecision2(input,letter);
                    }
                }
                else if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
                {

                    char letter = (GetKeyState(VK_SHIFT) & 0x8000) ? (char)i : (char)(i + 32);
                    input += letter;
                    if(output[j]==letter)
                    {

                        makeDecision1(input);
                    }
                    else
                    {
                        makeDecision2(input,letter);

                    }
                }
                else if(i>=48&&i<=57)
                {
                    char letter=(char)i;
                    input=input+letter;
                    gotoxy(0,0);
                    if(output[j]==letter)
                    {

                        makeDecision1(input);
                    }
                    else
                    {
                        makeDecision2(input,letter);
                        //for(auto val : v) cout << val;
                    }
                    // cout << input ;
                }
                else if (i == VK_OEM_COMMA)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        char letter='<';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                    }

                    else
                    {
                        char letter=',';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                        // gotoxy(00,0);
                        // cout << input ;
                    }
                }
                else if (i == VK_OEM_PERIOD)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        char letter='>';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }

                    }
                    else
                    {
                        char letter='.';
                        input=input+letter;

                    }
                }
                else if (i == VK_OEM_2)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        char letter='?';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }

                    }
                    else
                    {
                        char letter='/';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                    }
                }

                else if (i == VK_OEM_4)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        char letter='{';
                        input=input+letter;    // Use a different character for Shift+comma
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                    }
                    else
                    {
                        char letter='[';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                        // gotoxy(00,0);
                        // cout << input ;
                    }

                }
                else if (i == VK_OEM_6)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        char letter='}';
                        input=input+letter;    // Use a different character for Shift+comma
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                    }
                    else
                    {
                        char letter=']';
                        input=input+letter;
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }
                        //gotoxy(00,0);
                        //cout << input ;
                    }
                }

                else if (i >= VK_NUMPAD0 && i <= VK_NUMPAD9)
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        // Handle shift + numeric character
                        char letter;
                        switch (i)
                        {
                        case VK_NUMPAD0:
                        {
                            letter=')';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD1:
                        {
                            letter='!';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD2:
                        {
                            letter='@';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD3:
                        {
                            letter='#';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD4:
                        {
                            letter='$';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD5:
                        {
                            letter='%';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD6:
                        {
                            letter='^';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD7:
                        {
                            letter='&';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD8:
                        {
                            letter='*';
                            input += letter;
                            break;
                        }
                        case VK_NUMPAD9:
                        {
                            letter='(';
                            input += letter;
                            break;
                        }
                        if(output[j]==letter)
                        {
                            makeDecision1(input);
                        }
                        else
                        {
                            makeDecision2(input,letter);
                        }

                        }
                    }

                }
            }
        }


        gotoxy(30,04);
        setTextColor(10);
        cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
        // cout<<name;
        this_thread::sleep_for(chrono::microseconds(1));
    }

    file.close();
    system("cls");
}

void getscore( string date,int ac,int sp)
{
    ofstream file(name+".txt", ios::app);

    if (file.is_open())
    {

        file <<" "<<ac << "         " << sp <<"         "<<date <<endl;

        file.close();
    }
}

void sett()
{
    int ch6;
    system("cls");
    gotoxy(30,05);
    setTextColor(11);
    x=5;
    // pos;
    cout<<"Set the time limit for game in minute::"<<endl;

    cout<<endl;
    gotoxy(30,06);
    setTextColor(2);
    cout<<"Press 0 for   30 seconds";
    gotoxy(30,07);
    cout<<"Press 1 for   60 seconds";
    gotoxy(30,8);
    cout<<"Press 2 for   120 seconds";

    cin>>ch6;
    switch(ch6)
    {
    case 0:
        c_timer=30;
        break;
    case 1:
        c_timer=60;
        break;
    case 2:
        c_timer=120;
        break;
    default:
        main();
    }
    system("cls");
}

int resultAccuracy(int character,int wrcharacter)
{
   // cout<<character<<" "<<wrcharacter<<endl;
    Sleep(5000);
    int kp=character+wrcharacter;
    accuracy=((double)(character)/(kp))*100;
    return accuracy;
}
int resultSpeed(int shobdo)
{
    speed=(shobdo*60)/c_timer;
    return speed;
}

void Block_diagramOfSpeed()
{
    system("cls");
    //gotoxy(30,4);
    ifstream infile(name+".txt");

    vector<string> Dates;
    vector<int> Accs;
    vector<int> spds;

    string Dat;
    int acc,spd;

    while (infile >> acc >> spd>> Dat)
    {
        Dates.push_back(Dat);
        Accs.push_back(acc);
        spds.push_back(spd);
    }
    setTextColor(6);
    cout<<"Block Diagram of Speed(wpm)"<<endl;
    const int max_bar_width = 50;
    int max_speed = 0;
    for (int i = 0; i < spds.size(); i++)
    {
        max_speed = max(max_speed, spds[i]);
    }
    int max_bar_height = 20;
    int x_offset = 2;
    int y_offset = 1;
    setTextColor(2);
    for (int i = 0; i <Dates.size(); i++)
    {
        // gotoxy(30,4);
        setTextColor(2);
        cout << Dates[i] << ": ";
        int bar_width = max_bar_width * spds[i] / max_speed;
        int bar_height = max_bar_height;
        setTextColor(3);
        for (int j = 0; j < bar_width; j++)
        {
            cout << "I";
        }
        cout << endl;
    }
    gotoxy(50,20);
    setTextColor(6);
    cout<<"1 for main menu"<<endl;
    int cp;
    gotoxy(50,20);
    cin>>cp;
    if(cp==1)
        main();
}

void Block_diagramOfAccuracy()
{
    system("cls");
    //gotoxy(30,4);
    ifstream infile(name+".txt");

    vector<string> Dates;
    vector<int> Accs;
    vector<int> spds;

    string Dat;
    int acc,spd;

    while (infile >> acc >> spd>> Dat)
    {
        Dates.push_back(Dat);
        Accs.push_back(acc);
        spds.push_back(spd);
    }
    setTextColor(6);
    cout<<"Block Diagram of Accuracy(%)"<<endl;
    const int max_bar_width = 50;
    int max_accuracy = 0;
    for (int i = 0; i < spds.size(); i++)
    {
        max_accuracy = max(max_accuracy,Accs[i]);
    }
    int max_bar_height = 20;
    int x_offset = 2;
    int y_offset = 1;
    setTextColor(2);
    for (int i = 0; i <Dates.size(); i++)
    {
        // gotoxy(30,4);
        setTextColor(2);
        cout << Dates[i] << ": ";
        int bar_width = max_bar_width * Accs[i] / max_accuracy;
        int bar_height = max_bar_height;
        setTextColor(3);
        for (int j = 0; j < bar_width; j++)
        {
            cout << "I";
        }
        cout << endl;
    }
    gotoxy(50,20);
    setTextColor(4);
    cout<<"1 for main menu"<<endl;
    int cp;
    setTextColor(6);
    gotoxy(50,20);
    cin>>cp;
    if(cp==1)
        main();
}

void Graphical_viewOfSpeed()
{
    system("cls");
    //gotoxy(30,4);
    ifstream infile(name+".txt");

    vector<string> Dates;
    vector<int> Accs;
    vector<int> spds;

    string Dat;
    int acc,spd;

    while (infile >> acc >> spd>> Dat)
    {
        Dates.push_back(Dat);
        Accs.push_back(acc);
        spds.push_back(spd);
    }

    initwindow(500, 500, "Results Graph");

    int x = 100;
    int y = 400;
    int bar_width = 50;
    int max_result = *max_element(spds.begin(),spds.end());
    int max_bar_height = 200;
    int text_offset = 15;
    const char* title="Graphical view of speed(wpm)";
    int titleX = 30;
    int titleY = 40;

    for (int i = 0; i < Dates.size(); i++)
    {
        int bar_height = (spds[i] * max_bar_height) / max_result;
        int bar_y = y - bar_height;

        setfillstyle(SOLID_FILL, LIGHTMAGENTA);
        bar(x, bar_y, x + bar_width, y);

        const char* Date_cstr = Dates[i].c_str();
        outtextxy(x, y + text_offset, const_cast<char*>(Date_cstr));

        char spd_str[20];
        sprintf(spd_str, "%d", spds[i]);
        outtextxy(70, bar_y, spd_str);

        x += bar_width + 50;
    }
    setcolor(WHITE);

    settextstyle(BOLD_FONT, HORIZ_DIR,2);
    outtextxy(titleX, titleY, const_cast<char*>(title));


    getch();
    closegraph();
    gotoxy(30,10);
    cout<<"Press 1 for main menu"<<endl;
    int cp;
    cin>>cp;
    if(cp==1)
        main();
}
void Graphical_viewOfAccuracy()
{
    system("cls");
    //gotoxy(30,4);
    ifstream infile(name+".txt");

    vector<string> Dates;
    vector<int> Accs;
    vector<int> spds;

    string Dat;
    int acc,spd;

    while (infile >> acc >> spd>> Dat)
    {
        Dates.push_back(Dat);
        Accs.push_back(acc);
        spds.push_back(spd);
    }

    initwindow(500, 500, "Results Graph");

    int x = 100;
    int y = 400;
    int bar_width = 50;
    int max_result = *max_element(Accs.begin(),Accs.end());
    int max_bar_height = 500;
    int text_offset = 15;
    const char* title="Graphical view of Accuracy(%)";
    int titleX = 30;
    int titleY = 40;

    for (int i = 0; i < Dates.size(); i++)
    {
        int bar_height = (spds[i] * max_bar_height) / max_result;
        int bar_y = y - bar_height;

        setfillstyle(SOLID_FILL, LIGHTMAGENTA);
        bar(x, bar_y, x + bar_width, y);

        const char* Date_cstr = Dates[i].c_str();
        outtextxy(x, y + text_offset, const_cast<char*>(Date_cstr));

        // Show the result value on the Y-axis
        char Acc_str[20];
        sprintf(Acc_str, "%d", Accs[i]);
        outtextxy(70, bar_y, Acc_str);

        x += bar_width + 50;
    }
    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR,2);

    // Draw the title with the updated color and font size
    outtextxy(titleX, titleY, const_cast<char*>(title));


    getch();
    closegraph();
    gotoxy(30,10);
    cout<<"Press 1 for main menu"<<endl;
    int cp;
    cin>>cp;
    if(cp==1)
        main();
}

void scorecard()
{
    int ch;
    FILE *fp;
    system("cls");
    x=3;
    setTextColor(1);
    cout<<"....The scores are...."<<endl;
    setTextColor(2);
    cout<<"Accuracy(%) Speed(wpm)      Date"<<endl;
    ifstream file(name+".txt");
    char ck;
    setTextColor(3);
    while (file.get(ck))
    {
        cout << ck;
    }
    file.close();
    gotoxy(40,10);
    cout<<"1 for main menu"<<endl;
    int cp;
    gotoxy(40,10);
    cin>>cp;
    if(cp==1)
        main();
}

void help()
{
    system("cls");
    gotoxy(7,5);
    setTextColor(1);
    cout<<"#......Rules of the Test......#";
    gotoxy(7,6);
    setTextColor(2);
    cout<<"=>Enter your name as typer name ";
    gotoxy(7,7);
    setTextColor(3);
    cout<<"=>Press option no 2 to see the scorecard";
    gotoxy(7,8);
    setTextColor(4);
    cout<<"=>Press option no 3 to know the process of this typing master ";
    gotoxy(7,9);
    setTextColor(5);
    cout<<"=>Press option no 4 to 7 to see the Graphical view of Speed and Accuracy"<<endl;
    int cp;
    setTextColor(3);
    gotoxy(30,10);
    cout<<"Press 1 for main menu"<<endl;
    gotoxy(30,10);
    cin>>cp;
    if(cp==1)
        main();
}
void About_me()
{
    system("cls");
    gotoxy(7,7);
    cout<<"Hello everyone I am Khandakar Mehedi Hasan ,BSSE-13"<<endl;
    cout<<"I think it would be better....thanks..."<<endl;
    gotoxy(30,10);
    cout<<"Press 1 for main menu"<<endl;
    int cp;
    cin>>cp;
    if(cp==1)
        main();
}

void makeDecision1(string input)
{
    character++;
    //gotoxy(0,0);
    system("cls");
    for(int i=0; i<j; i++)
    {
        if(find(redflag.begin(), redflag.end(), i) != redflag.end())
        {
            setTextColor(12);
            cout << output[i];
        }
        else
        {
            setTextColor(10);
            cout << output[i];
        }
    }
    for(int i=j; i<output.length(); i++)
    {
        setTextColor(7);
        cout<<output[i];
    }
    j++;
    //gotoxy(0,00);
    //cout<<output;
}
void makeDecision2(string input,char letter)
{
    wrcharacter++;
    system("cls");
    if(letter!=' '&&output[j]!=' ')
    {
        //gotoxy(0,00);
        for (int i = 0; i <j-1; i++)
        {
            if(find(redflag.begin(), redflag.end(), i) != redflag.end())
            {
                setTextColor(12);
                cout << output[i];
            }
            else
            {
                setTextColor(10);
                cout << output[i];
            }
        }
        setTextColor(12);
        cout << output[j];
        redflag.push_back(j);
        for(int i=j+1; i<output.length(); i++)
        {
            setTextColor(7);
            cout << output[i];
            v.push_back(output[i]);
        }
        k=j+1;
        j++;

    }
    else if(letter!=' '&&output[j]==' ')
    {
        system("cls");
        //gotoxy(0,00);
        int  n=input.size();
        for(int i=0; i<j; i++)
        {
            if(find(redflag.begin(), redflag.end(), i) != redflag.end())
            {
                setTextColor(12);
                cout << output[i];
            }
            else
            {
                setTextColor(10);
                cout << output[i];
            }
        }
        system("cls");
        string s1 = output.substr(0,j), s2 = output.substr(j+1, output.size());
        output.clear();
        output = s1 + " " + input[n-1] + " " + s2;
        setTextColor(12);
        redflag.push_back(j+1);
        for(int i=j; i<output.size(); i++)
        {
            setTextColor(7);
            cout<<output[i];
        }
    }
}

int main()
{
    writesavefiles.open("savefile.txt", ios_base::app);
    readsavefiles.open("savefile.txt", ios_base::in);
    time_t t;
    time(&t);
    x=1;
    //system("cls");

    setTextColor(27) ;
    gotoxy(30,0);
    printf("Welcome to typing test ");
    setTextColor(10) ;
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
    gotoxy(30,1);
    cout<<"#..MAIN MENU..#"<<endl;
    pos;

    cout<<"1.Start typing"<<endl;
    pos;

    cout<<"2.Scorecard"<<endl;
    pos;
    cout<<"3.Help"<<endl;
    pos;
    cout<<"4.Graphical view Of Speed"<<endl;
    pos;
    cout<<"5.Graphical view Of Accuracy"<<endl;
    pos;
    cout<<"6.Block Diagram Of  Speed"<<endl;
    pos;
    cout<<"7.Block Diagram Of Accuracy"<<endl;
    pos;
    cout<<"8.About me"<<endl;
    pos;
    cout<<"0.Exit"<<endl;
    pos;
    cout<<"Enter your choice::"<<endl;
    int ch2;
    gotoxy(30,15);
    cin>>ch2;
    cout<<ch2;

    switch(ch2)
    {
    case 1:
        starttyping();
        break;
    case 2:
        scorecard();
        break;
    case 3:
        help();
        break;
    case 4:
        Graphical_viewOfSpeed();
        break;
    case 5:
    {
        Graphical_viewOfAccuracy();
        break;
    }
    case 6:
        Block_diagramOfSpeed();
        break;
    case 7:
        Block_diagramOfAccuracy();
        break;
    case 8:
        About_me();
        break;
        //default:
        //  main();
    }

}

