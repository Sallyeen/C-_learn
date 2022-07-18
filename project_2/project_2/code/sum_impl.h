#include"sum_io.h"
#include"sum_process.h"
#include<iostream>
#include<vector>

IO _io;//实例化 文件类
SUM sum;//实例化  求和类


int _base_in;//输入进制数
int _base_out;//输出进制数
int _base_ten;//十进制

std::string _file;   //文件路径
std::vector<std::string>_num_arr;  //储存文件中的数字  按行储存
int _oper;  //运算符
int _comp;  //俩个数的大小关系
std::string _results;  //存放计算结果
std::string _ans;//最终结果

std::string _num1;  //第一个字符串数字
std::string _num2;  //第二个字符串数字