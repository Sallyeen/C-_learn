#include"room_base.h"

class Room_home:Room_base
{
public:
    Room_home(Player *player);
    ~Room_home();
    
    void into(Player *player); // 进入房间
    Player player;
};

class Room_normal:Room_base
{
public:
    Room_normal(Player *player, Monster monster);
    ~Room_normal();
    
    void into(Player *player); // 进入房间
    bool check(Player *player); // 判定
    void fight(Player *player, Monster *monster); // 战斗
    void settle(Player *player); // 结算
    Player *player;
    Monster monster;
};

class Room_trap:Room_base
{
public:
    Room_trap(Player *player, Monster *monster);
    ~Room_trap();
    
    void into(Player *player); // 进入房间
    bool check(Player *player); // 判定
    void fight(Player *player); // 战斗
    void settle(Player *player); // 结算
    Player *player;
    Monster monster;
};

class Room_leader:Room_base
{
public:
    Room_leader(Player *player, Monster_Leader *monster_leader);
    ~Room_leader();
    
    void into(Player *player); // 进入房间
    bool check(Player *player); // 判定
    void fight(Player *player); // 战斗
    void settle(Player *player); // 结算
    Player *player;
    Monster_Leader monster_leader;

};

class Room_weapon:Room_base
{
public:
    Room_weapon(Player *player, Weapon *weapon){};
    ~Room_weapon(){};
    
    void into(Player *player); // 进入房间
    bool check(Player *player); // 判定
    void fight(Player *player); // 战斗
    void settle(Player *player); // 结算
};
