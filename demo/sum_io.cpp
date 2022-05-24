#include"sum_io.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

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

void IO::print_result(std::vector<int>&results,int &oper,int &comp)
{
    std::cout<<"result=";
    switch (oper)
    {
    case 1://num1+num2
        for(const auto& val:results) std::cout<<val;
        break;
    case 2://-(num1+num2)
        std::cout<<"-";
        for(const auto& val:results) std::cout<<val;
        break;
    case 3://num1-num2
        {
            if(comp==1)
            {
                for(const auto& val:results) std::cout<<val;
            }
            else if(comp==2)
            {
                std::cout<<"-";
                for(const auto& val:results) std::cout<<val;
            }
            else
            {
                std::cout<<"0";
            }
            break;
        }
    case 4://num2-num1
        {
            if(comp==2)
            {
                for(const auto& val:results) std::cout<<val;
            }
            else if(comp==1)
            {
                std::cout<<"-";
                for(const auto& val:results) std::cout<<val;
            }
            else
            {
                std::cout<<"result = 0";
            }
            break;
        }
    default:
        std::cout<<"error"<<std::endl;
        break;
    }
    std::cout<<std::endl;
}