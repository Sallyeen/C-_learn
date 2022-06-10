#include <string>
using namespace std;

class OPE
{
private:
    
public:
    OPE(){};
    ~OPE(){};

    string read_file(string file_name);

    string encode(string code, string plaintext);

    string decode(string code, string ciphertext);

    void write_file(string file_name, string content);
};

