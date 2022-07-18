#include"role.h"

Player::Player(int life, int hurt, int expe, int dura_buff, int hurt_buff)
:Role_base(life, hurt, expe, dura_buff, hurt_buff)
{}

Monster::Monster(int life, int hurt)
:Role_base(life, hurt)
{}

Monster_Leader::Monster_Leader(int life, int hurt)
:Role_base(life, hurt)
{}

Weapon1::Weapon1(int hurt, int dura)
:Weapon(hurt, dura){}

Weapon2::Weapon2(int hurt, int dura)
:Weapon(hurt, dura){}

Weapon3::Weapon3(int hurt, int dura)
:Weapon(hurt, dura){}