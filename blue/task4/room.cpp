#include"room.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<unistd.h>
#include<vector>
#include<algorithm>
using namespace std;

// 营地方法重写
// Room_home::room_base(Player *player)
//           :Room_base(Player *player){}
void Room_home::into(Player *player) // 进入房间
{
    cout << "进入营地，恢复玩家全部生命，当前生命（100/100）" << endl;
    player->life = 100;
    sleep(1);
}

// 普通房间方法重写
void Room_normal::into(Player *player) // 进入房间
{
    cout << "进入普通房间" << endl;
    // player->life = player->life + 5 > 100 ? 100 : player->life + 5;
    // cout << "恢复5点生命，当前生命（" << player->life << "/100）" << endl;
    srand(int(time(0)));
    if((1 + rand() % 10) == 1){
        player->life = player->life + 10 > 100 ? 100 : player->life + 10;
        cout << "恢复10点生命，当前生命（" << player->life << "/100）" << endl;
    }  
    sleep(1);  
}
void Room_normal::fight(Player *player, Monster *monster) // 战斗
{
    srand(int(time(0)));
    int num_monster = 1 + rand() % 3; // 随机生成怪物数量1-3
    std::vector<Monster *> monster_vec;
    // 随机改变怪物的属性值
    for(int i=0;i<num_monster;++i){
        Monster *monster_i = new Monster(10, 5);
        float change_i = (rand() % 8) - 4;
        // cout << "change_i / 10 + 1 : " << (change_i / 10 + 1) << endl;
        // cout << "life : " << monster->life << endl;
        monster_i->life = 10 * (change_i / 10 + 1);
        monster_i->hurt = 5 * (change_i / 10 + 1);
        monster_vec.push_back(monster_i);
        cout << "遇到怪物 " << i + 1 << " (" << monster_i->life << "/" << monster_i->life << ")" << endl;
        sleep(1);
    }
    sort(monster_vec.begin(),monster_vec.end(),
                [](Monster * monster1,Monster * monster2)
                {return monster1->hurt>monster2->hurt;});
    cout << "战斗开始" << endl;
    for(int i=0;i<num_monster;++i){ // 循环若干个怪物
        while(monster_vec[i]->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
            if (player->dura_buff>0&&monster->life>0){
                if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                    player->hurt = 10 + player->hurt_buff;
                    cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                    player->dura_buff--; 
                }
                else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                    player->hurt = 10 + player->dura_buff;
                    cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                    player->dura_buff--; 
                }
                else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                    srand(int(time(0)));
                    int rand_hurt = 1 + rand() % 2;
                    if(rand_hurt==1){
                        player->hurt = 10 + (player->hurt_buff * 2);
                    }
                    else{
                        player->hurt = 10 + player->dura_buff;
                    }
                    cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                    player->dura_buff--; 
                }
            }
            cout << "玩家攻击怪物 " << i+1 << "，造成 " << player->hurt<<" 点伤害，怪物 " << i+1 <<" (" << monster_vec[i]->life - player->hurt 
            << "/" << monster_vec[i]->life << ")"<<endl;
            monster_vec[i]->life -= player->hurt; 
            if(monster_vec[i]->life<=0){ // 怪物承受攻击后死亡
                cout << "怪物 " << i+1 << " 死亡" << endl;
            }
            sleep(1);         
            for(int j=i;j<num_monster;++j){ 
                if(player->life>0 && monster_vec[j]->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                    cout << "怪物 " << j+1 <<" 攻击玩家"<< "，造成 " << monster_vec[j]->hurt<<" 点伤害，玩家 " <<"(" << player->life - monster_vec[j]->hurt
                    << "/" << 100 << ")"<<endl;
                    player->life -= monster_vec[j]->hurt;
                } 
                else if(player->life<=0){
                    cout << "玩家死亡" << endl;
                }
                sleep(1);               
            }
        }
    } 
    player->expe += num_monster;
    cout << "获得 " << num_monster << " 点经验，当前经验 （" << player->expe << "/10）" << endl;
    sleep(1);   
}

