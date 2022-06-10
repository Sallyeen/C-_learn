#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string _path_book = argv[1];    //码本文件
    std::string _path_code = argv[2];    //输入文件
    std::string _path_en_code = argv[3]; //加密文件
    std::ofstream outFile(_path_en_code, std::ios_base::out);
    std::string _code, _book;

    std::string buf1;
    std::ifstream inFile_book(_path_book, std::ios_base::in | std::ios_base::binary);
    while (getline(inFile_book, buf1));
    _book = buf1; //密码本仅有一行

    std::string buf2; //编码文件多行
    std::ifstream inFile_code(_path_code, std::ios_base::in | std::ios_base::binary);
    if (!(inFile_book.is_open() || inFile_code.is_open()))
    {
        std::cout << "input error!" << std::endl;
    }

    while (getline(inFile_code, buf2)) //一行一行处理
    {
        std::cout << "book=" << _book << "\ncode=" << buf2 << std::endl;
        int _index = 0;
        for (auto c : buf2)
        {
            // std::cout<<c<<std::endl;
            if (c > 'a' && c < 'z')
            {
                _index = c - 'a' + 0;
                outFile << _book[_index];
            }
            else
            {
                outFile << c;
            }
        }
        outFile << "\n";
    }
    inFile_book.close();
    inFile_code.close();
    outFile.close();

    return 0;
}