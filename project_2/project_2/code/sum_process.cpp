#include"sum_process.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int SUM::num_oper(std::string &num1,std::string &num2)
{
    int flag1=0;
    int flag2=0;

    switch (num1[0])
    {
        case '+':
        flag1=1;break;
        case '-':
        flag1=-1;break;
        default:
        flag1=1;break;
    }
     switch (num2[0])
    {
        case '+':
        flag2=1;break;
        case '-':
        flag2=-1;break;
        default:
        flag2=1;break;
    }
    std::cout<<"运算关系:  ";
    if(flag1==flag2) //加法
    {
        if(flag1==1)
        {
            std::cout<<"num1 + num2"<<std::endl;
            return 1;
        }
        else{
            std::cout<<"- num1 - num2"<<std::endl;
            return 2;
        }
        
    }
    else  //减法
    {
        if(flag1==1)
        {
            std::cout<<"num1 - num2"<<std::endl;
            return 3;
        }
        else
        {
            std::cout<<"num2 - num1"<<std::endl;
            return 4;
        }
    }
}

int SUM::compare(std::string &num1,std::string &num2)
{
    switch (num1[0])
    {
    case '+':
    case '-':
        num1.erase(num1.begin()+0);
        break;
    default:
        break;
    }
    switch (num2[0])
    {
    case '-':
    case '+':
        num2.erase(num2.begin()+0);
        break;
    default:
        break;
    }
    int i=0;                 //删除多余的0
    while(num1[i]=='0')
    {
        ++i;
    }
    if(i==num1.size())num1.erase(0,i-1);
    else num1.erase(0,i);

    int j=0;
    while(num2[j]=='0')
    {
        ++j;
    }
    if(j==num2.size())num2.erase(0,j-1);
    else num2.erase(0,j);

    std::cout<<"num1="<<num1<<std::endl;
    std::cout<<"num2="<<num2<<std::endl;

    size_t size_1=num1.size();
    size_t size_2=num2.size();
    if(size_1>size_2)
    {
        //std::cout<<"num1>num2"<<std::endl;
        return 1;   //num1绝对值大
    }
    else if(size_1<size_2)
    {
        //std::cout<<"num1<num2"<<std::endl;
        return 2;   //num2绝对值大
    }
    else
    {
        if(num1==num2)
        {
            //std::cout<<"num1==num2"<<std::endl;
            return 0;
        }
        else
        {
            for(int i=0;i<size_1;++i)
            {
                if(num1[i]>num2[i])
                {
                    //std::cout<<"num1>num2"<<std::endl;
                    return 1;   //num1绝对值大
                }
                else if(num1[i]<num2[i])
                {
                    //std::cout<<"num1<num2"<<std::endl;
                    return 2;   //num2绝对值大
                }
                else
                {
                    continue;
                }
             }   
        }
        
    }
}

std::string SUM::num_add(std::string &num1,std::string &num2,int &comp,int &oper)
{
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    int len=std::max(num1.size(),num2.size());
    std::string results;
    int base=0;

    for(int i=0;i<len;++i)
    {
        int str_1=(i<num1.size())?(num1[i]-'0'):0;
        int str_2=(i<num2.size())?(num2[i]-'0'):0;
        
        int sum = (str_1 + str_2 + base) % 10;
        //std::cout<<"str_1:"<<str_1<<"  str_2:"<<str_2<<"  sum:"<<sum<<std::endl;
        base = (str_1+ str_2 + base) / 10;
        //std::cout<<"base:"<<base<<std::endl;
        results.push_back(sum+'0');
    }
    if(base==1) results.push_back('1');
    //if(oper==2) results.push_back('-'); //-num1-num2

    reverse(results.begin(),results.end());

    return results;
}

std::string SUM::num_minus(std::string &num1,std::string &num2,int &comp,int &oper)
{
    //std::cout<<"comp="<<comp<<std::endl;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    int len=std::max(num1.size(),num2.size());
    std::string results;
    int base=0;
    switch (comp)
    {
    case 0:  //num1==num2
        return "0";
        break;
    case 2: //num2>num1   互换
        {
            std::string temp=num1;
            num1=num2;
            num2=temp;
        }
    case 1:  //num1>num2
        {
            for(int i=0;i<len;++i)
            {
                int str_1=(i<num1.size())?(num1[i]-'0'):0;
                int str_2=(i<num2.size())?(num2[i]-'0'):0;
                
                int minus = (str_1 - str_2 - base+10) % 10;
                results.push_back(minus+'0');
               // std::cout<<"str_1:"<<str_1<<"  str_2:"<<str_2<<"  minus:"<<minus<<std::endl;
                base =(str_1-str_2-base)<0?1: 0;
               // std::cout<<"base:"<<base<<std::endl;
            }
            break;
        }
    default:
        std::cout<<"error"<<std::endl;
        break;
    }
    reverse(results.begin(),results.end());
    //std::cout<<"ysq1  "<<results<<std::endl;
    int j=0; 
    while(results[j]=='0')  //删除多余的0
    {
        ++j;
    }
    if(j==results.size())
    {
        results.erase(0,j-1);
    }
    if(j>0&&j<results.size())
    {
        results.erase(0,j);
    }

    //if(comp==2) results.insert(results.begin(),'-'); //   num1<num2  num1-num2<0
    //std::cout<<"ysq2  "<<results<<std::endl;
    return results;
}
