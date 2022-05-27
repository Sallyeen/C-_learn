#include <iostream>

using namespace std;

int main ()
{
    int score[3][3] = {
        {100, 100, 100},
        {90, 50, 10},
        {60, 70, 80}
    };
    int score1 = score[0][0] + score[0][1] + score[0][2];
    int score2 = score[1][0] + score[1][1] + score[1][2];
    int score3 = score[2][0] + score[2][1] + score[2][2];
    cout << "第一个人总成绩为: " << score1 << endl;
    cout << "第二个人总成绩为: " << score2 << endl;
    cout << "第三个人总成绩为: " << score3 << endl;
}