// 陷阱房间方法重写
void Room_trap::into(Player *player) // 进入房间
{
cout << "进入陷阱房间" << endl;
    player->life = player->life * 0.9;
    cout << "损失十分之一生命，当前生命（" << player->life << "/100）" << endl;  
    // player->life = player->life - 2;
    // cout << "持续损伤，损失2点生命，当前生命（" << player->life << "/100）" << endl;
    sleep(1);
}
void Room_trap::fight(Player *player) // 战斗
{
    // 改变怪物的属性值
    Monster *monster = new Monster(20, 10);
    cout << "遇到怪物 1 " << " (" << monster->life << "/" << monster->life << ")" << endl;
    cout << "战斗开始" << endl;

    while(monster->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
        if (player->dura_buff>0&&monster->life>0){
            if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                player->hurt = 10 + player->hurt_buff;
                cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
            else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                player->hurt = 10 + player->dura_buff;
                cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
            else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                srand(int(time(0)));
                int rand_hurt = 1 + rand() % 2;
                if(rand_hurt==1){
                    player->hurt = 10 + (player->hurt_buff * 2);
                }
                else{
                    player->hurt = 10 + player->dura_buff;
                }
                cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
        }
        cout << "玩家攻击怪物 1"<< "，造成 " << player->hurt<<" 点伤害，怪物 1 " <<"(" << monster->life - player->hurt 
        << "/" << monster->life << ")"<<endl;
        monster->life -= player->hurt;
        sleep(1);
        if(monster->life<=0){ // 怪物承受攻击后死亡
            cout << "怪物 1 死亡" << endl;
        }
        else{ // 怪物有生命，则继续攻击玩家
            if(player->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                cout << "怪物 1 " <<"攻击玩家"<< "，造成 " << monster->hurt<<" 点伤害，玩家 " <<"(" << player->life - monster->hurt
                << "/" << 100 << ")"<<endl;
                player->life -= monster->hurt;
                sleep(1);
            }
            else{ // 玩家死亡
                cout << "玩家死亡" << endl;
                sleep(1);
            } 
        }                                  
    }
    player->expe += 1;
    cout << "获得 1 点经验，当前经验 （" << player->expe << "/10）" << endl;
    sleep(1); 
}


// 首领房间方法重写
void Room_leader::into(Player *player) // 进入房间
{
    cout << "进入首领房间" << endl;
    // player->life = player->life + 20;
    // cout << "恢复20点生命，当前生命（" << player->life << "/100）" << endl;
    sleep(1);
}
void Room_leader::fight(Player *player) // 战斗
{
    Monster_Leader *monster_leader = new Monster_Leader(40, 15);
    int life = monster_leader->life;
    cout << "遇到怪物首领 1 " << "(" << monster_leader->life << "/" << life << ")" << endl;
    cout << "战斗开始" << endl;
    int chance = 1;
    

    while(monster_leader->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
        if (player->dura_buff>0&&monster_leader->life>0){
            if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                player->hurt = 10 + player->hurt_buff;
                cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
            else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                player->hurt = 10 + player->dura_buff;
                cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
            else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                srand(int(time(0)));
                int rand_hurt = 1 + rand() % 2;
                if(rand_hurt==1){
                    player->hurt = 10 + (player->hurt_buff * 2);
                }
                else{
                    player->hurt = 10 + player->dura_buff;
                }
                cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                player->dura_buff--; 
            }
        }
        cout << "玩家攻击怪物首领 1"<< "，造成 " << player->hurt<<" 点伤害，怪物首领 1 " <<"(" << monster_leader->life - player->hurt 
        << "/" << life << ")"<<endl;
        monster_leader->life -= player->hurt;
        sleep(1);
        while(chance && monster_leader->life<=10){ // 怪物首领特效，生命不高于20时触发，且机会只一次
            monster_leader->life += 20;
            chance--;
            life = monster_leader->life;
            cout << "怪物首领 1 生命值不高于 10，触发回血buff，生命 (" << monster_leader->life << "/" << life << ")"<<endl;
        }
        if(monster_leader->life<=0){ // 怪物首领承受攻击后死亡
            cout << "怪物首领1 死亡" << endl;
        }
        else{ // 怪物首领有生命，则继续攻击玩家
            if(player->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                cout << "怪物首领 1 " <<"攻击玩家"<< "，造成 " << monster_leader->hurt + 1 <<" 点伤害，玩家 " <<"(" << player->life - monster_leader->hurt - 1
                << "/" << 100 << ")"<<endl;
                player->life = player->life - monster_leader->hurt - 1;
                sleep(1);
            }
            else{ // 玩家死亡
                cout << "玩家死亡" << endl;
                sleep(1);
            } 
        }                                  
    }
    player->expe += 5;
    cout << "获得 5 点经验，当前经验 （" << player->expe << "/10）" << endl;
    sleep(1); 
}

