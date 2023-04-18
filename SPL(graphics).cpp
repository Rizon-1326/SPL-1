#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <graphics.h>
using namespace std;
struct Student {
    string name;
    int age;
    int result;
};

int main() {
   ifstream infile("result.txt");

    vector<Student> students;

    Student student;

    while (infile >> student.name >> student.age >> student.result) {
        students.push_back(student);
    }


    initwindow(800, 600, "Results Graph");


    int x = 50;
    int y = 550;
    int bar_width = 50;
    int bar_height;

    for (const auto& s : students) {
        bar_height = s.result / 2;
        setfillstyle(SOLID_FILL, BLUE);
        bar(x, y, x + bar_width, y - bar_height);

         /* outtextxy(x, y + 20, s.name.c_str());
        x += bar_width + 20; */

        // I've fixed the problem of oulfoun conversion of char* using chatGPT


        const char* name_cstr = s.name.c_str();
        outtextxy(x, y + 20, const_cast<char*>(name_cstr));
        x += bar_width + 20;
    }


    getch();

    closegraph();

    return 0;
}
