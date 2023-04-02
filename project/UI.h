//
// Created by bienu on 5/21/2022.
//

#ifndef ARRAY_H_UI_H
#define ARRAY_H_UI_H
#include "Network.h"

class UI {
private:
    Network& network;

    void uiShowMenu();
    void uiShowMenuUsers();
    void uiShowMenuFriendships();
    void uiShowMenuMessages();

    void uiAddUser();
    void uiUpdateUser();
    void uiDeleteUser();
    void uiAllUser();
    void uiOneUser();

    void uiAddFriendship();
    void uiDeleteFriendship();
    void uiUserFriendships();
    void uiCommonFriends();

    void uiSendMessage();
    void uiUpdateMessage();
    void uiDeleteMessage();
    void uiConversation();
    void uiUserConversations();

public:
    UI(Network &network);
    ~UI();
    void menu();
    void usersMenu();
    void friendshipMenu();
    void messageMenu();

};


#endif //ARRAY_H_UI_H
