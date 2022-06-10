#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>


int main(int argc,char *argv[])
{
    std::string _path_book=argv[1];//码本文件
    std::string _path_code=argv[2];//编码文件
    std::string _path_en_code=argv[3];//解密文件
    std::ofstream outFile(_path_en_code,std::ios_base::out|std::ios_base::trunc);
    std::string _code,_book;

    std::string buf1;
    std::ifstream inFile_book(_path_book,std::ios::in|std::ios_base::binary);
    while (getline(inFile_book,buf1));
    _book=buf1;
    std::unordered_map<char,char>map;
    int index=0;
    for(auto c:_book)
    {
        map[c]=index+'a';
        index++;
    }

    std::string buf2;
    std::ifstream inFile_code(_path_code,std::ios::in|std::ios_base::binary);
    if(!(inFile_code.is_open()||inFile_book.is_open()||outFile.is_open()))
    {
        std::cout<<"input error!"<<std::endl;
    }
    while (getline(inFile_code,buf2))
    {
        std::cout<<"book="<<_book<<"\ncode="<<buf2<<std::endl;
        for(auto c:buf2)
        {
            if(c>'a'&&c<'z')
            {
                outFile<<map[c];
            }
            else
            {
                outFile<<c;
            }
        }
        outFile<<'\n';
    }
    inFile_code.close();
    inFile_book.close();
    outFile.close();
    
    return 0;
}