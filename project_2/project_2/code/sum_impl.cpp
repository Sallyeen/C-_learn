#include"sum_impl.h"

int main(int argc ,char *argv[])
{
    _base_ten=10;
    _file=argv[1];
    switch (argc)        
    {
    case 2:            //基础功能  十进制输入输出
        _base_in=10;
        _base_out=10;
        break;
    case 3:           //扩展一
        _base_in=std::stoi(argv[2]);
        _base_out=std::stoi(argv[2]);
        break;
    case 4:          //扩展二
        _base_in=std::stoi(argv[2]);
        _base_out=std::stoi(argv[3]);
        break;
    default:
        std::cout<<"输入参数错误,请重新输入!"<<std::endl;
        return -1;
    }
    if(_base_in>37||_base_in<1||_base_out>37||_base_out<1)
    {
        std::cout<<"输入参数错误,请重新输入!"<<std::endl;
        return 0;
    }

    _num_arr=_io.read_file(_file);
    _num1=_num_arr[0];_num2=_num_arr[1];//读取文件内容

    if(!_io.check_input_str(_num1,_base_in)||!_io.check_input_str(_num2,_base_in))return 0; //非法输入的判断

    _oper=sum.num_oper(_num1,_num2);    //判断读取内容的符号位及两个数的运算关系
      
    _comp=sum.compare(_num1,_num2);     //过滤符号位和占位的0 比较两个字符串数字的大小 
    
    _num1=_io.N_2_dec(_num1,_base_in,_base_ten);   //将任意进制转化为十进制  进行计算
    _num2=_io.N_2_dec (_num2,_base_in,_base_ten);  

   if(_oper==1||_oper==2)
   {
       _results=sum.num_add(_num1,_num2,_comp,_oper);  //num1+num2   -num1-num2
   }
   else
   {
       _results=sum.num_minus(_num1,_num2,_comp,_oper);  //num1-num2   num2-num1
   }

    _ans=_io.dec_2_N(_results,_base_ten,_base_out);//将十进制的结果转化为指定进制  
   
    _io.print_ans(_ans,_base_in,_base_out,_comp,_oper);

    return 0;
}