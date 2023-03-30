//
// Created by bienu on 5/20/2022.
//

#ifndef ARRAY_H_NETWORK_H
#define ARRAY_H_NETWORK_H

#include "array.h"
#include "Dictionary.h"
#include "User.h"
#include "Message.h"
#include "Friendship.h"
#include "RepoInMemory.h"
#include <string>
using namespace std;

class Network {
private:
    RepoInMemory &repo;

public:
    Network(RepoInMemory &repo);
    ~Network();

    Dictionary<string, User>& getUsers();
    Array<Friendship>& getFriendships();
    Array<Message>& getConversations();

    void addUser(const string& userN, const string& pass, const string& full);
    void updateUser(const string &userN1, const string &pass1, const string &full1,
                    const string &userN2, const string &pass2, const string &full2);
    void deleteUser(const string& userN, const string& pass, const string& full);
    User getUserByUsername(const string& userN);

    void addFriendship(const string& userN1, const string& userN2);
    void deleteFriendship(const string& userN1, const string& userN2);
    Array<User> userFriends(const string& userN);
    Array<User> commonFriends(const string& userN1, const string& userN2);

    void addMessage(const string& userN1, const string& userN2, const string& mess);
    void updateMessage(const string& userN1, const string& userN2, const string& mess, const string& mess2);
    void deleteMessage(const string& userN1, const string& userN2, const string& mess);
    Array<Message> getConversation(const string& userN1, const string& userN2);
    Dictionary<basic_string<char>, Array<Message>> getUserConversations(const string& userN);

    void waterfallDelete(User &u);
    void waterfallUpdate(User &u, User &uu);

};


#endif //ARRAY_H_NETWORK_H
