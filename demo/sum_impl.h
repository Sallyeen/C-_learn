#include"sum_io.h"
#include"sum_process.h"
#include<iostream>
#include<vector>

IO _io;//实例化 文件类
SUM sum;//实例化  求和类



std::string _file;   //文件路径
std::vector<std::string>_num_arr;  //储存文件中的数字  按行储存
int _oper;  //运算符
int _comp;  //俩个数的大小关系
std::vector<int>_results;

std::string _num1;
std::string _num2;