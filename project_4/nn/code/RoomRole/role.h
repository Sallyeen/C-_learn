/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#pragma once
class Role
{
public:
    Role(){}
    Role(int life,int harm,int experience,int enduring);
    Role(int life,int harm);

    int m_life;  //生命值
    int m_harm;  //伤害
    int m_experience;  //经验
    int m_enduring; //探险者获得武器时的耐久力
};

class Arm
{
public:
    Arm(){}
    Arm(int attack,int lasting,int effect);

    int m_attack;//攻击力
    int m_lasting;//耐久
    int m_effect;//效果
};