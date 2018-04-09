#pragma once

#include <vector>
using namespace std;
static int counter = 0;
static int numID = 0 ;

class Member
{
    vector<Member*> folowList;
    vector<Member*> folowsList;
    int FollowersCount;
    int FollowingCount;
    int id;
    public:
        Member();
        ~Member();
        static int count();
        void follow(Member &m);
        void unfollow(Member &m);
        void newFollowers(Member &m);
        void unFollowers(Member &m);
        int numFollowers();
        int numFollowing();
 
        
};