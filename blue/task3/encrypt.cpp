#include <iostream>
#include "ope.h"
using namespace std;

int main (int argc, char *argv[])
{
    OPE ope;
    string code = ope.read_file(argv[1]); // 读取码本
    string content_in = ope.read_file(argv[2]); // 读取输入文件
    cout << "编码前，文件内容为： " << content_in << endl;
    string ciphertext = ope.encode(code, content_in); // 编码
    cout << "编码后，文件内容为： " << ciphertext << endl;
    ope.write_file(argv[3], ciphertext); // 写入输出文件
    cout << "写入成功！" << endl;
}