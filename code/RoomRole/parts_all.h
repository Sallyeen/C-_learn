#pragma once
#include"role.h"
//角色
class Explorer:public Role 
{
public:
    Explorer(){}
    Explorer(int life,int harm,int experience);
};
class Monster:public Role
{
public:
    Monster(){}
    Monster(int life,int harm);
};
class Leader:public Role
{
public:
    Leader(){}
    Leader(int life,int harm);
};

//武器
class P911:public Arm//手枪
{
    P911(){}
    P911(int attack,int lasting,int effect);
};
class M416:public Arm//步枪
{
    M416(){}
    M416(int attack,int lasting,int effect);
};
class Kar98k:public Arm//狙击枪
{
    Kar98k(){}
    Kar98k(int attack,int lasting,int effect);
};