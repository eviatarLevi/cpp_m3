#include "Member.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("follow twice after same member :"){
    Member alex, misha;
    alex.follow(misha);
    CHECK(misha.numFollowers() == 1);
    misha.follow(misha);
    CHECK(misha.numFollowers() == 1);
    misha.follow(alex);
    CHECK(alex.numFollowers() == 1);
}

TEST_CASE("check follow :"){
    Member p1,p2,p3,p4,p5;
    p1.follow(p2);
    p2.follow(p1);
    p2.follow(p3);
    p3.follow(p4);
    p4.follow(p5);
    p5.follow(p4);
    CHECK(p1.numFollowing() == 1);
    CHECK(p2.numFollowing() == 2);
    CHECK(p4.numFollowing() == 1);
    CHECK(p3.numFollowing() == 1);
}

TEST_CASE("check unfollow :"){
    Member p1,p2,p3;
    p1.follow(p2);
    p3.follow(p2);
    CHECK(p2.numFollowers() == 2);
    CHECK(p1.numFollowers() == 0);
    CHECK(p1.numFollowing()==1);
    p1.unfollow(p2);
    CHECK(p2.numFollowers() == 1);
    CHECK(p1.numFollowing() == 0);
}

void test(Member& m){
    Member p1;
    p1.follow(m);
}

TEST_CASE("Destructor :"){
    Member p1, p2;
    p1.follow(p2);
    CHECK(p2.numFollowers()==1);
    test(p2);
    CHECK(p2.numFollowers()==1);
}