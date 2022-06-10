#include <iostream>
#include "ope.h"
using namespace std;

int main (int argc, char *argv[])
{
    OPE ope;
    string code = ope.read_file(argv[1]); // 读取码本
    string content_in = ope.read_file(argv[2]); // 读取输入文件
    cout << "解码前，文件内容为： " << content_in << endl;
    string plaintext = ope.decode(code, content_in);
    cout << "解码后，文件内容为： " << plaintext << endl;
    ope.write_file(argv[3], plaintext); // 写入输出文件
    cout << "写入成功！" << endl;
}