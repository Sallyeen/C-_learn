/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#include"rooms_all.h"
#include"role.h"

#define explorer_life 100
#define explorer_harm 10
#define explorer_experience 0
#define explorer_enduring 0
#define monster_life 10
#define monster_harm 5
#define leader_life 40
#define leader_harm 15

int _num_campsite=0;
int _num_baseroom=0;
int _num_traproom=0;
int _num_leaderoom=0;
int _num_weapenroom=0;
int _num_goneroom=0;//走过的房间数量

Role *_hero=new Explorer(explorer_life,explorer_harm,explorer_experience,explorer_enduring);
Role *_monster=new Monster(monster_life,monster_harm);
Role *_leader=new Leader(leader_life,leader_harm);
Arm *_arm=new Arm;

Dungeon *_campsite=new Campsite(*_hero);
Dungeon *_baseroom=new BaseRoom(*_hero,*_monster);
Dungeon *_traproom=new TrapRoom(* _hero,*_monster);
Dungeon *_leaderoom=new LeaderRoom(* _hero,*_leader);
Dungeon *_weapenroom=new WeaponRoom(*_hero,*_arm);

bool _isBaseroom=false;
bool _isTraproom=false;
bool _isLeaderoom=false;

int i=2;
int j=2;//从第二个房间开始持续buff