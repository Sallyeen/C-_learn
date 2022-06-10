#include "ope_extend.h"
#include <fstream>
#include <iostream>
#include <sstream> 
using namespace std;

string OPE_extend::read_file(string file_name)
{
    string codebook;
    ifstream fin;
    fin.open(file_name, ios::in | ios::binary);
    while (!fin.is_open())
    {
        cerr << "读取文件错误!" << endl; 
    }
    char c;
    while ((c = fin.get()) != EOF)
    {
        codebook.push_back(c);
    }
    return codebook;
}

unordered_map<char, char> OPE_extend::gen_enmap(string code)
{
    unordered_map<char,char> map;
    istringstream is(code);
    int i=0;
    string s;
    while(!is.eof())
    {
        is>>s;
        char y=(char)atoi(s.c_str());
        map[(char)i]=y;
        i++;
    }
    return map;
}

unordered_map<char, char> OPE_extend::gen_demap(string code)
{
    unordered_map<char,char> map;
    istringstream is(code);
    int i=0;
    string s;
    while(!is.eof())
    {
        is>>s;
        char y=(char)atoi(s.c_str());
        map[y]=(char)i;
        i++;
    }
    return map;
}

void OPE_extend::code(unordered_map<char,char> map, string file_in, string file_out)
{
    ifstream fin;
    fin.open(file_in, ios::in | ios::binary);
    ofstream fout;
    fout.open(file_out, ios::out | ios::binary);
    char c;
    while(fin.get(c))
    {
        fout.put(map[c]);
    }
}