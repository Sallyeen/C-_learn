#include "ope.h"
#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[])
{
    int base_in = 10;
    int base_out = 10;
    
    // 处理命令行输入与非法判断
    switch (argc)
    {
    case 2:
        cout << "输入进制为: " << base_in << endl;
        cout << "输出进制为: " << base_out << endl;
        break;
    case 3:
        base_in = stoi(argv[2]); 
        base_out = stoi(argv[2]);
        cout << "输入进制为: " << base_in << endl;
        cout << "输出进制为: " << base_out << endl;
        break;
    case 4:
        base_in = stoi(argv[2]); 
        base_out = stoi(argv[3]);
        cout << "输入进制为: " << base_in << endl;
        cout << "输出进制为: " << base_out << endl;
        break;
    default:
        cout << "输入参数错误,请重新输入!" << endl;
        return -1;
    }
    
    // 限制进制范围
    if (base_in>36 || base_in<2 || base_out>36 || base_out<2)
    {
        cout << "允许的进制范围为 0-36, 请重新输入！" << endl;
        return -1;
    }

    OPE ope;
    vector<string> nums_string = ope.read_file(argv[1], base_in);
    string num1 = nums_string[0];
    string num2 = nums_string[1];
    if (ope.input_judg(num1, base_in) != 0 || ope.input_judg(num2, base_in) != 0 )
    {
        cout << "输入进制不符！" << endl;
        return -1;
    }
    else
    {
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
        string ans = ope.ope(num1, num2, base_in, base_out);
        cout << "The answer is : ";
        cout << ans << endl;
    }    
}