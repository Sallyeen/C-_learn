/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-13 19:44:08
 */
#include<iostream>
#include"game_impl.h"
#include<vector>

const int choose_room();
void add_buff_baseroom(Role *explorer,bool& isBaseroom);
void add_buff_traproom(Role *explorer,bool& isTraproom);
void add_buff_leaderoom(Role *explorer,bool& isLeaderoom,bool& isBaseroom,bool& isTraproom);
int main()
{
    std::cout<<"\033[1;3;4;31m\t\t欢迎来到地牢探险游戏\033[0m"<<std::endl;
    std::cout<<"游戏开始..........."<<std::endl;
    while(_hero->m_life>0)
    {
        int room_id=choose_room();
        switch (room_id)
        {
            case 1://1--营地
                _num_campsite++;_num_goneroom++;
                _campsite->go_room(_hero,_num_goneroom);
                add_buff_leaderoom(_hero,_isLeaderoom,_isBaseroom,_isTraproom);
                add_buff_baseroom(_hero,_isBaseroom);
                add_buff_traproom(_hero,_isTraproom);
                break;
            case 2:// 2--普通房间
                _num_baseroom++;_num_goneroom++;
                _baseroom->go_room(_hero,_num_goneroom);
                add_buff_leaderoom(_hero,_isLeaderoom,_isBaseroom,_isTraproom);
                add_buff_baseroom(_hero,_isBaseroom);
                add_buff_traproom(_hero,_isTraproom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _baseroom->fighting(_hero,_monster);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _baseroom->end(_hero);
                _isBaseroom=true;
                break;
            case 3://3--陷阱房
                _num_traproom++;_num_goneroom++;
                _traproom->go_room(_hero,_num_goneroom);
                add_buff_leaderoom(_hero,_isLeaderoom,_isBaseroom,_isTraproom);
                add_buff_baseroom(_hero,_isBaseroom);
                add_buff_traproom(_hero,_isTraproom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _traproom->fighting(_hero,_monster);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _baseroom->end(_hero);
                _isTraproom=true;
                break;
            case 4:// 4--首领房 
                _num_leaderoom++;_num_goneroom++;_isLeaderoom=true;
                _leaderoom->go_room(_hero,_num_goneroom);
                add_buff_leaderoom(_hero,_isLeaderoom,_isBaseroom,_isTraproom);
                add_buff_baseroom(_hero,_isBaseroom);
                add_buff_traproom(_hero,_isTraproom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _leaderoom->fighting(_hero,_leader);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _baseroom->end(_hero);
                break;
            case 5://5--武器房
                _num_weapenroom++;_num_goneroom++;
                _weapenroom->go_room(_hero,_num_goneroom);
                add_buff_leaderoom(_hero,_isLeaderoom,_isBaseroom,_isTraproom);
                add_buff_baseroom(_hero,_isBaseroom);
                add_buff_traproom(_hero,_isTraproom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _weapenroom->fighting(_hero,_monster);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _baseroom->end(_hero);
                break;
            default:
                std::cout<<"error,restart game"<<std::endl;
                break;
        }
    }
}

const int choose_room()
{
    srand(time(0));
    int a=rand()%100+1;
    //std::cout<<"随机数:"<<a<<std::endl;
    if(a>1&&a<11){
        //std::cout<<"进入营地"<<std::endl;
        return 1;
    }
    else if(a<66){
        //std::cout<<"进入普通房间"<<std::endl;
        return 2;
    }
    else if(a<81){
        //std::cout<<"进入陷阱房间"<<std::endl;
        return 3;
    }
    else if(a<91){
        //std::cout<<"进入首领房间"<<std::endl;
        return 4;
    }
    else{
        //std::cout<<"进入武器房间"<<std::endl;
        return 5;
    }
}
void add_buff_baseroom(Role *explorer,bool& isBaseroom)
{
    if(isBaseroom&&i<=2)
    {
        explorer->m_life=explorer->m_life+5>100?100:explorer->m_life+5;
        std::printf("\033[33m持续触发普通房间buff\033[0m----持续2个房间恢复5点生命, 探险者(%d/100) 持续数量:第%d次\n",explorer->m_life,i);
        i++;
    }
    if(i>2)
    {
        i=2;
        isBaseroom=false;
    }
}
void add_buff_traproom(Role *explorer,bool& isTraproom)
{
    if(isTraproom&&j<=5)
    {
        explorer->m_life=explorer->m_life-2;
        std::printf("\033[33m持续触发陷阱房间buff\033[0m----持续5个房间损失2点生命, 探险者 (%d/100) 持续数量:第%d次\n",explorer->m_life,j);
        j++;
    }
    if(j>5)
    {
        j=2;
        isTraproom=false;
    }
}
void add_buff_leaderoom(Role *explorer,bool& isLeaderoom,bool& isBaseroom,bool& isTraproom)
{
    if(isLeaderoom)
    {
        isTraproom=false;
        isBaseroom=false;
        isLeaderoom=false;
        i=j=2;
       // std::printf("\033[33m持续触发首领房间buff\033[0m----清除所有特效buff, 探险者 (%d/100)\n",explorer->m_life);
    }
}