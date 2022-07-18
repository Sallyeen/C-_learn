#include"room_base.h"
#include<iostream>
#include<unistd.h>
using namespace std;

void Room_base::into(Player *player)// 进入房间
{
    cout << "进入房间" << endl;
}

bool Room_base::check(Player *player, int num_all, int num_home, int num_normal,
int num_trap, int num_leader, int num_weapon)// 判定
{
    if(player->life<=0){
        cout << "经死亡判定, 玩家已死亡" << endl;
        printf("走过的房间总数:%d,\t营地:%d,\t普通房间:%d,\t陷阱房间:%d,\t首领房间%d,\t武器库:%d\n"
                    ,num_all, num_home, num_normal, num_trap, num_leader, num_weapon);
        return false;
    }
    return true;
}

void Room_base::fight(Player *player) // 战斗
{
    cout << "开始战斗" << endl;
}

void Room_base::settle(Player *player) // 结算
{
    if(player->expe>=10){
        player->life = 100;
        player->expe = player->expe - 10;
        cout << "玩家经验积累已达上限，现恢复生命 （" << player->life << "/100），经验 （" << player->expe << "/10）"<< endl;
    }
    cout << "结算结束" << endl;
    sleep(1); 
}

