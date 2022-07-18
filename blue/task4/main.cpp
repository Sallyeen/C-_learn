#include "main.h"
#include <iostream>
#include<unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int choose_room()
{
    srand(int(time(0)));
    int rand_choose = rand()%100 +1;
    if(rand_choose<=10 && rand_choose >= 1){
        return 1; // 营地
    }
    else if(rand_choose<=65 && rand_choose >= 11){
        return 2; //普通房间
    }
    else if(rand_choose<=80 && rand_choose >= 66){
        return 3; //陷阱房间
    }
    else if(rand_choose<=90 && rand_choose >= 81){
        return 4; //首领房间
    }
    else{
        return 5; //武器房间
    }
}

void good_buff(Player *player, int &num_good){
    if(num_good<2){
        player->life = player->life + 5 > 100 ? 100: player->life + 5;
        num_good ++;
        cout << "第 " << num_good << " 次触发持续恢复，获得 5 点生命，当前生命（"
        << player->life << "/100）" << endl;
        sleep(1);
    }
}

void bad_buff(Player *player, int &num_bad){
    if(num_bad<5){
        player->life -= 2;
        num_bad ++;
        cout << "第 " << num_bad << " 次触发持续损伤，损失 2 点生命，当前生命（"
        << player->life << "/100）" << endl;
        sleep(1);
    }
};

void clear_buff(Player *player, int &num_bad){
    player->life = player->life + 20 > 100 ? 100: player->life + 20;
    num_bad = 10;
    cout << "触发首领房间buff，负面效果已清除，并恢复20点生命，当前生命（"
    << player->life << "/100）" << endl;
    sleep(1);
};


int main ()
{
    cout << "游戏开始" << endl;
    player;
    while (player->life>0)
    {
        bool is_alive = room->check(player, num_all, num_home, num_normal,
                                 num_trap, num_leader, num_weapon);
        if(!is_alive){
            cout << "玩家死亡，游戏结束" << endl;
            return 0;
        }
        switch (choose_room())
        {
            case 1: // 营地
                num_all++; num_home++;
                room_home->into(player);
                good_buff(player, num_good);
                bad_buff(player, num_bad);
                break;
            case 2: // 普通房间
                num_all++; num_normal++;
                room_normal->into(player);
                good_buff(player, num_good);
                bad_buff(player, num_bad);
                num_good = 0; // 为下一个房间触发持续恢复做准备
                room_normal->fight(player, monster);
                room->settle(player);
                break;
            case 3: // 陷阱房间
                num_all++; num_trap++;
                room_trap->into(player);
                good_buff(player, num_good);
                bad_buff(player, num_bad);
                num_bad = 0; // 为下一个房间触发持续损伤做准备
                room_trap->fight(player);
                room->settle(player);
                break;
            case 4: // 怪物首领房间
                num_all++; num_leader++;
                room_leader->into(player);
                good_buff(player, num_good);
                clear_buff(player, num_bad);
                room_leader->fight(player);
                room->settle(player);
                break;
            case 5: // 武器房间
                num_all++; num_home++;
                room_weapon->into(player);
                good_buff(player, num_good);
                bad_buff(player, num_bad);
                room_weapon->fight(player);
                room->settle(player);
                break;
            default:
                break;
        }
    }
}