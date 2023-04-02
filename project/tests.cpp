//
// Created by bienu on 5/3/2022.
//

#include "tests.h"
#include <assert.h>
#include "array.h"
#include "User.h"
#include "Message.h"
#include "Friendship.h"
#include "Network.h"
#include "RepoInMemory.h"
#include "Dictionary.h"

void testAddTAD1(){
    User u1("claudia", "cl100","CLaudia");
    User u2("camelia","cami190","Camelia");
    assert(u1.getUserName()=="claudia");
    Array<User> testare;
    testare.add(u1);
    testare.add(u2);
    assert(testare.exists(u1));
}

void testAddTAD2(){
    User u1("claudia", "cl100","CLaudia");
    User u2("camelia","cami190","Camelia");
    Dictionary<string,User> dict;
    dict.add(u1.getUserName(),u1);
    dict.add(u2.getUserName(),u2);
    assert(dict.getSize()==2);
    dict.deleting(u1.getUserName(),u1);
    assert((dict.getSize()==1));
    assert(dict.search(u1.getUserName()).getUserName().empty());
}

void testEntities()
{
    User u1("claudia", "cl100","CLaudia");
    User u2("camelia","cami190","Camelia");

    Array<User> t;
    t.add(u1);
    t.add(u2);

    Friendship f1(u1,u2);

    Message m1("claudia", "camelia","Hello!");


    assert(f1.getFriend1().getUserName()=="claudia");

}

void testNetwork()
{
//    RepoInMemory repository;
//    Network n(repository);
//    n.addUser("claudic", "cl100","CLaudia");
//    n.addUser("camelia","cami190","Camelia");
//    assert(n.getUsers().getSize()==17);
//    n.addMessage("claudia", "camelia", "hello");
//    n.addMessage("camelia", "claudia", "helloo");
    //assert(n.getConversation("claudia","camelia").size()==2);


}

void allTests(){
    testAddTAD1();
    testAddTAD2();
    testEntities();
    testNetwork();
}