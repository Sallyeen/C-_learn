#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct student
{
    string name;
    int score;
};


struct teacher
{
    string name;
    struct student sArray[5];
};

void allocate (teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].name = "teacher_";
        tArray[i].name += nameSeed[i];
        for (int j = 0; j <5; j++)
        {
            tArray[i].sArray[j].name = "student_";
            tArray[i].sArray[j].name += nameSeed[j];
            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
}

void printST (teacher tArray[], int len)
{
    for (int i = 0; i<len; i++)
    {
        cout << "第" << i + 1 << "位老师姓名为： " << tArray[i].name << ", 所带的学生有： " << endl;
        for (int j = 0; j<5; j++)
        {
            cout << "\t" << "第" << j + 1 << "位学生姓名为： " << tArray[i].sArray[j].name << ", 分数为：" << tArray[i].sArray[j].score << endl;
        }
    }

}

int main ()
{

    struct teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    srand((unsigned)time(NULL));
    allocate(tArray, len);
    printST(tArray, len);    
}