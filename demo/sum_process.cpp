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
    std::cout<<"num1="<<num1<<std::endl;
    std::cout<<"num2="<<num2<<std::endl;

    size_t size_1=num1.size();
    size_t size_2=num2.size();
    if(size_1>size_2)
    {
        std::cout<<"num1>num2"<<std::endl;
        return 1;   //num1绝对值大
    }
    else if(size_1<size_2)
    {
        std::cout<<"num1<num2"<<std::endl;
        return 2;   //num2绝对值大
    }
    else
    {
        if(num1==num2)
        {
            std::cout<<"num1==num2"<<std::endl;
            return 0;
        }
        else
        {
            for(int i=0;i<size_1;++i)
            {
                if(num1[i]>num2[i])
                {
                    std::cout<<"num1>num2"<<std::endl;
                    return 1;   //num1绝对值大
                }
                else if(num1[i]<num2[i])
                {
                    std::cout<<"num1<num2"<<std::endl;
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

std::vector<int> SUM::num_add(std::string &num1,std::string &num2,int &comp)
{
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    std::cout<<"num1="<<num1<<std::endl;
    std::cout<<"num2="<<num2<<std::endl;

    int len=std::max(num1.size(),num2.size());
    std::vector<int>results;
    int base=0;

    for(int i=0;i<len;++i)
    {
        int str_1=(i<num1.size())?(num1[i]-'0'):0;
        int str_2=(i<num2.size())?(num2[i]-'0'):0;
        
        int sum = (str_1 + str_2 + base) % 10;
        //std::cout<<"str_1:"<<str_1<<"  str_2:"<<str_2<<"  sum:"<<sum<<std::endl;
        base = (str_1+ str_2 + base) / 10;
        //std::cout<<"base:"<<base<<std::endl;
        results.push_back(sum);
    }
    if(base==1) results.push_back(1);


    reverse(results.begin(),results.end());

    return results;
}

std::vector<int> SUM::num_minus(std::string &num1,std::string &num2,int &comp)
{
    //std::cout<<"comp="<<comp<<std::endl;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    int len=std::max(num1.size(),num2.size());
    std::vector<int>results;
    int base=0;
    switch (comp)
    {
    case 0:  //num1==num2
        results.push_back(0);
        break;
    case 1:  //num1>num2
        {
            for(int i=0;i<len;++i)
            {
                int str_1=(i<num1.size())?(num1[i]-'0'):0;
                int str_2=(i<num2.size())?(num2[i]-'0'):0;
                
                int minus = (str_1 - str_2 - base) % 10;
                minus<0?minus=(minus+10)%10:minus;
                //std::cout<<"str_1:"<<str_1<<"  str_2:"<<str_2<<"  minus:"<<minus<<std::endl;
                base =(str_1-str_2)==0?0: -(str_1- str_2 -10) / 10;
                //std::cout<<"base:"<<base<<std::endl;
                results.push_back(minus);
            }
            break;
        }
    case 2: //num2>num1
        {
            std::string temp=num1;
            num1=num2;
            num2=temp;
            for(int i=0;i<len;++i)
            {
                int str_1=(i<num1.size())?(num1[i]-'0'):0;
                int str_2=(i<num2.size())?(num2[i]-'0'):0;
                int minus = (str_1 - str_2 - base) % 10;
                minus<0?minus=(minus+10)%10:minus;
                //std::cout<<"str_1:"<<str_1<<"  str_2:"<<str_2<<"  minus:"<<minus<<std::endl;
                base =(str_1-str_2)==0?0: -(str_1- str_2 -10) / 10;
                //std::cout<<"base:"<<base<<std::endl;
                results.push_back(minus);
            }
            break;
        }
    default:
        std::cout<<"error"<<std::endl;
        break;
    }

    reverse(results.begin(),results.end());
    for(int i=0;i<results.capacity();++i)  //删除多余的0
    {
        if(results[0]==0)
        {
            results.erase(results.begin());
        }
        else
        {
            break;
        }
    }
    return results;
}

