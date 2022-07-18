/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#include"dungeon.h"
#include<iostream>

Dungeon::Dungeon(Role explorer)
        :m_explorer(explorer){}

void Dungeon::go_room(Role *explorer,int& num)
{
        std::cout<<"进入事件"<<std::endl;
}
void Dungeon::cheak_death(Role *explorer,int& num_camp,int& num_base,int& num_trap,int& num_lead,int& weapen,int& gone)//死亡判定
{
        std::cout<<"死亡判定"<<std::endl;
}
void Dungeon::fighting(Role *hero,Role *monster)//战斗开始
{
        std::cout<<"战斗开始"<<std::endl;
}
void Dungeon::end(Role *explorer)//结算
{
        std::cout<<"结算"<<std::endl;
}