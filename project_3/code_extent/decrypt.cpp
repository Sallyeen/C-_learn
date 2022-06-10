#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>


int main(int argc,char *argv[])
{
    std::string _path_book=argv[1];//码本文件
    std::string _path_code=argv[2];//编码文件
    std::string _path_en_code=argv[3];//解密文件
    std::ofstream outFile(_path_en_code,std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);

    std::string buf1;
    std::ifstream inFile_book(_path_book,std::ios::in|std::ios_base::binary);

    std::ifstream inFile_code(_path_code,std::ios::in|std::ios_base::binary);
    if(!(inFile_code.is_open()||inFile_book.is_open()||outFile.is_open()))
    {
        std::cout<<"input error!"<<std::endl;
    }

    std::unordered_map<char,char>mp;
    while (getline(inFile_book,buf1))
    {
        //std::cout<<"de_buf1="<<buf1<<std::endl;
        std::istringstream is(buf1);
        int i=0;
        std::string s;
        while(!is.eof())
        {
            is>>s;
            char y=(char)atoi(s.c_str());
            mp[y]=(char)i;
            i++;
        }
    }
    char c;
    while(inFile_code.get(c))
    {
        outFile.put(mp[c]);
    }
    inFile_code.close();
    inFile_book.close();
    outFile.close();
    
    return 0;
}