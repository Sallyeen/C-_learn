#include "ope.h"
#include <fstream>
#include <iostream>
using namespace std;

string OPE::read_file(string file_name)
{
    string codebook;
    ifstream fin;
    fin.open(file_name, ios::in);
    while (!fin.is_open())
    {
        cerr << "读取文件错误!" << endl; 
    }
    getline(fin, codebook);
    return codebook;
}

string OPE::encode(string code, string plaintext)
{
    string ciphertext = "";
    for (int i=0; i< plaintext.size(); i++)
    {
        if (plaintext[i] <= 'a' || plaintext[i] >= 'z')
        {
            ciphertext.push_back(plaintext[i]);
        }
        else
        {
            int index = plaintext[i] - 'a';
            //cout << i<< endl;
            //cout << index << endl;
            char t = code[index];
            ciphertext += t;
        }
    }
    return ciphertext;
}

string OPE::decode(string code, string ciphertext)
{
    string plaintext = "";
    for (int i=0; i< ciphertext.size(); i++)
    {
        if (ciphertext[i] <= 'a' || ciphertext[i] >= 'z')
        {
            plaintext.push_back(ciphertext[i]);
        }
        else
        {
            int idx = code.find(ciphertext[i]);
            char t = idx + 'a';
            plaintext += t;
        }
    }
    return plaintext;
}

void OPE::write_file(string file_name, string content)
{
    ofstream fout;
    fout.open(file_name, ios::out);
    fout << content << endl;
    fout.close();
}