// 武器房间方法重写
void Room_weapon::into(Player *player) // 进入房间
{
    cout << "进入武器房间，当前生命（" << player->life << "/100）" << endl;
    sleep(1);
}
void Room_weapon::fight(Player *player) // 战斗
{
    int life = player->life;
    Monster *monster = new Monster(40, 4);
    cout << "遇到怪物 1 " << " (" << monster->life << "/" << monster->life << ")" << endl;
    srand(int(time(0)));
    int rand_weapon = 1+rand()%3;
    Weapon *weapon;
    int dura_weapon; int hurt_weapon;
    switch (rand_weapon)
    {
        case 1:
            weapon = new Weapon1(4, 6);
            dura_weapon = weapon->dura; hurt_weapon = weapon->hurt;
            cout << "怪物装备武器 1，攻击力 " << " (" << weapon->hurt<< "/" << weapon->hurt << ")，耐久 (" 
            << weapon->dura << "/" << weapon->dura << ")"<< endl;
            cout << "战斗开始" << endl;
            for(int i = weapon->dura;i>0;--i){
                if (player->dura_buff>0&&monster->life>0){
                    if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                        player->hurt = 10 + player->hurt_buff;
                        cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                        player->hurt = 10 + player->dura_buff;
                        cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                        srand(int(time(0)));
                        int rand_hurt = 1 + rand() % 2;
                        if(rand_hurt==1){
                            player->hurt = 10 + (player->hurt_buff * 2);
                        }
                        else{
                            player->hurt = 10 + player->dura_buff;
                        }
                        cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                }
                if(monster->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
                    cout << "玩家攻击怪物 1"<< "，造成 " << player->hurt<<" 点伤害，怪物 1 " <<"(" << monster->life - player->hurt 
                    << "/" << monster->life << ")"<<endl;
                    monster->life -= player->hurt;
                    sleep(1);
                    if(monster->life<=0){ // 怪物承受攻击后死亡
                        cout << "怪物 1 死亡" << endl;
                    }
                    else{ // 怪物有生命，则继续攻击玩家
                        if(player->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                            cout << "怪物 1 " <<"攻击玩家"<< "，造成 " << monster->hurt + weapon->hurt <<" 点伤害，玩家 " <<"(" 
                            << player->life - monster->hurt - weapon->hurt << "/" << 100 << ")"<<endl;
                            player->life = player->life - monster->hurt - weapon->hurt;
                            sleep(1);
                        }
                        else{ // 玩家死亡
                            cout << "玩家死亡" << endl;
                            sleep(1);
                        } 
                    }                                  
                }
            }
            if(player->life>0){
                player->dura_buff = dura_weapon; player->hurt_buff =hurt_weapon;
                cout << "结束战斗，玩家获得武器，叠加伤害" << player->hurt_buff << "，叠加耐久" << player->dura_buff << endl;
            }
            break;
        case 2:
            weapon = new Weapon2(0, 6);
            dura_weapon = weapon->dura; hurt_weapon = weapon->hurt;
            cout << "怪物装备武器 2，攻击力 " << " (" << weapon->hurt << "/" << weapon->hurt << ")，耐久 (" 
            << weapon->dura << "/" << weapon->dura << ")"<< endl;
            cout << "战斗开始" << endl;
            for(int i = weapon->dura;i>0;--i){
                if (player->dura_buff>0&&monster->life>0){
                    if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                        player->hurt = 10 + player->hurt_buff;
                        cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                        player->hurt = 10 + player->dura_buff;
                        cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                        srand(int(time(0)));
                        int rand_hurt = 1 + rand() % 2;
                        if(rand_hurt==1){
                            player->hurt = 10 + (player->hurt_buff * 2);
                        }
                        else{
                            player->hurt = 10 + player->dura_buff;
                        }
                        cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                }
                if(monster->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
                    cout << "玩家攻击怪物 1"<< "，造成 " << player->hurt<<" 点伤害，怪物 1 " <<"(" << monster->life - player->hurt 
                    << "/" << monster->life << ")"<<endl;
                    monster->life -= player->hurt;
                    sleep(1);
                    if(monster->life<=0){ // 怪物承受攻击后死亡
                        cout << "怪物 1 死亡" << endl;
                    }
                    else{ // 怪物有生命，则继续攻击玩家
                        if(player->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                            cout << "怪物 1 " <<"攻击玩家"<< "，造成 " << monster->hurt + i <<" 点伤害，玩家 " <<"(" 
                            << player->life - monster->hurt - i << "/" << 100 << ")"<<endl;
                            player->life = player->life - monster->hurt - weapon->dura;
                            sleep(1);
                        }
                        else{ // 玩家死亡
                            cout << "玩家死亡" << endl;
                            sleep(1);
                        } 
                    }                                  
                }
            }
            if(player->life>0){
                player->dura_buff = dura_weapon; player->hurt_buff =hurt_weapon;
                cout << "结束战斗，玩家获得武器 1，叠加伤害" << player->hurt_buff << "，叠加耐久" << player->dura_buff << endl;
            }
            break;
        case 3:
            weapon = new Weapon3(1, 6);
            dura_weapon = weapon->dura; hurt_weapon = weapon->hurt;
            cout << "怪物装备武器 3，攻击力 " << " (" << weapon->hurt << "/" << weapon->hurt << ")，耐久 (" 
            << weapon->dura << "/" << weapon->dura << ")"<< endl;
            cout << "战斗开始" << endl;
            for(int i = weapon->dura;i>0;--i){
                if (player->dura_buff>0 && monster->life>0){
                    if(player->hurt_buff==4){ // 武器1，直接叠加伤害
                        player->hurt = 10 + player->hurt_buff;
                        cout << "本轮攻击，玩家装备武器 1，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==0){ // 武器2，动态叠加伤害
                        player->hurt = 10 + player->dura_buff;
                        cout << "本轮攻击，玩家装备武器 2，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                    else if(player->hurt_buff==1){ // 武器3，随机叠加伤害
                        srand(int(time(0)));
                        int rand_hurt = 1 + rand() % 2;
                        if(rand_hurt==1){
                            player->hurt = 10 + (player->hurt_buff * 2);
                        }
                        else{
                            player->hurt = 10 + player->dura_buff;
                        }
                        cout << "本轮攻击，玩家装备武器 3，伤害为 " << player->hurt << endl;
                        player->dura_buff--; 
                    }
                }
                if(monster->life>0 && player->life>0){ // 只要怪物有生命，则需承受攻击
                    int rand_hurt = 1+rand()%2;
                    if(rand_hurt==1){
                        weapon->hurt = weapon->hurt * 2;
                        cout << "武器 3 触发伤害加倍效果 （" << weapon->hurt << "）" << endl;
                    }
                    else{cout << "本次攻击,武器 3 未触发伤害加倍效果" << endl;}
                    cout << "玩家攻击怪物 1"<< "，造成 " << player->hurt<<" 点伤害，怪物 1 " <<"(" << monster->life - player->hurt 
                    << "/" << monster->life << ")"<<endl;
                    monster->life -= player->hurt;
                    sleep(1);
                    if(monster->life<=0){ // 怪物承受攻击后死亡
                        cout << "怪物 1 死亡" << endl;
                    }
                    else{ // 怪物有生命，则继续攻击玩家
                        if(player->life>0){ // 只要玩家有生命，则需承受轮番攻击                   
                            cout << "怪物 1 " <<"攻击玩家"<< "，造成 " << monster->hurt + weapon->hurt <<" 点伤害，玩家 " <<"(" 
                            << player->life - monster->hurt - weapon->hurt << "/" << 100 << ")"<<endl;
                            player->life -= monster->hurt - weapon->hurt;
                            sleep(1);
                        }
                        else{ // 玩家死亡
                            cout << "玩家死亡" << endl;
                            sleep(1);
                        } 
                    }                                  
                }
            }
            if(player->life>0){
                player->dura_buff = dura_weapon; player->hurt_buff =hurt_weapon;
                cout << "结束战斗，玩家获得武器 1，叠加伤害" << player->hurt_buff << "，叠加耐久" << player->dura_buff << endl;
            }
            break;
        default:
            break;
    }
    
    player->expe += 2;
    player->life = life;
    cout << "玩家生命恢复，并获得 2 点经验，当前经验 （" << player->expe << "/10），当前生命 （" << player->life << "/100）"<< endl;
    sleep(1); 

}