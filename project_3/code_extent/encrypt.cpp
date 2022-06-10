#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <vector>
#include<unordered_map>

int main(int argc, char *argv[])
{
    std::string _path_book = argv[1];    //码本文件
    std::string _path_code = argv[2];    //输入文件
    std::string _path_en_code = argv[3]; //加密文件
    std::ofstream outFile(_path_en_code, std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);

    std::string buf1;
    std::ifstream inFile_book(_path_book, std::ios_base::in | std::ios_base::binary);

    std::string buf2; //编码文件
    std::ifstream inFile_code(_path_code, std::ios_base::in | std::ios_base::binary);
    if (!(inFile_book.is_open() || inFile_code.is_open()))
    {
        std::cout << "input error!" << std::endl;
    }
    //std::cout<<"buf0"<<std::endl;
    //建立密码本的映射
    std::unordered_map<char,char>mp;
    while (getline(inFile_book, buf1)) //一行一行处理
    {
        //std::cout<<"en_buf1="<<buf1<<std::endl;
        std::istringstream is(buf1);
        int i=0;
        std::string s;
        while(!is.eof())
        {
            is>>s;
            char y=(char)atoi(s.c_str());
            mp[(char)i]=y;
            i++;
        }
    }
    char c;
    while(inFile_code.get(c))
    {
        //std::cout<<"c="<<c;
        outFile.put(mp[c]);
    }
    inFile_book.close();
    inFile_code.close();
    outFile.close();

    return 0;
}