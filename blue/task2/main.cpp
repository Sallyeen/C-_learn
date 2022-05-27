#include <iostream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;



int main (int argc, char *argv[])
{
    vector<string> nums_string = read_file(argv[1]);
    string num1 = nums_string[0];
    string num2 = nums_string[1];
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    string ans = ope(num1, num2);
    cout << "The answer is : ";
    cout << ans << endl;
}