vector<string> nums;
vector<string> read_file(string file)
{
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

void del_zero(string& num)
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

int compare_(string& num1, string& num2)
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

string add_(string num1, string num2)
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

string minus_(string num1, string num2)
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

string ope(string num1, string num2)
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
    return ans;
}