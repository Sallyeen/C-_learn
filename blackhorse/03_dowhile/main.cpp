#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int main()
{
    time_t start = time(0);
    // for (int i=100; i<1000; i++)
    // {
    //     int a = pow(i%10, 3);
    //     int b = pow(i/100, 3);
    //     int c = pow((i%100)/10, 3);
    //     //cout << i << "\t" << a << "\t" << b << "\t" << c << endl;
    //     if (a + b + c == i)
    //     {
    //         cout << i << endl;
    //     }
    // }
    int num = 100;
    do
    {
        int a = num % 10;
        int b = num / 100;
        int c = (num % 100) / 10;
        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout << num << endl;
        }
        num ++;
    } while (num < 1000);
    
    time_t finish = time(0);
    double time = double(finish - start);
    cout << time << endl;
}
