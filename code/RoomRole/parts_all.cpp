#include"parts_all.h"
#include<iostream>

Explorer::Explorer(int life,int harm,int experience)
            :Role(life,harm,experience)
{
    std::cout<<"英雄诞生了,\t生命值:"<<life<<"\t伤害:"<<harm<<" \t经验值:"<<experience<<std::endl;   
}
Monster::Monster(int life,int harm)
            :Role(life,harm)
{
    std::cout<<"怪物来了,\t生命值:"<<life<<"\t伤害:"<<harm<<std::endl;   
}
Leader::Leader(int life,int harm)
            :Role(life,harm)
{
    std::cout<<"怪物首领现身,\t生命值:"<<life<<"\t伤害:"<<harm<<std::endl;
}


P911::P911(int attack,int lasting,int effect)
        :Arm(attack,lasting,effect)
{
    std::cout<<"构造手枪P911"<<std::endl;
}
M416::M416(int attack,int lasting,int effect)
        :Arm(attack,lasting,effect)
{
    std::cout<<"构造步枪M416"<<std::endl;
}
Kar98k::Kar98k(int attack,int lasting,int effect)
        :Arm(attack,lasting,effect)
{
    std::cout<<"构造狙击枪Kar98k"<<std::endl;
}