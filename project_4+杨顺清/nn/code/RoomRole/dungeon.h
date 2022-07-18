/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#pragma once
#include"role.h"
#include"parts_all.h"
class Dungeon
{
public:
    Dungeon(Role explorer);
    //Dungeon(Explorer explorer,Monster monster);
    //Dungeon(Explorer explorer,Monster monster,Leader leader);


    virtual void go_room(Role *explorer,int& num);//进入房间

    virtual void cheak_death(Role *explorer,int& num_camp,int& num_base,int& num_trap,int& num_lead,int& weapen,int& gone);//死亡判定

    virtual void fighting(Role *explorer,Role* monster);//战斗开始

    virtual void end(Role *explorer);//结算

    Role m_explorer;
};
