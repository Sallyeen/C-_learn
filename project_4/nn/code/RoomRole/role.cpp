/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#include<iostream>
#include"role.h"

Role::Role(int life,int harm,int experience,int enduring)
            :m_life(life),m_harm(harm),m_experience(experience),m_enduring(enduring){}

Role::Role(int life,int harm)
            :m_life(life),m_harm(harm){}

Arm::Arm(int attack,int lasting,int effect)
            :m_attack(attack),m_lasting(lasting),m_effect(effect){}