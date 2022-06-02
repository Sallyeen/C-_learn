#include <iostream>
#include <string>
#include <vector>
using namespace std;

class OPE
{
private:
    /* data */
public:
    OPE(){};
    ~OPE(){};

    vector<string> read_file(string file, int base_int);

    int input_judg(string num, int base_in);

    void del_zero(string& num);

    int compare_(string& num1, string& num2);

    string add_(string num1, string num2);

    string minus_(string num1, string num2);

    string n_to_ten(string num, int base_in, int base_out);

    string ten_to_n(string num, int base_in, int base_out);

    string ope(string num1, string num2, int base_in, int base_out);
};

