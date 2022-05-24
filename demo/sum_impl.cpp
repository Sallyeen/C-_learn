#include"sum_impl.h"

int main()
{
    _file="./data.txt";
    _num_arr=_io.read_file(_file);
    _num1=_num_arr[0];_num2=_num_arr[1];
   _oper=sum.num_oper(_num1,_num2);
   _comp=sum.compare(_num1,_num2);
   if(_oper==1||_oper==2)
   {
       _results=sum.num_add(_num1,_num2,_comp);
   }
   else
   {
       _results=sum.num_minus(_num1,_num2,_comp);
   }
   _io.print_result(_results,_oper,_comp);
   
    return 0;
}