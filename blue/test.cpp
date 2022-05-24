#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str = "000000021";
    int flag = 0;
    for(int i=0; i<str.size(); i++)
    {
        cout << str[i] << endl;
		if(str[i] == '0')
        {
			flag++;
			cout << "str[i]" << endl;
		}
        else
        {break;}
    }
    str.erase(0, flag);
	cout << flag << endl;
	cout << str << endl;
}