#include <iostream>
#include <unordered_map>
#include "ope_extend.h"
using namespace std;

int main (int argc, char *argv[])
{
    OPE_extend ope;
    string code = ope.read_file(argv[1]); // 读取码本
    unordered_map<char,char> map = ope.gen_demap(code);
    ope.code(map, argv[2], argv[3]);
}