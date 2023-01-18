#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<ctime>
#include<vector>
using namespace std;
int wrong=0;
int timer = 0;
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
            wrong++;
            break;
        }

    }
}
void random_word(vector <string> big)
{
    int len = big.size();
    int t = 0;
    bool input = false;
    string word, userword;
    while(1)
    {
        if(input == false)
        {
            word = big[rand()%len];
            cout << word << endl;
            input = true;
        }
        else
        {
            cin >> userword;
            if(word == userword)
            {
                cout << "Matched\n";
            }
            input = false;
        }
        //current_time = time();
    }
}
void read_word_by_word(string filename)
{
    fstream file;
    vector <string> big;
    string word;
    file.open(filename.c_str());
    while(file >> word)   //take word and print
    {
        big.push_back(word);
        //file.close();
    }
    //cout<<big;
    random_word(big);
}
int main()
{
    string name;
    cout << "Enter filename: ";
    cin >> name;
    read_word_by_word(name);
}
