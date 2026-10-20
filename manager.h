#pragma once
#include <vector>
#include "student.h"

class StudentManger { 
public:
    void add();
    void show();
    void find();
    void deleteS();
    void sortS();
    void saveToFile();
    void loadFromFile();

private:
    vector<Student> students;
};
 
