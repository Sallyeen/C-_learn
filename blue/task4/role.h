#pragma once
#include"role_base.h"

class Player:public Role_base
{
public:
    Player(){}
    Player(int life, int hurt, int expe, int dura_buff, int hurt_buff);
    ~Player();
    // int life = 100;
    // int hurt = 10;
    // int expe = 0;
};

class Monster:public Role_base
{
public:
    Monster(){}
    Monster(int life, int hurt);
    ~Monster();
    // int life = 40;
    // int hurt = 15;
};

class Monster_Leader:public Role_base
{
public:
    Monster_Leader(){}
    Monster_Leader(int life, int hurt);
    ~Monster_Leader();
    // int life = 40;
    // int hurt = 15;
};

class Weapon1:public Weapon
{
public:
    Weapon1(){}
    Weapon1(int hurt, int dura);
    ~Weapon1();
};

class Weapon2:public Weapon
{
public:
    Weapon2(){}
    Weapon2(int hurt, int dura);
    ~Weapon2();
};

class Weapon3:public Weapon
{
public:
    Weapon3(){}
    Weapon3(int hurt, int dura);
    ~Weapon3();
};