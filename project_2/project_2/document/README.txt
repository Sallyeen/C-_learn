1.程序说明

长整数加减法,默认使用十进制进行输入输出.用户也可以指定输入进制,进行加减运算,也可以指定输出进制.详细操作查看4.
若文件字符不满足输入进制限制 ,则提示用户越界 .输入格式不满足4,则提示用户输入格式错误.

2.代码结构

├── code
│   ├── sum_impl.cpp          -------main执行程序
│   ├── sum_impl.h      
│   ├── sum_process.cpp       -------加减运算
│   ├── sum_process.h
│   └── sum_io.cpp            -------输入输出
│   ├── sum_io.h
│   ├── run.sh                -------编译脚本
│   ├── data.txt              --------所用输入文件
│   └── CMakeLists.txt

3.编译
  运行./run.sh进行编译，生成可执行文件project_1;

4.运行

 ./project_1 ./data.txt       ------默认使用十进制进行输入输出
 ./project_1 ./data.txt x     ------指定x进制进行输入输出
 ./project_1 ./data.txt x  y  ------指定x进制进行输入 y进制输出

5.备注
    pic_1.png  pic_2.png    为 第二次作业补充说明中的案例

    pic_3.png               为错误输入和字符越界  输入是  -ZZZZZZZY   -2 

    pic_4.png                为自定义的文件输入   long_input.png是所使用的自定义输入.
