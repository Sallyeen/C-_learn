#include"room.h"
#include"role_base.h"
#include"role.h"

// 角色
Player *player = new Player(100, 10, 0, 0, 0);
Monster *monster = new Monster(10, 5);
Monster_Leader *monster_leader = new Monster_Leader(40, 15);

// 房间
Room_home *room_home;
Room_normal *room_normal;
Room_trap *room_trap;
Room_leader *room_leader;
Room_weapon *room_weapon;
Room_base *room;

// 走过的房间个数
int num_all = 0;
int num_home = 0;
int num_normal = 0;
int num_trap = 0;
int num_leader = 0;
int num_weapon = 0;

// 记录buff
int num_good = 10;
int num_bad = 10;

// 施加buff特效
void good_buff();
void bad_buff();
void clear_buff();
