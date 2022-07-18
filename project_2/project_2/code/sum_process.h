#pragma once
#include<iostream>
#include<string>
#include<vector>

class SUM
{    
    friend class IO;
public:
    SUM(){};
    ~SUM(){};
    int num_oper(std::string &num1,std::string &num2);

    std::string num_add(std::string &num1,std::string &num2,int& comp,int &oper);
    std::string num_minus(std::string &num1,std::string &num2,int& comp,int &oper);
    int compare(std::string &num1,std::string &num2);


private:
    
};