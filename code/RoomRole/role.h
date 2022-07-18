#pragma once
class Role
{
public:
    Role(){}
    Role(int life,int harm,int experience);
    Role(int life,int harm);

    int m_life;  //生命值
    int m_harm;  //伤害
    int m_experience;  //经验
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