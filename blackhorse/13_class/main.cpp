#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// 设计学生类，属性为姓名和学号；行为有赋值+显示

class Student
{
public:
    string name;
    int number;
    void assign_(string name_new, int number_new)
    {
        name = name_new;
        number = number_new;
    }
    void show_()
    {
        cout << "该学生的姓名为： " << name << ", 学号为： " << number << endl;
    }    
};

int main ()
{
    Student stu1;
    stu1.name = "张三";
    stu1.number = 12;
    stu1.show_();
    stu1.assign_("李四", 13);
    stu1.show_();
} 