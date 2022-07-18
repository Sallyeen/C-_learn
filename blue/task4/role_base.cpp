#include"role_base.h"

Role_base::Role_base(int life, int hurt, int expe, int dura_buff, int hurt_buff)
:life(life),hurt(hurt),expe(expe),dura_buff(dura_buff),hurt_buff(hurt_buff){}

Role_base::Role_base(int life, int hurt)
:life(life),hurt(hurt){}

Weapon::Weapon(int hurt, int dura)
:hurt(hurt),dura(dura), eff(eff){}