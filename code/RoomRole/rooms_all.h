#include"dungeon.h"
#include"role.h"
#include"parts_all.h"
class Campsite:public Dungeon
{
public:
    Campsite(Role explorer);
    void go_room(Role *explorer,int& num);//进入房间

    Role m_explorer;
};

class BaseRoom:public Dungeon
{
public:
    BaseRoom(Role explorer,Role monster);

    void go_room(Role *explorer,int& num_room);//进入房间

    void cheak_death(Role *explorer,int& num_camp,int& num_base,int& num_trap,int& num_lead,int& weapen,int& gone);//死亡判定

    void fighting(Role* explorer,Role *monster);//战斗开始

    void end(Role *explorer);//结算

    Role m_explorer;
    Role m_monster;
};

class TrapRoom:public Dungeon
{
public:
    TrapRoom(Role explorer,Role monster);

    void go_room(Role *explorer,int& num_room);//进入房间

    void cheak_death(Role *explorer);//死亡判定

    void fighting(Role* explorer,Role *monster);//战斗开始

    void end(Role *explorer);//结算

    Role m_explorer;
    Role m_monster;
};

class LeaderRoom:public Dungeon
{
public:
    LeaderRoom(Role explorer,Role leader);

    void go_room(Role *explorer,int& num_room);//进入房间

    void cheak_death(Role *explorer);//死亡判定

    void fighting(Role* explorer,Role *leader);//战斗开始

    void end(Role *explorer);//结算

    Role m_explorer;
    Role m_leader;
};

class WeaponRoom:public Dungeon
{
public:
    WeaponRoom(Role explorer,Arm arm);

    void go_room(Role *explorer,int& num_room);//进入房间

    void cheak_death(Role *explorer);//死亡判定

    void fighting(Role* explorer,Arm *arm);//战斗开始

    void end(Role *explorer);//结算

    Role m_explorer;
    Arm m_arm;
};