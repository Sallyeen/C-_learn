#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(int(time(0)));
    int num = 1 + rand() % 100;
    int num_in;
    int flag = 0;
    cout << "请猜一个1-100的数字：" << endl;
    // cin >> num_in;
    // while(num_in != num)
    // {
    //     if (num_in > num)
    //     {
    //         cout << "猜大啦" << endl;
    //         cin >> num_in;
    //     }
    //     else
    //     {
    //         cout << "猜小啦" << endl;
    //         cin >> num_in;
    //     }
    //     flag ++;
    // }
    // cout << "通过" << flag + 1 << "次的努力，你终于猜对啦！" << endl;

    while(1)
    {
        cin >> num_in;
        flag ++;
        if (num_in > num)
        {
            cout << "猜大啦" << endl;
        }
        else if (num_in < num)
        {
            cout << "猜小啦" << endl;
        }
        else
        {
            cout << "通过" << flag + 1 << "次的努力，你终于猜对啦！" << endl;
            break;
        }
    }
    
}

