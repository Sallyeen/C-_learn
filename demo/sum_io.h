#pragma once
#include<iostream>
#include<vector>
#include<string>

class IO
{
public:
    IO(){};
    ~IO(){};

    std::vector<std::string>read_file(std::string& file);
    void print_result(std::vector<int>&results,int &_oper,int &comp);

private:


};