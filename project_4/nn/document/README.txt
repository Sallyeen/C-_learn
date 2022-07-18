1.程序说明
    文字版挂机游戏设计说明:
    1.定义一个抽象地牢类Dungeon,定义四个虚函数.再定义四个房间个类Campsite,Baseroom,Traproom,Weapenroom
    继承父类,利用多态分别实现四个虚函数.定义不同房间功能.
    2.定义一个角色Role父类,再定义四个具体角色类继承Role,分别是Explorer,Monster,Leader
    3.定义一个武器父类,再定义三种具体武器类继承父类,分别是:P911,M416,Kar98k
    4.因为人持有武器,所以Role类增加耐久属性.
    5.详细信息,请阅读代码

2.代码结构

├── code
│   ├──RoomRole         
│   │       ├──dungeon.cpp
│   │       ├──dungeon.h
│   │       ├──parts_all.cpp
│   │       ├──parts_all.h             
│   │       ├──role.cpp 
│   │       ├──role.h          
│   │       ├──rooms_all.cpp      
│   │       └──rooms_all.h   
│   ├── game_impl.cpp
│   ├── game_impl.h                     
│   └── CMakeLists.txt  
│   ├── run.sh                        

3.编译
  一键编译和运行  ./run.sh

4.运行
  执行文件输入过于复杂 放在了run.sh中,编译和运行程序

5.其他
  pic1.jpg是运行部分案例
  pic2.jpg是运行部分案例
