水平有限，尽力实现。

# quick start
> 基础任务：
```
cd task
sh run.sh
entask code.txt file_in.txt file_out.txt // 编码任务，code.txt为码本，file_in.txt和file_out.txt分别为编码前文件和编码后文件
detask code.txt file_in.txt file_out.txt // 解码任务，code.txt为码本，file_in.txt和file_out.txt分别为解码前文件和解码后文件
```

> 扩展任务：
```
cd task_extend
sh run.sh
entask code.txt file_in.txt file_out.txt // 编码任务，code.txt为码本，file_in.txt和file_out.txt分别为编码前文件和编码后文件
detask code.txt file_in.txt file_out.txt // 解码任务，code.txt为码本，file_in.txt和file_out.txt分别为解码前文件和解码后文件
```

# 功能
> 基础任务
- 读取码本，读取输入文件
- 进行编码或解码任务
- 将编/解码后内容写入输出文件

> 扩展任务
- 读取码本
- 根据码本生成明文与密文的映射map
- 读入输入文件，根据map进行编码或解码操作，并读出到输出文件

# 代码解释
> 基础任务
- `OPE::encode`: 遍历读取的输入文件内容，若内容不属于 a-z, 直接添加到输出变量；若属于，则求出该内容的索引，在码本中索引到对应的密文，添加到输出变量并返回
- `OPE::decode`: 遍历读取的输入文件内容，若内容不属于 a-z, 直接添加到输出变量；若属于，则在码本中找到其对应的索引，根据索引确定a-z对应的char值，添加到输出变量并返回
> 扩展任务
- `OPE_extend::gen_enmap`: 生成编码所需的映射map。将码本转为流形式，map为明文到密文的映射
- `OPE_extend::gen_demap`: 生成解码所需的映射map。将码本转为流形式，map为密文到明文的映射
- `OPE_extend::code`: 读输入文件，根据字符找到在相应的map中对应的编解码字符，并写到输出文件


# 工程目录
```
.
├── readme.md
├── task # 基础任务
│   ├── CMakeLists.txt
│   ├── codebook.txt
│   ├── decrypt.cpp # 解码主文件
│   ├── detask
│   ├── encrypt.cpp # 编码主文件
│   ├── entask
│   ├── file_in.txt
│   ├── file_out.txt
│   ├── ope.cpp # 所需的功能函数
│   ├── ope.h
│   ├── pic
│   │   └── cut1.png
│   └── run.sh
└── task_extend # 扩展任务
    ├── CMakeLists.txt
    ├── codebook.txt
    ├── decrypt_extend.cpp # 解码主文件
    ├── detask
    ├── encrypt_extend.cpp # 编码主文件
    ├── entask
    ├── file_in.txt
    ├── file_out.txt
    ├── ope_extend.cpp # 所需的功能函数
    ├── ope_extend.h
    └── run.sh
```
# 运行截图
运行截图与如下： 
![运行截图](/task/pic/cut1.png)

