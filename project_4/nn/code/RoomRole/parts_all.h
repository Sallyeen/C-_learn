/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#pragma once
#include"role.h"
//角色
class Explorer:public Role 
{
public:
    Explorer(){}
    Explorer(int life,int harm,int experience,int enduring);
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
public:
    P911(){}
    P911(int attack,int lasting,int effect);
};
class M416:public Arm//步枪
{
public:
    M416(){}
    M416(int attack,int lasting,int effect);
};
class Kar98k:public Arm//狙击枪
{
public:
    Kar98k(){}
    Kar98k(int attack,int lasting,int effect);
};