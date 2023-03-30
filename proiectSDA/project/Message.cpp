//
// Created by bienu on 5/21/2022.
//

#include "Message.h"
#include <iostream>

#include <utility>

Message::Message() {
    this->sender="";
    this->receiver="";
    this->text="";
}

Message::Message(string username1, string username2, string mess)
        : sender(username1),
          receiver(username2),
          text(mess) {}

Message::~Message() {

}

string &Message::getSender()  {
    return this->sender;
}

string &Message::getReceiver() {
    return this->receiver;
}

string &Message::getText() {
    return this->text;
}

Message &Message::operator=(const Message &m) {
    this->sender=m.sender;
    this->receiver=m.receiver;
    this->text=m.text;
    return *this;
}

bool Message::operator==(const Message &m) {
    return (this->sender==m.sender&&this->receiver==m.receiver&&this->text==m.text);
}

std::ostream &operator<<(std::ostream &os, const Message &m) {
    os << m.sender<<": "<<m.text<<std::endl;
    return os;
}
