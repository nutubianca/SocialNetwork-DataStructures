//
// Created by bienu on 5/20/2022.
//

#include <fstream>
#include "Network.h"


Network::Network(RepoInMemory &repo) : repo(repo) {
}

Network::~Network() = default;

Dictionary<string, User> &Network::getUsers() {
    return this->repo.getUsers();
}

Array<Friendship> &Network::getFriendships() {
    return this->repo.getFriendships();
}

Array<Message> &Network::getConversations() {
    return this->repo.getConversations();
}


void Network::addUser(const string &useerN, const string &paass, const string &fuull) {
    User us(useerN, paass, fuull);
    if (this->repo.getUsers().search(useerN).getUserName() != "")
        throw invalid_argument("Username-ul exista deja!");
    this->repo.addUser(us);
}

void Network::updateUser(const string &userN1, const string &pass1, const string &full1,
                         const string &userN2, const string &pass2, const string &full2) {
    User u1(userN1, pass1, full1);
    User u2(userN2, pass2, full2);
    if (this->repo.getUsers().search(userN2).getUserName() != "")
        throw invalid_argument("Username-ul exista deja!");
    waterfallUpdate(u1,u2);
    repo.updateUser(u1, u2);
}

void Network::deleteUser(const string &userN, const string &pass, const string &full) {
    User u(userN, pass, full);
    if (this->repo.getUsers().search(userN).getUserName() == "")
        throw invalid_argument("Utilizatorul nu exista!");
    waterfallDelete(u);
    repo.deleteUser(u);

}

void Network::addFriendship(const string &userN1, const string &userN2) {
    Friendship f(getUserByUsername(userN1), getUserByUsername(userN2));
    if (this->repo.getFriendships().exists(f))
        throw invalid_argument("Utilizatorii sunt deja prieteni!");
    if (this->repo.getUsers().search(userN1).getUserName() == "" ||
        this->repo.getUsers().search(userN2).getUserName() == "")
        throw invalid_argument("Username-uri invalide!");
    repo.addFriendship(f);
}

void Network::deleteFriendship(const string &userN1, const string &userN2) {
    Friendship f(getUserByUsername(userN1), getUserByUsername(userN2));
    if (!this->repo.getFriendships().exists(f))
        throw invalid_argument("Nu exista prietenia data!");
    this->repo.deleteFriendship(f);
}

Array<User> Network::userFriends(const string &userN) {
    Array<User> result;
    for (int i = 0; i < this->repo.getFriendships().size(); i++)
        if (getUserByUsername(userN) == repo.getFriendships().getElement(i).getFriend1())
            result.add(repo.getFriendships().getElement(i).getFriend2());
        else if (getUserByUsername(userN) == repo.getFriendships().getElement(i).getFriend2())
            result.add(repo.getFriendships().getElement(i).getFriend1());
    return result;
}

Array<User> Network::commonFriends(const string &userN1, const string &userN2) {
    Array<User> result;
    Array<User> friends1 = userFriends(userN1);
    Array<User> friends2 = userFriends(userN2);
    for (int i = 0; i < friends1.size(); i++)
        for (int j = 0; j < friends2.size(); j++)
            if (friends1.getElement(i) == friends2.getElement(j))
                result.add(friends1.getElement(i));
    return result;
}


void Network::addMessage(const string &userN1, const string &userN2, const string &mess) {
    Message m(userN1, userN2, mess);
    this->repo.addMessage(m);
}

void Network::updateMessage(const string &userN1, const string &userN2, const string &mess, const string &mess2) {
    Message oldOne(userN1, userN1, mess);
    Message newOne(userN1, userN1, mess2);
    if (!this->repo.getConversations().exists(oldOne))
        throw invalid_argument("Mesajul nu exista!");
    this->repo.updateMessage(oldOne, newOne);

}

void Network::deleteMessage(const string &userN1, const string &userN2, const string &mess) {
    Message m(userN1, userN2, mess);
    if (!this->repo.getConversations().exists(m))
        throw invalid_argument("Mesajul nu exista!");
    this->repo.deleteMessage(m);
}

Array<Message> Network::getConversation(const string &userN1, const string &userN2) {
    Array<Message> convo;
    for (int i = 0; i < this->repo.getConversations().size(); i++) {
        string s;
        string r;
        s = this->repo.getConversations().getElement(i).getSender();
        r = this->repo.getConversations().getElement(i).getReceiver();
        if ((s == userN1 && r == userN2) || (s == userN2 && r == userN1))
            convo.add(this->repo.getConversations().getElement(i));
    }
    return convo;
}

Dictionary<basic_string<char>, Array<Message>> Network::getUserConversations(const string &userN) {
    Dictionary<basic_string<char>, Array<Message>> result;
    for (int i = 0; i < repo.getConversations().size(); i++) {
        Message m = repo.getConversations().getElement(i);
        if (m.getSender() == userN && result.search(m.getReceiver()).size() == 0)
            result.add(m.getReceiver(), getConversation(userN, m.getReceiver()));
        else if (m.getReceiver() == userN && result.search(m.getSender()).size() == 0)
            result.add(m.getSender(), getConversation(userN, m.getSender()));
    }
    return result;
}


User Network::getUserByUsername(const string &userN) {
    return this->repo.getUsers().search(userN);
}

void Network::waterfallDelete(User &u) {
    Array<User> friends = userFriends(u.getUserName());
    Array<Message> texts;
    for (int i = 0; i < friends.size(); i++)
        deleteFriendship(u.getUserName(), friends.getElement(i).getUserName());
    for (int i = 0; i < this->repo.getConversations().size(); i++) {
        string s;
        string r;
        s = this->repo.getConversations().getElement(i).getSender();
        r = this->repo.getConversations().getElement(i).getReceiver();
        if (s == u.getUserName() || r == u.getUserName())
            texts.add(this->repo.getConversations().getElement(i));

    }
    for (int i = 0; i < texts.size(); i++)
        deleteMessage(texts.getElement(i).getSender(),
                      texts.getElement(i).getReceiver(),
                      texts.getElement(i).getText());
}

void Network::waterfallUpdate(User &u, User &newOne) {
    Array<User> friends = userFriends(u.getUserName());
    Array<Message> textsSent, textsReceived;
    for (int i = 0; i < friends.size(); i++) {
        Friendship f(newOne, friends.getElement(i));
        deleteFriendship(u.getUserName(), friends.getElement(i).getUserName());
        this->repo.addFriendship(f);
    }
    for (int i = 0; i < this->repo.getConversations().size(); i++) {
        string s;
        string r;
        s = this->repo.getConversations().getElement(i).getSender();
        r = this->repo.getConversations().getElement(i).getReceiver();
        if (s == u.getUserName())
            textsSent.add(this->repo.getConversations().getElement(i));
        else if (r == u.getUserName())
            textsReceived.add(this->repo.getConversations().getElement(i));

    }
    for (int i = 0; i < textsSent.size(); i++) {
        Message m(newOne.getUserName(),textsSent.getElement(i).getReceiver(),
                  textsSent.getElement(i).getText());
        Message old(u.getUserName(),textsSent.getElement(i).getReceiver(),
                    textsSent.getElement(i).getText());
        this->repo.updateMessage(old,m);

    }
    for (int i = 0; i < textsReceived.size(); i++)
    {
        Message m(textsReceived.getElement(i).getSender(),
                  newOne.getUserName(),
                  textsReceived.getElement(i).getText());
        Message old(textsReceived.getElement(i).getSender(),
                    u.getUserName(),
                    textsReceived.getElement(i).getText());
        this->repo.updateMessage(old,m);
    }
}

