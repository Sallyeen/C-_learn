#include <iostream>

using namespace std;

// 分别输入三只小猪的体重，判断哪只最重

int main()
{
    int weight1, weight2, weight3;
    cout << "请输入第一只小猪的体重：" << endl;
    cin >> weight1;
    cout << "请输入第2只小猪的体重：" << endl;
    cin >> weight2;
    cout << "请输入第3只小猪的体重：" << endl;
    cin >> weight3;

    if(weight1>weight2)
    {
        if(weight1>weight3)
        {
            cout << "第一只小猪最重" << endl;
        }
        else if(weight1==weight3)
        {
            cout << "第一只小猪和第三只一样重" << endl;
        }
        if(weight1<weight3)
        {
            cout << "第三只小猪最重" << endl;
        }
    }
    else if(weight1<weight2)
    {
        if(weight2>weight3)
        {
            cout << "第二只小猪最重" << endl;
        }
        else if(weight2==weight3)
        {
            cout << "第二只小猪和第三只一样重" << endl;
        }
        else if(weight2<weight3)
        {
            cout << "第三只最重" << endl;
        }
    }
    else{
        if(weight2>weight3)
        {
            cout << "第一只小猪和第二只一样重" << endl;
        }
        else if(weight2<weight3)
        {
            cout << "第三只最重" << endl;
        }
        else if(weight2==weight3)
        {
            cout << "三只一样重" << endl;
        }
    }
}