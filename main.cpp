#include <iostream>
#include "manager.h"
using namespace std;

int main() {
    StudentManger sm;
    sm.loadFromFile(); // 启动时加载

    while (true) {
        cout << "\n===== 学生成绩管理系统 =====" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 查找学生" << endl;
        cout << "4. 删除学生" << endl;
        cout << "5. 排序" << endl;
        cout << "6. 退出" << endl;
        cout << "请输入操作编号：";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: sm.add(); break;
            case 2: sm.show(); break;
            case 3: sm.find(); break;
            case 4: sm.deleteS(); break;
            case 5: sm.sortS(); break;
            case 6: 
                sm.saveToFile(); // 退出前保存
                cout << "已保存并退出。" << endl;
                return 0; 
            default:
                cout << "输入有误，请重新输入！" << endl;
        }
    }
}
