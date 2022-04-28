水平有限，尽力实现。

# 功能

- 可通过选择难易等级，实现100以内、200以内或者300以内的随机数的伪随机加减法
- 可输出答对的题数、打错的题数、正确答案、答错的题目的正确答案、分数、平均用时与最短用时

# 代码实现

- 开始时，可选择题目难易程度——2(hard), 1(medium) or 0(easy)。目前难易程度仅影响题数与参与计算的数值范围
- 随机生成两个整数，利用整数的值伪随机选择加减法
- 赋分规则为一题2分

# 运行截图
easy等级运行截图：
![easy等级运行截图](/blue/add_and_minus/pic/easy.png)
medium等级运行截图：
![medium等级运行截图](/pic/medium.png)

从运行结果看，程序较好地完成了作业。

# 工程目录
```
└── add_and_minus
    ├── a.out
    ├── pic: 运行结果截图
    │   ├── easy.png
    │   └── medium.png
    ├── readme.md
    └── solution.cpp
```