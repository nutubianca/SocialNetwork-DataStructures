//
// Created by bienu on 5/21/2022.
//

#ifndef ARRAY_H_MESSAGE_H
#define ARRAY_H_MESSAGE_H

#include "User.h"

class Message {
private:
    std::string sender;
    std::string receiver;
    std::string text;
public:
    Message();
    Message(string username1, string username2, string mess);
    ~Message();

    string & getSender();
    string & getReceiver();
    string & getText();

    Message &operator=(const Message &m);
    bool operator==(const Message &m);

    friend std::ostream &operator<<(std::ostream &os, const Message &m);
};


#endif //ARRAY_H_MESSAGE_H
