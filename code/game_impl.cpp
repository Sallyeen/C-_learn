/*
 * @Author: Shunqing Yang 
 * @Date: 2022-07-09 13:22:58 
 * @Last Modified by: Shunqing Yang
 * @Last Modified time: 2022-07-11 17:01:08
 */
#include<iostream>
#include"game_impl.h"
#include<vector>

const int choose_room();
int main()
{
    Role *_hero=new Explorer(explorer_life,explorer_harm,explorer_experience);
    Role *_monster=new Monster(monster_life,monster_harm);
    Role *_leader=new Leader(leader_life,leader_harm);

    Dungeon *_campsite=new Campsite(*_hero);
    Dungeon *_baseroom=new BaseRoom(*_hero,*_monster);
    Dungeon *_traproom=new TrapRoom(* _hero,*_monster);
    Dungeon *_leaderoom=new LeaderRoom(* _hero,*_leader);

    int _num=1;
    //_campsite->go_room(_hero,_num);

    //Role *_monster_base_1=new Monster(monster_life,monster_harm);
    // _baseroom->go_room(_hero,_num);
    // _baseroom->fighting(_hero,_monster);
    // _baseroom->end(_hero);
   // _baseroom->cheak_death(_hero);

    //Role *_monster_base_2=new Monster(monster_life,monster_harm);
    // _traproom->go_room(_hero,_num);
    // _traproom->fighting(_hero,_monster);
    // _traproom->end(_hero);
    //_traproom->cheak_death(_hero);

    _leaderoom->go_room(_hero,_num);
    _leaderoom->fighting(_hero,_leader);

    int _num_campsite=0;
    int _num_baseroom=0;
    int _num_traproom=0;
    int _num_leaderoom=0;
    int _num_weapenroom=0;
    int _num_goneroom=0;//走过的房间数量

/*
    while(_hero->m_life>0)
    {
        int room_id=choose_room();  
                         
        //std::cout<<room_id<<std::endl;
        switch (room_id)
        {
            case 1://1--营地
                _num_campsite++;_num_goneroom++;
                _campsite->go_room(_hero,_num_goneroom);
                break;
            case 2:// 2--普通房间
                _num_baseroom++;_num_goneroom++;
                _baseroom->go_room(_hero,_num_goneroom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _baseroom->fighting(_hero,_monster);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _baseroom->end(_hero);
                break;
            case 3://3--陷阱房
                _num_traproom++;_num_goneroom++;
                _traproom->go_room(_hero,_num_goneroom);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                if(_hero->m_life<=0)break;
                _traproom->fighting(_hero,_monster);
                _baseroom->cheak_death(_hero,_num_campsite,_num_baseroom,_num_traproom,_num_leaderoom,_num_weapenroom,_num_goneroom);
                _traproom->end(_hero);
                break;
            case 4:// 4--首领房 
                _num_leaderoom++;_num_goneroom++;
                //std::cout<<"进入首领房"<<std::endl;
                
                break;
            case 5://5--武器房
                _num_weapenroom++;_num_goneroom++;
                //std::cout<<"进入武器库"<<std::endl;

                break;
            default:
                std::cout<<"error,restart game"<<std::endl;
                break;
        }

    }

*/
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