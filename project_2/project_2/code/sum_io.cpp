#include"sum_io.h"
#include"sum_process.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

std::vector<std::string> IO::read_file(std::string& file)
{
    std::fstream fin;
    fin.open(file,std::ios::in);

    if(!fin.is_open())
    {
        std::cerr<<"fail to open file"<<std::endl;
    }

    std::vector<std::string>num_arr;
    std::string buff;
    while(getline(fin,buff))
    {
        num_arr.push_back(buff);
    }
    return num_arr;
}

bool IO::check_input_str(std::string &ss,int &base_in)
{
    for(auto val:ss)
    {
        if(val=='-'||val=='+')continue;
        int temp=val-'0';
        int temp_a=val-'a'+10;
        int temp_A=val-'A'+10;
        if((base_in<10&&temp>=base_in)||(base_in>=10&&temp_a>=base_in)||(base_in>=10&&temp_A>=base_in))
        {
            std::cout<<"输入字符越界!"<<std::endl;
            return false;
        }
    }
    return true;
}

std::string IO::N_2_dec(std::string&results,int &x,int &y) //任意进制转十进制
{
    //std::cout<<"input_base:"<<x<<std::endl;
    //std::cout<<"output_base:"<<y<<std::endl;
    std::vector<int> conv;
    std::vector<int> out;
    switch (results[0])
   {
    case '-':
    case '+':
        results.erase(results.begin());
    default:
        for(int i=0;i<results.size();i++)
        {
             if(results[i] >= 'A' && results[i] <= 'Z')
            {
                conv.push_back(results[i]-'A'+10);
            }
            else if(results[i] >= 'a' && results[i] <= 'z')
            {
                conv.push_back(results[i]-'a'+10);
            }
            else if(results[i] >= '0' && results[i] <= '9')
            {
                conv.push_back(results[i]-'0');
            }
        }
        break;
   }
//    std::cout<<"conv="<<std::endl;
//    for(auto val:conv)std::cout<<val<<std::endl;
    // 转换为y进制之后的长度
    int size = 0;
    int n=conv.size();
    // 每次迭代是一次除法
    int i = 0;
    while (i < n) 
    {
        int remainder = 0;
        int dividend=0;
        // 每次迭代是一位数字的除法
        for (int j = i; j < n; j++) 
        {
            dividend = remainder * x + conv[j];
            conv[j] = dividend / y;
            remainder = dividend % y;
        }
        out.push_back(remainder);
        size++;
        // 去除商前面所有的0
        // 2019/6/18 15.51添加判断范围条件，之前为 while (in[i] == 0) i++;
        while (conv[i] == 0 && i < n) i++;
    }
    reverse(out.begin(),out.end());

    std::string res;
    for(int i=0;i<out.size();i++)
    {
        res.push_back(out[i]+'0');
    }
    //for(auto val:out)std::cout<<"out="<<val<<std::endl;
    //std::cout<<"准换完成:"<<res<<std::endl;
    return res;
}

std::string IO::dec_2_N(std::string&results,int &x,int &y) //十进制转任意进制
{
    //std::cout<<"input_base:"<<x<<std::endl;
    //std::cout<<"output_base:"<<y<<std::endl;
    std::vector<int> conv;
    std::vector<int> out;
    for(auto val:results)
    {
        conv.push_back(val-'0');
    }
//    std::cout<<"conv="<<std::endl;
//    for(auto val:conv)std::cout<<val<<std::endl;
    // 转换为y进制之后的长度
    int size = 0;
    int n=conv.size();
    // 每次迭代是一次除法
    int i = 0;
    while (i < n) 
    {
        int remainder = 0;
        int dividend=0;
        // 每次迭代是一位数字的除法
        for (int j = i; j < n; j++) 
        {
            dividend = remainder * x + conv[j];
            conv[j] = dividend / y;
            remainder = dividend % y;
        }
        out.push_back(remainder);
        size++;
        // 去除商前面所有的0
        // 2019/6/18 15.51添加判断范围条件，之前为 while (in[i] == 0) i++;
        while (conv[i] == 0 && i < n) i++;
    }
    reverse(out.begin(),out.end());

    std::string res;
    for(int i=0;i<out.size();i++)
    {
        res.push_back(out[i]+'0');
    }
    //for(auto val:out)std::cout<<"out="<<val<<std::endl;
    //std::cout<<"准换完成:"<<res<<std::endl;
    return res;
}

void IO::print_ans(std::string&ans,int &base_in,int &base_out,int &comp,int &oper)
{
    std::cout<<"输入进制数:"<<base_in<<"\t输出进制数:"<<base_out<<std::endl;
    std::cout<<"The answer is:";
    if(comp==0)//num1=num2
    {
         switch (oper)
       {
        case 2: //-num-num2
            std::cout<<"-";
        case 1://num1+num2
            break;
        case 4: //num2-num1
        case 3: //num1-num2
            std::cout<<"0"<<std::endl;
            return ;
       }
    }
    else if(comp==1)//num1>num2
    {
       switch (oper)
       {
        case 3: //num1-num2
        case 1://num1+num2
            break;
        case 4: //num2-num1
        case 2: //-num-num2
            std::cout<<"-";
            break;
       }
    }
    else if(comp==2)//num2>num1
    {
        switch (oper)
       {
        case 4: //num2-num1
        case 1://num1+num2
            break;
        case 3: //num1-num2
        case 2: //-num-num2
            std::cout<<"-";
            break;
       }
    }
    std::cout<<ans<<std::endl;
}