#ifndef DICTIONARY_H_REPOINMEMORY_H
#define DICTIONARY_H_REPOINMEMORY_H

#include "Dictionary.h"
#include "array.h"
#include "User.h"
#include "Message.h"
#include "Friendship.h"

class RepoInMemory {
private:
    Dictionary<string, User> users;
    Array<Friendship> friendships;
    Array<Message> conversations;

public:
    RepoInMemory();
    ~RepoInMemory();
    Dictionary<std::string, struct User> & getUsers();
    Array<struct Friendship> & getFriendships();
    Array<Message>& getConversations();

    void addUser(User& u);
    void updateUser(User& u1, User& u2);
    void deleteUser(User& u);

    void addFriendship(Friendship &f);
    void deleteFriendship(Friendship &f);

    void addMessage(Message &m);
    void updateMessage(Message &m1, Message &m2);
    void deleteMessage(Message &m);

    void startUpData();


};


#endif //DICTIONARY_H_REPOINMEMORY_H
