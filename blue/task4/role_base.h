#pragma once

class Role_base
{
public:
    Role_base(){}
    Role_base(int life, int hurt, int expe, int dura_buff, int hurt_buff);
    Role_base(int life, int hurt);
    ~Role_base();

    int life; // 生命值
    int hurt; // 伤害值
    int expe; // 经验值
    int dura_buff; // 叠加耐久
    int hurt_buff; // 叠加伤害
};

class Weapon
{
public:
    Weapon(){}
    Weapon(int hurt, int dura);
    ~Weapon();

    int hurt; // 攻击力
    int dura; // 耐久
    int eff; // 效果
};