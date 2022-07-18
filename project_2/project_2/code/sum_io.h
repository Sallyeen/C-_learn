#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"sum_process.h"

class IO
{
public:
    IO(){};
    ~IO(){};

    std::vector<std::string>read_file(std::string& file);
    bool check_input_str(std::string &ss,int &base_in);

    std::string N_2_dec(std::string&results,int &x,int &y);
    std::string dec_2_N(std::string&results,int &x,int &y);

    void print_ans(std::string&ans,int &base_in,int &base_out,int &comp,int &oper);
};