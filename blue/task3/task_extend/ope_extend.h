#include <string>
#include <unordered_map>
using namespace std;

class OPE_extend
{
private:
    
public:
    OPE_extend(){};
    ~OPE_extend(){};
    
    string read_file(string file_name);

    unordered_map<char,char> gen_enmap(string code);

    unordered_map<char,char> gen_demap(string code);

    void code(unordered_map<char,char> map, string file_in, string file_out);

    void write_file(string file_name, string content);
};

