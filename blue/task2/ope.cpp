#include "ope.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;

vector<string> OPE::read_file(string file, int base_in)
{
    vector<string> nums;
    ifstream fin;
    fin.open(file, ios::in);
    while(!fin.is_open())
    {
        cerr << "fail to open file" << endl;
    }
    string buff;
    while(getline(fin, buff))
    {
        nums.push_back(buff);
    }
    fin.close();
    return nums;
}

int OPE::input_judg(string num, int base_in)
{
    for (int j=0; j< num.size(); j++)
        {
            if(num[j] >= 'A' && num[j] <= 'Z' && num[j]-'A'+10 >= base_in)
            {
                return -1;
            }
            else if(num[j] >= 'a' && num[j] <= 'z' && num[j]-'A'+10 >= base_in)
            {
                return -1;
            }
            else if(num[j] >= '0' && num[j] <= '9' && num[j] - '0' >= base_in)
            {
                return -1;
            }
        }
    return 0;
}

void OPE::del_zero(string& num)
{
    int flag = 0;
    for(int i=0; i<num.size(); i++)
    {
        if(num[i] == '0')
        {flag++;}
        else
        {break;}
    }
    num.erase(0, flag);
}

int OPE::compare_(string& num1, string& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
        return 2;
    }
    else
    {
        for (int i=0; i<len1; i++)
        {
            if(num1[i] < num2[i])
            {
                string temp = num1;
                num1 = num2;
                num2 = temp;
                return 2;
            }
            else if(num1[i] > num2[i])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

string OPE::add_(string num1, string num2)
{
    int len = max(num1.size(), num2.size());
    int base = 0; // 进位
    string ans;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for(int i=0; i<len; i++)
    {
        int str1 = (i<num1.size())?(num1[i]-'0'):0;
        int str2 = (i<num2.size())?(num2[i]-'0'):0;
        int temp = (str1 + str2 + base) % 10;
        base = (str1 + str2 + base) / 10;
        ans.push_back(temp+'0');
    }
    if(base != 0)
    {
        ans.push_back(base+'0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string OPE::minus_(string num1, string num2)
{
    int len = max(num1.size(), num2.size());
    int base = 0;
    string ans;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for(int i=0; i<len; i++)
    {
        int str1 = (i<num1.size())?(num1[i]-'0'):0;
        int str2 = (i<num2.size())?(num2[i]-'0'):0;
        str1 = str1 - base;
        base = 0;
        if (str1 < str2) base ++;
        int temp = str1 - str2 + base * 10;
        ans.push_back(temp + '0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//其他进制转十进制
string OPE::n_to_ten(string num, int base_in, int base_out) 
{
    std::vector<int> conv;
    std::vector<int> out;

    for(int i=0;i<num.size();i++)
    {
        if(num[i] >= 'A' && num[i] <= 'Z')
        {
            conv.push_back(num[i]-'A'+10);
        }
        else if(num[i] >= 'a' && num[i] <= 'z')
        {
            conv.push_back(num[i]-'a'+10);
        }
        else if(num[i] >= '0' && num[i] <= '9')
        {
            conv.push_back(num[i]-'0');
        }
    }

    //int size = 0;
    int i = 0;
    while (i < conv.size()) 
    {
        int remainder = 0;
        int dividend=0;
        // 每次迭代是一位数字的除法
        for (int j = i; j < conv.size(); j++) 
        {
            dividend = remainder * base_in + conv[j];
            conv[j] = dividend / base_out;
            remainder = dividend % base_out;
        }
        out.push_back(remainder);
        //size++;
        // 去除商前面所有的0
        while (conv[i] == 0 && i < conv.size()) i++;
    }
    reverse(out.begin(),out.end());
    
    string res;
    for(int i=0;i<out.size();i++)
    {
        res.push_back(out[i]+'0');
    }
    return res;
}

//十进制转其他进制
string OPE::ten_to_n(string num, int base_in, int base_out) 
{
    std::vector<int> conv;
    string out;
    char sign = num[0];
    num.erase(remove(num.begin(),num.end(),'-'),num.end());
    num.erase(remove(num.begin(),num.end(),'+'),num.end());

    for(int i=0;i<num.size();i++)
    {
        conv.push_back(num[i]-'0');
    }
    //int size = 0;
    int i = 0;
    while (i < conv.size()) 
    {
        int remainder = 0;
        int dividend=0;
        // 每次迭代是一位数字的除法
        for (int j = i; j < conv.size(); j++) 
        {
            dividend = remainder * base_in + conv[j];
            conv[j] = dividend / base_out;
            remainder = dividend % base_out;
        }
        if(remainder >= 10 && remainder <= 35)
        {
            out.push_back(remainder + 'A' - 10);
        }
        else
        {
            out.push_back(remainder + '0');
        }
        //size++;
        // 去除商前面所有的0
        while (conv[i] == 0 && i < conv.size()) i++;
    }
    reverse(out.begin(),out.end());
    out.insert(out.begin(), sign);
    return out;
}

string OPE::ope(string num1, string num2, int base_in, int base_out)
{
    char sign1 = num1[0];
    char sign2 = num2[0];
    string ans;
    num1.erase(remove(num1.begin(),num1.end(),'-'),num1.end());
    num1.erase(remove(num1.begin(),num1.end(),'+'),num1.end());
    num2.erase(remove(num2.begin(),num2.end(),'-'),num2.end());
    num2.erase(remove(num2.begin(),num2.end(),'+'),num2.end());
    del_zero(num1);
    del_zero(num2);
    num1 = n_to_ten(num1, base_in, 10);
    num2 = n_to_ten(num2, base_in, 10);
    //cout << "转为10进制后，num1 为： " << num1 << endl;
   // cout << "转为10进制后，num2 为： " << num2 << endl;
    int flag = compare_(num1, num2);
    if(sign1=='-')
    {
        if (sign2=='-')
        {
            ans = add_(num1, num2);
            ans.insert(ans.begin(), '-');
        }
        else
        {
            if (flag == 0)
            {ans = "0";}
            else
            {
                ans = minus_(num1, num2);
                del_zero(ans);
                if (flag == 1) 
                {ans.insert(ans.begin(), '-');}
            }
        }
    }
    else
    {
        if (sign2=='-')
        {
            if (flag == 0)
            {ans = "0";}
            else
            {
                ans = minus_(num1, num2);
                del_zero(ans);
                if (flag == 2) 
                {ans.insert(ans.begin(), '-');}
            }
        }
        else
        {
            ans = add_(num1, num2);
        }
    }
    cout << "转为10进制前，ans 为： " << ans << endl;
    ans = ten_to_n(ans, 10, base_out);
    // cout << "转为10进制后，ans 为： " << ans << endl;
    // ans = n_to_ten(ans, base_out, 10);
    // cout << "再次转为10进制后，ans 为： " << ans << endl;
    return ans;
}