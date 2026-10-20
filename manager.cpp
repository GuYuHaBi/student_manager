#include "manager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void StudentManger::add() {
    Student s;
    cout << "请输入添加学生姓名：";
    cin >> s.name;
    cout << "请输入添加学生成绩：";
    cin >> s.score;
    students.push_back(s);
}

void StudentManger::show() {
    if (students.empty()) {
        cout << "暂无学生" << endl;
        return;
    }
    for (auto x : students)
        cout << x.name << " " << x.score << endl;
}

void StudentManger::find() {
    if (students.empty()) {
        cout << "暂无学生" << endl;
        return;
    }
    cout << "请输入要查找的学生姓名：";
    string name;
    cin >> name;
    for (auto x : students) {
        if (x.name == name) {
            cout << x.name << " " << x.score << endl;
            return;
        }
    }
    cout << "未找到该学生" << endl; 
}

void StudentManger::deleteS() {
    if (students.empty()) {
        cout << "暂无学生" << endl;
        return;
    }
    cout << "请输入要删除的学生姓名：";
    string name;
    cin >> name;
    students.erase(
        remove_if(students.begin(), students.end(), [name](const Student& s) {
            return s.name == name;
        }),
        students.end()
    );
}

void StudentManger::sortS() {
    if (students.empty()) {
        cout << "暂无学生" << endl;
        return;
    }
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.score > s2.score;
    });
    cout << "排序成功！" << endl;
    cout << "成绩最高的同学为：" << students[0].name << " " << students[0].score << endl;
    cout << "成绩最低的同学为：" << students[students.size() - 1].name << " " << students[students.size() - 1].score << endl;
    
    double average = 0;
    double all = 0;
    for (auto x : students) {
        all += x.score;
    }
    average = all / students.size();
    cout << "平均成绩为：" << average << endl;
}

void StudentManger::saveToFile() {
    ofstream out("students.txt");
    if (!out) {
        cout << "文件打开失败！" << endl;
        return;
    }
    for (auto x : students) {
        out << x.name << " " << x.score << endl;
    }
    out.close();
}

void StudentManger::loadFromFile() {
    ifstream in("students.txt");
    if (!in) {
        return; 
    }
    students.clear();
    Student s;
    while (in >> s.name >> s.score) {
        students.push_back(s);
    }
    in.close();
}
