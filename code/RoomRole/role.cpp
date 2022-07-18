#include<iostream>
#include"role.h"

Role::Role(int life,int harm,int experience)
            :m_life(life),m_harm(harm),m_experience(experience){}

Role::Role(int life,int harm)
            :m_life(life),m_harm(harm){}

Arm::Arm(int attack,int lasting,int effect)
            :m_attack(attack),m_lasting(lasting),m_effect(effect){}