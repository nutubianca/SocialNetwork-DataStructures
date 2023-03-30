#include "RepoInMemory.h"

RepoInMemory::RepoInMemory() :
        users(),
        friendships(){
    startUpData();
}

RepoInMemory::~RepoInMemory() = default;

Dictionary<string, User>& RepoInMemory::getUsers() {
    return this->users;
}

Array<Friendship>& RepoInMemory::getFriendships() {
    return this->friendships;
}

Array<Message> &RepoInMemory::getConversations() {
    return this->conversations;
}

void RepoInMemory::addUser(User &u) {
    users.add(u.getUserName(), u);

}

void RepoInMemory::updateUser(User &u1, User &u2) {
    users.update(u1.getUserName(), u1,
                 u2.getUserName(), u2);

}

void RepoInMemory::deleteUser(User &u) {
    users.deleting(u.getUserName(), u);

}

void RepoInMemory::addFriendship(Friendship &f) {
    friendships.add(f);

}

void RepoInMemory::deleteFriendship(Friendship &f) {
    friendships.deleting(f);
}

void RepoInMemory::addMessage(Message &m) {
    conversations.add(m);
}


void RepoInMemory::updateMessage(Message &m1, Message &m2) {
    conversations.update(m1, m2);
}

void RepoInMemory::deleteMessage(Message &m) {
    conversations.deleting(m);
}

void RepoInMemory::startUpData() {
    User u1("ana","ana123","Ana");
    User u2("teo","teo123","Teo");
    User u3("cami","cami123","Cami");
    User u4("claudia","claudia123","Claudia");
    User u5("ale","ale123","Alecsandra");
    User u6("ralu","ralu123","Raluca");
    User u7("cristi","cristi123","Cristian");
    User u8("irina","irina123","Irina");
    User u9("eliza","eliza123","Eliza");
    User u10("maria","maria123","Maria");
    User u11("naomi","naomi123","Naomi");
    User u12("manu","manu123","Emanuel");
    User u13("crina","crina123","Crinela");
    User u14("diana","diana123","Diana");
    User u15("edith","edith123","Edith");

    users.add(u1.getUserName(),u1);
    users.add(u2.getUserName(),u2);
    users.add(u3.getUserName(),u3);
    users.add(u4.getUserName(),u4);
    users.add(u5.getUserName(),u5);
    users.add(u6.getUserName(),u6);
    users.add(u7.getUserName(),u7);
    users.add(u8.getUserName(),u8);
    users.add(u9.getUserName(),u9);
    users.add(u10.getUserName(),u10);
    users.add(u11.getUserName(),u11);
    users.add(u12.getUserName(),u12);
    users.add(u13.getUserName(), u13);
    users.add(u14.getUserName(),u14);
    users.add(u15.getUserName(),u15);

    Friendship f1(u1,u2);
    Friendship f2(u1,u3);
    Friendship f3(u2,u3);
    Friendship f4(u4,u5);
    Friendship f5(u4,u6);
    Friendship f6(u5,u6);
    Friendship f7(u7,u8);
    Friendship f8(u7,u9);
    Friendship f9(u8,u9);
    Friendship f10(u10,u11);
    Friendship f11(u10,u12);
    Friendship f12(u11,u12);
    Friendship f13(u13,u14);
    Friendship f14(u13,u15);
    Friendship f15(u14,u15);

    friendships.add(f1);
    friendships.add(f2);
    friendships.add(f3);
    friendships.add(f4);
    friendships.add(f5);
    friendships.add(f6);
    friendships.add(f7);
    friendships.add(f8);
    friendships.add(f9);
    friendships.add(f10);
    friendships.add(f11);
    friendships.add(f12);
    friendships.add(f13);
    friendships.add(f14);
    friendships.add(f15);

    Message m1(u1.getUserName(),u2.getUserName(),"Buna, teo!");
    Message m111(u2.getUserName(),u1.getUserName(),"hello ana!");
    Message m2(u1.getUserName(),u3.getUserName(),"Ce faaci?");
    Message m22(u3.getUserName(),u1.getUserName(),"Ce faaci, anuta?");

    Message m3(u2.getUserName(),u3.getUserName(),"hellooo!");

    Message m4(u4.getUserName(),u5.getUserName(),"Hello!");
    Message m5(u4.getUserName(),u6.getUserName(),"Buna");
    Message m6(u5.getUserName(),u6.getUserName(),"Buna!");

    Message m7(u7.getUserName(),u8.getUserName(),"Buna!");
    Message m8(u7.getUserName(),u9.getUserName(),"Ce faaci?");
    Message m9(u8.getUserName(),u9.getUserName(),"Buna!");

    Message m10(u10.getUserName(),u11.getUserName(),"Buna!");
    Message m11(u10.getUserName(),u12.getUserName(),"Ce faaci?");
    Message m12(u11.getUserName(),u12.getUserName(),"Buna!");

    Message m13(u13.getUserName(),u14.getUserName(),"Hello!");
    Message m14(u13.getUserName(),u15.getUserName(),"Buna");
    Message m15(u14.getUserName(),u15.getUserName(),"Buna!");

    conversations.add(m1);
    conversations.add(m2);
    conversations.add(m3);
    conversations.add(m4);
    conversations.add(m5);
    conversations.add(m6);
    conversations.add(m7);
    conversations.add(m8);
    conversations.add(m9);
    conversations.add(m10);
    conversations.add(m11);
    conversations.add(m12);
    conversations.add(m13);
    conversations.add(m14);
    conversations.add(m15);
    conversations.add(m22);
    conversations.add(m111);


}

