
#include "Member.h"
#include <iostream>
using namespace std;

Member::Member()
{
    counter++;
    FollowersCount = 0;
    FollowingCount = 0;
    id = ++numID;
}
Member::~Member()
{
    for(int i=0; i<FollowingCount; i++){
           unfollow(*folowList[i]);
        }
    for(int i=0; i<FollowersCount; i++){
           folowsList[i]->unfollow(*this);
        }   
    counter--;
}
int Member::count()
{
    return counter;
}

void Member::follow(Member &m)
{
    if(this->id!=m.id){
        for(int i=0; i<FollowingCount; i++){
            if(folowList[i]->id == m.id)
            {
                return;
            }
        }   
        folowList.push_back(&m);
        FollowingCount++;
        m.newFollowers(*this);
    }
}
void Member::unfollow(Member &m)
{
     for(int i=0; i<FollowingCount; i++){
        if(folowList[i]->id == m.id)
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


