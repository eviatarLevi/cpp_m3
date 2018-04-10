
#include "Member.h"
#include <iostream>
using namespace std;

Member::Member()//constructor
{
    counter++;
    FollowersCount = 0;
    FollowingCount = 0;
    id = ++numID;
}
Member::~Member()//distructor
{
    for(int i=0; i<FollowingCount; i++){
           unfollow(*folowList[i]);//unfollow from my list
        }
    for(int i=0; i<FollowersCount; i++){
           folowsList[i]->unfollow(*this);//unfollow from their list
        }   
    counter--;
}
int Member::count()
{
    return counter;
}

void Member::follow(Member &m)//follow
{
    if(this->id!=m.id){//check it not this obj
        for(int i=0; i<FollowingCount; i++){//check duplicity
            if(folowList[i]->id == m.id)
            {
                return;
            }
        }   
        folowList.push_back(&m);//add
        FollowingCount++;//counter
        m.newFollowers(*this);
    }
}
void Member::unfollow(Member &m)//unfollow
{
     for(int i=0; i<FollowingCount; i++){
        if(folowList[i]->id == m.id)//find to erase
        {
            folowList.erase(folowList.begin() + i);
            FollowingCount--;
            m.unFollowers(*this);
            return;
        }
    }  
}
void Member::newFollowers(Member &m)
{
    FollowersCount++;
    folowsList.push_back(&m);
}
void Member::unFollowers(Member &m)
{
    for(int i=0; i<FollowersCount; i++){
        if(folowsList[i]->id == m.id)
        {
            folowsList.erase(folowsList.begin() + i);
            FollowersCount--;
            return;
        }
    }  
}
int Member::numFollowers()
{
    return FollowersCount;
}
int Member::numFollowing()
{
    return FollowingCount;
}


