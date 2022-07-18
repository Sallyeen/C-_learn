/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#include"rooms_all.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<unistd.h>

Campsite::Campsite(Role explorer)
         :Dungeon(explorer){}
//营地
void Campsite::go_room(Role *explorer,int& num)
{
    std::cout<<"\033[32m进入营地\033[0m"<<std::endl;
    std::cout<<"\033[32;1m恢复探险者的全部生命! (100/100)\033[0m"<<std::endl;sleep(1);
    explorer->m_life=100;
}

//普通房间
BaseRoom::BaseRoom(Role explorer,Role monster)
            :Dungeon(explorer),m_monster(monster){}
void BaseRoom::go_room(Role *explorer,int& num_room)
{
    std::cout<<"\033[32m进入普通房间\033[0m"<<std::endl;
    explorer->m_life=explorer->m_life+5>100?100:explorer->m_life+5;
    std::printf("---------buff特效:连续2个房间恢复5点生命! 探险者 (%d/100)\n",explorer->m_life);
    srand(time(0));
    if(1==rand()%10)   //10%概率恢复10点生命
    {
        explorer->m_life=explorer->m_life+10>100?100:explorer->m_life+10;
        std::printf("10%%恢复探险者10点生命生效,(%d/100)\n",explorer->m_life);sleep(1);
    }
}
void BaseRoom::cheak_death(Role *explorer,int& num_camp,int& num_base,int& num_trap,int& num_lead,int& weapen,int& gone)
{
    if(explorer->m_life<=0)
    {
        std::cout<<"\033[31;1m经死亡判定,探险者已死亡\033[0m"<<std::endl;
        std::printf("走过的房间总数:%d,\t营地:%d,\t普通房间:%d,\t陷阱房间:%d,\t首领房间%d,\t武器库:%d\n"
                    ,gone,num_camp,num_base,num_trap,num_lead,weapen);
    }
}
void BaseRoom::fighting(Role* explorer,Role *monster)
{
    //随机生成怪物
    double arr_num[5]={0.0,0.1,0.2,0.3,0.4};
    srand(time(0));
   
    int num_monster=rand()%3+1;//1-3个怪物
    //std::cout<<"monser数量:"<<num_monster<<std::endl;
    std::vector<Role *>monster_vec;
    while(num_monster>0)
    {
        Role *monster_plus=new Monster;
        int id_monster=rand()%5;  //+-40%属性
        //std::cout<<"id_monster="<<id_monster<<std::endl;
        if(id_monster%2==0)
        {
            monster_plus->m_life=10+arr_num[id_monster]*10;
            monster_plus->m_harm=5+arr_num[id_monster]*5;
            //std::cout<<"+  "<<monster_plus->m_life<<"\t"<<monster_plus->m_harm<<std::endl;
        }
        else
        {
            monster_plus->m_life=10-arr_num[id_monster]*10;
            monster_plus->m_harm=5-arr_num[id_monster]*5;
            //std::cout<<"-  "<<monster_plus->m_life<<"\t"<<monster_plus->m_harm<<std::endl;
        }
        monster_vec.emplace_back(monster_plus);
        num_monster--;
    }
    std::sort(monster_vec.begin(),monster_vec.end(),
                [](Role * monster1,Role * monster2)
                {return monster1->m_harm>monster2->m_harm;});
   //开始战斗
    for(int i=0;i<monster_vec.size();++i)
    {   
        //std::cout<<"size="<<monster_vec.size()<<std::endl;
        printf("遇到怪物%d (%d/%d)  伤害:%d    ",i+1,monster_vec[i]->m_life,monster_vec[i]->m_life,monster_vec[i]->m_harm);
    }
    std::cout<<"\033[31;1m\n\t战斗开始\033[0m"<<std::endl; sleep(1);
    
    int monster_size=monster_vec.size();
    //std::cout<<"flags:"<<monster_size<<std::endl;
    switch (monster_size)
    {
    case 1:
    {
        int residual_life_mon=monster_vec[0]->m_life;
        while(residual_life_mon>0)
        {
            if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon=residual_life_mon-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物1,造成%d点伤害,怪物1 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon,monster_vec[0]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon=residual_life_mon-10;
                std::printf("探险者攻击怪物1,造成10点伤害,怪物1 (%d/%d)\n",residual_life_mon,monster_vec[0]->m_life);sleep(1);
            }

            if(residual_life_mon>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[0]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",1,monster_vec[0]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
        }
        std::cout<<"怪物1死亡"<<std::endl;
        explorer->m_experience=explorer->m_experience+1;
        std::printf("获得1点经验,当前经验值 (%d/10)\n",explorer->m_experience);sleep(1);
        break;
    }
    case 2:
    {
        int residual_life_mon_1=monster_vec[0]->m_life;
        int residual_life_mon_2=monster_vec[1]->m_life;
        while(residual_life_mon_1>0)
        {
           if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon_1=residual_life_mon_1-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物1,造成%d点伤害,怪物1 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon_1,monster_vec[0]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon_1=residual_life_mon_1-10;
                std::printf("探险者攻击怪物1,造成10点伤害,怪物1 (%d/%d)\n",residual_life_mon_1,monster_vec[0]->m_life);sleep(1);
            }
            if(residual_life_mon_1>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[0]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",1,monster_vec[0]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
                explorer->m_life=explorer->m_life-monster_vec[1]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",2,monster_vec[1]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
        }
        std::cout<<"怪物1死亡"<<std::endl;sleep(1);

        while(residual_life_mon_2>0)
        {
            if(residual_life_mon_2>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[1]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",2,monster_vec[1]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
            //residual_life_mon_2=residual_life_mon_2-10;
            //std::printf("探险者攻击怪物%d,造成10点伤害,怪物%d (%d/%d)\n",2,2,residual_life_mon_2,monster_vec[1]->m_life);sleep(1);

            if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon_2=residual_life_mon_2-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物2,造成%d点伤害,怪物2 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon_2,monster_vec[1]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon_2=residual_life_mon_2-10;
                std::printf("探险者攻击怪物2,造成10点伤害,怪物2 (%d/%d)\n",residual_life_mon_2,monster_vec[1]->m_life);sleep(1);
            }

        }
        std::cout<<"怪物2死亡"<<std::endl;
        explorer->m_experience=explorer->m_experience+2;
        std::printf("获得2点经验,当前经验值 (%d/10)\n",explorer->m_experience);sleep(1);
        break;
    }
    case 3:
    {
        int residual_life_mon_1=monster_vec[0]->m_life;
        int residual_life_mon_2=monster_vec[1]->m_life;
        int residual_life_mon_3=monster_vec[2]->m_life;
        //std::cout<<"residual_life_mon_1:"<<residual_life_mon_1<<std::endl;
        while(residual_life_mon_1>0)
        {
            if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon_1=residual_life_mon_1-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物1,造成%d点伤害,怪物1 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon_1,monster_vec[0]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon_1=residual_life_mon_1-10;
                std::printf("探险者攻击怪物1,造成10点伤害,怪物1 (%d/%d)\n",residual_life_mon_1,monster_vec[0]->m_life);sleep(1);
            }
            //residual_life_mon_1=residual_life_mon_1-10;
            //std::cout<<"residual_life_mon_1:"<<residual_life_mon_1<<std::endl;
            //std::printf("探险者攻击怪物%d,造成10点伤害,怪物%d (%d/%d)\n",1,1,residual_life_mon_1,monster_vec[0]->m_life);sleep(1);
            if(residual_life_mon_1>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[0]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",1,monster_vec[0]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
                explorer->m_life=explorer->m_life-monster_vec[1]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",2,monster_vec[1]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
                explorer->m_life=explorer->m_life-monster_vec[2]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",3,monster_vec[2]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
        }
        std::cout<<"怪物1死亡"<<std::endl;sleep(1);

        while(residual_life_mon_2>0)
        {
            if(residual_life_mon_2>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[1]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",2,monster_vec[1]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
                explorer->m_life=explorer->m_life-monster_vec[2]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",3,monster_vec[2]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
            if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon_2=residual_life_mon_2-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物2,造成%d点伤害,怪物2 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon_2,monster_vec[1]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon_2=residual_life_mon_2-10;
                std::printf("探险者攻击怪物2,造成10点伤害,怪物2 (%d/%d)\n",residual_life_mon_2,monster_vec[1]->m_life);sleep(1);
            }
            //residual_life_mon_2=residual_life_mon_2-10;
            //std::printf("探险者攻击怪物%d,造成10点伤害,怪物%d (%d/%d)\n",2,2,residual_life_mon_2,monster_vec[1]->m_life);sleep(1);
        }
        std::cout<<"怪物2死亡"<<std::endl;sleep(1);
        while(residual_life_mon_3>0)
        {
            if(residual_life_mon_3>0)
            {
                explorer->m_life=explorer->m_life-monster_vec[2]->m_harm;
                std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",3,monster_vec[2]->m_harm,explorer->m_life,100);
                if(explorer->m_life<=0)
                {
                    std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                    return;
                }
            }
            if(explorer->m_enduring>0)
            {
                explorer->m_enduring--;
                residual_life_mon_3=residual_life_mon_3-explorer->m_harm;
                std::printf("探险者\033[34m持有武器\033[0m攻击怪物3,造成%d点伤害,怪物3 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon_3,monster_vec[2]->m_life,explorer->m_enduring);sleep(1);
                if(explorer->m_enduring==0)
                {
                    std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                    explorer->m_harm=10;
                }
            }
            else
            {
                residual_life_mon_3=residual_life_mon_3-10;
                std::printf("探险者攻击怪物3,造成10点伤害,怪物3 (%d/%d)\n",residual_life_mon_3,monster_vec[2]->m_life);sleep(1);
            }
            //residual_life_mon_3=residual_life_mon_3-10;
            //std::printf("探险者攻击怪物%d,造成10点伤害,怪物%d (%d/%d)\n",3,3,residual_life_mon_3,monster_vec[2]->m_life);sleep(1);
        }
        std::cout<<"怪物3死亡"<<std::endl;
        explorer->m_experience=explorer->m_experience+3;
        std::printf("获得3点经验,当前经验值 (%d/10)\n",explorer->m_experience);sleep(1);
        break;  
    }
    default:
        std::cout<<"没有怪物"<<std::endl;sleep(1);
        break;
    }
}
void BaseRoom::end(Role *explorer)
{
    if(explorer->m_experience>10)
    {
        explorer->m_life=100;
        explorer->m_experience=explorer->m_experience-10;
        std::printf("\033[32;1m探险者经验超越上线,触发恢复全部生命特效,探险者  (100/100)\t当前经验:%d\n\033[0m",explorer->m_experience);sleep(1);
    }
    std::cout<<"结算结束"<<std::endl;
}

//陷阱房间
TrapRoom::TrapRoom(Role explorer,Role monster)
            :Dungeon(explorer),m_monster(monster){}
void TrapRoom::go_room(Role *explorer,int& num_room)
{
    std::cout<<"\033[32m进入陷阱房\033[0m"<<std::endl;sleep(1);
    explorer->m_life=explorer->m_life-2;
    std::printf("---------buff特效:连续5个房间损失2点生命! 探险者 (%d/100)\n",explorer->m_life);
    //std::cout<<"explorer life 1:"<<explorer->m_life<<std::endl;
    explorer->m_life=explorer->m_life-explorer->m_life*0.1;
    std::printf("探险者损失当前10%%的生命,探险者  (%d/%d)\n",explorer->m_life,100);
}
void TrapRoom::cheak_death(Role *explorer)
{

}
void TrapRoom::fighting(Role* explorer,Role *monster)
{
    //std::cout<<"explorer life 2:"<<explorer->m_life<<std::endl;
    Role *monster_plus=new Monster;  
    monster_plus->m_life=2*monster->m_life;  
    monster_plus->m_harm=2*monster->m_harm;
    std::printf("遇到怪物1 (20/20)   伤害:%d\n",monster_plus->m_harm);

    std::cout<<"\033[31;1m\t战斗开始\033[0m"<<std::endl;sleep(1);

    int residual_life_mon=monster_plus->m_life;
    while(residual_life_mon>0)
    {
        if(explorer->m_enduring>0)
        {
            explorer->m_enduring--;
            residual_life_mon=residual_life_mon-explorer->m_harm;
            std::printf("探险者\033[34m持有武器\033[0m攻击怪物,造成%d点伤害,怪物 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon,monster_plus->m_life,explorer->m_enduring);sleep(1);
            if(explorer->m_enduring==0)
            {
                std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                explorer->m_harm=10;
            }
        }
        else
        {
            residual_life_mon=residual_life_mon-10;
            std::printf("探险者攻击怪物,造成10点伤害,怪物 (%d/%d)\n",residual_life_mon,monster_plus->m_life);sleep(1);
        }
        //residual_life_mon=residual_life_mon-10;
        //std::printf("探险者攻击怪物%d,造成10点伤害,怪物%d (%d/%d)\n",1,1,residual_life_mon,monster_plus->m_life);sleep(1);
        if(residual_life_mon>0)
        {
            explorer->m_life=explorer->m_life-10;
            std::printf("怪物%d攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",1,monster_plus->m_harm,explorer->m_life,100);
            if(explorer->m_life<=0)
            {
                std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                return;
            }
        }
    }
    std::cout<<"怪物1死亡"<<std::endl;sleep(1);
    explorer->m_experience=explorer->m_experience+1;
    std::printf("获得1点经验,当前经验值 (%d/10)\n",explorer->m_experience);
}
void TrapRoom::end(Role *explorer)
{
    std::cout<<"结算结束"<<std::endl;sleep(1);
    if(explorer->m_experience>10)
    {
        explorer->m_life=100;
        explorer->m_experience=explorer->m_experience-10;
    }
}

//首领房间
LeaderRoom::LeaderRoom(Role explorer,Role leader)
            :Dungeon(explorer),m_leader(leader){}
void LeaderRoom::go_room(Role *explorer,int& num_room)
{
    std::cout<<"\033[32m进入怪物首领房\033[0m"<<std::endl;
    std::cout<<"---------buff特效:清除所有buff效果!-----------"<<std::endl;
    explorer->m_life=explorer->m_life+20>100?100:explorer->m_life+20;
    std::printf("恢复探险者20点生命  探险者(%d/100)\n",explorer->m_life);
}
void LeaderRoom::cheak_death(Role *explorer)
{

}
void LeaderRoom::fighting(Role* explorer,Role *leader)
{
    Role * leader_plus=leader;
    std::printf("遇到怪物首领  (%d/%d) \t伤害:%d \n",leader_plus->m_life,40,15);
    std::cout<<"\033[31;1m\t战斗开始\033[0m"<<std::endl;
    int residual_life_leader=leader_plus->m_life;
    int leader_plus_harm=leader_plus->m_harm;
    bool once=true;
    while(residual_life_leader>0)
    {
         if(explorer->m_enduring>0)
        {
            explorer->m_enduring--;
            residual_life_leader=residual_life_leader-explorer->m_harm;
            std::printf("探险者\033[34m持有武器\033[0m攻击怪物,造成%d点伤害,怪物 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_leader,leader_plus->m_life,explorer->m_enduring);sleep(1);
            if(explorer->m_enduring==0)
            {
                std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                explorer->m_harm=10;
            }
        }
        else
        {
            residual_life_leader=residual_life_leader-10;
            std::printf("探险者攻击怪物,造成10点伤害,怪物 (%d/%d)\n",residual_life_leader,leader_plus->m_life);sleep(1);
        }
        //residual_life_leader=residual_life_leader-10;
        //std::printf("探险者攻击怪物首领,造成10点伤害,怪物首领 (%d/%d)\n",residual_life_leader,leader_plus->m_life);sleep(1);
        if(residual_life_leader>10||!once)
        {
            if(residual_life_leader<=0)break;
            explorer->m_life=explorer->m_life-leader_plus_harm;
            std::printf("怪物首领攻击探险者,造成%d点伤害,探险者 (%d/%d)\n",leader_plus_harm,explorer->m_life,100);
            ++leader_plus_harm;
            if(explorer->m_life<=0)
            {
                std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                return;
            }
        }
        if(residual_life_leader<=10&&once)
        {
            once=false;//仅触发一次
            residual_life_leader=residual_life_leader+20;
            std::printf("\033[32m怪物首领生命小于等于10,恢复20点生命触发,怪物首领  (%d/%d)\n\033[0m",residual_life_leader,40);
        }
    }
    std::cout<<"怪物首领死亡"<<std::endl;
    explorer->m_experience=explorer->m_experience+5;
    std::printf("获得5点经验,当前经验值 (%d/10)\n",explorer->m_experience);
}
void LeaderRoom::end(Role *explorer)
{

}

//武器库
WeaponRoom::WeaponRoom(Role explorer,Arm arm)
            :Dungeon(explorer),m_arm(arm){}
void WeaponRoom::go_room(Role *explorer,int& num_room)
{
    std::cout<<"\033[32m进入武器库\033[0m"<<std::endl;
    std::printf("记录探险者生命值  探险者 (%d/100)\n",explorer->m_life);
}
void WeaponRoom::cheak_death(Role *explorer)
{

}
void WeaponRoom::fighting(Role* explorer,Role *arm)//此处Role *arm未使用  带必须定义Role* 因为此函数是虚函数
{
    int re_life=explorer->m_life;//记录探险者进入武器库生命,出门恢复
    Role * monster_plus=new Monster;
    monster_plus->m_life=0.4*100;
    monster_plus->m_harm=0.4*10;
    std::printf("遇到怪物 (%d/%d) 伤害:%d",40,40,4);
    srand(time(0));
    int id_arm=rand()%3+1;
    int like=rand()%2+1;//武器三50%触发特效
    //std::cout<<"id_arm:"<<id_arm<<std::endl;
    Arm *arm_equip;
    switch (id_arm)
    {
        case 1:
            arm_equip=new P911(4,6,0);
            std::printf("  ##装配武器1:P911 攻击力:%d 耐久力:%d 无特效\n",4,6);
            break;
        case 2:
            arm_equip=new M416(0,6,1);
            arm_equip->m_attack=6;
            std::printf("  ##装配武器2:M416 攻击力:%d 耐久力:%d 触发特效\n",6,6);
            break;
        case 3:
            arm_equip=new Kar98k(1,6,1);
            if(1==like)
            {   
                arm_equip->m_attack=2;
                std::printf("  ##装配武器3:Kar98k 攻击力:%d 耐久力:%d 50%%特效已触发\n",2,6);
            }
            else
            {
                std::printf("  ##装配武器3:Kar98k 攻击力:%d 耐久力:%d 50%%特效未触发\n",1,6);
            }
            break;
        default:
            std::cout<<"error,武器库没有武器"<<std::endl;
            break;
    }
    std::cout<<"\033[31;1m\t战斗开始\033[0m"<<std::endl;sleep(1);

    int residual_life_mon=monster_plus->m_life;
    int monster_harm_arm=monster_plus->m_harm+arm_equip->m_attack;
    int arm_lasting=arm_equip->m_lasting;
    while(residual_life_mon>0)
    {
        if(explorer->m_enduring>0)
        {
            explorer->m_enduring--;
            residual_life_mon=residual_life_mon-explorer->m_harm;
            std::printf("探险者\033[34m持有武器\033[0m攻击怪物,造成%d点伤害,怪物1 (%d/%d)  武器耐久:%d\n",explorer->m_harm,residual_life_mon,40,explorer->m_enduring);sleep(1);
            if(explorer->m_enduring==0)
            {
                std::cout<<"\033[5;1;31m武器损坏\033[0m"<<std::endl;
                explorer->m_harm=10;
            }
        }
        else
        {
            residual_life_mon=residual_life_mon-10;
            std::printf("探险者攻击怪物1,造成10点伤害,怪物1 (%d/%d)\n",residual_life_mon,40);sleep(1);
        }
        //residual_life_mon=residual_life_mon-10;
        //std::printf("探险者攻击怪物,造成10点伤害,怪物 (%d/%d)\n",residual_life_mon,40);
        if(residual_life_mon>0)
        {
            arm_lasting--;
            explorer->m_life=explorer->m_life-monster_harm_arm;
            std::printf("怪物持武器攻击探险者,造成%d点伤害,武器耐久:%d,探险者 (%d/%d)\n",monster_harm_arm,arm_lasting,explorer->m_life,100);sleep(1);
            if(explorer->m_life<=0)
            {
                std::cout<<"\033[31m探险者BBQ,被怪物打死\033[0m"<<std::endl;
                return;
            }
            if(arm_lasting<=0)
            {
                std::printf("武器已损坏");
                monster_harm_arm=monster_plus->m_harm;
            }
        }
    }
    std::cout<<"怪物死亡"<<std::endl;sleep(1);

    if(explorer->m_enduring>0)//说明探险者此时有武器,需要更新
    {
        explorer->m_harm=10;
    }
    explorer->m_harm=explorer->m_harm+arm_equip->m_attack;
    explorer->m_enduring=arm_equip->m_lasting;
    std::printf("\033[1;33m探险者获得怪物武器%d,并装备,获得武器伤害加成,伤害:%d,持久:%d\n\033[0m",id_arm,explorer->m_harm,explorer->m_enduring);
    explorer->m_experience=explorer->m_experience+2;
    std::printf("获得2点经验,当前经验值 (%d/10)",explorer->m_experience);
    explorer->m_life=re_life;
    std::printf("   并恢复进入房间时的生命值 (%d/100)\n",explorer->m_life);
}
void WeaponRoom::end(Role *explorer)
{

}