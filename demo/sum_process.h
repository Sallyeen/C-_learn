#pragma once
#include<iostream>
#include<string>
#include<vector>

class SUM
{    
public:
    SUM(){};
    ~SUM(){};
    int num_oper(std::string &num1,std::string &num2);

    std::vector<int> num_add(std::string &num1,std::string &num2,int& comp);
    std::vector<int> num_minus(std::string &num1,std::string &num2,int& comp);
    int compare(std::string &num1,std::string &num2);


private:
    
};