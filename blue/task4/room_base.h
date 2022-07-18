#pragma once
#include"role.h"

class Room_base
{
public:
    Room_base(){};
    ~Room_base(){};
    
    void into(Player *player); // 进入房间
    bool check(Player *player, int num_all, int num_home, int num_normal, int num_trap, int num_leader, int num_weapon); // 判定
    void fight(Player *player); // 战斗
    void settle(Player *player); // 结算
};

