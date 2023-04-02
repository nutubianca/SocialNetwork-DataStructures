//
// Created by bienu on 5/3/2022.
//

#include "User.h"
#include <utility>
#include "iostream"


User::User() {
    this->userName = "";
    this->password = "";
    this->fullName = "";
}

User::User(const string &userNamee, const string &passwordd, const string &fullNamee) {
    this->userName = userNamee;
    this->password = passwordd;
    this->fullName = fullNamee;
}

User::User(const User &user) {
    this->userName = user.userName;
    this->password = user.password;
    this->fullName = user.fullName;
}

User::~User() {

}

bool User::operator==(const User &u) {
    return this->userName == u.userName;
}

string User::getUserName() {
    return this->userName;
}

string User::getFullName() {
    return this->fullName;
}

void User::setUserName(string userNamee) {
    this->userName = std::move(userNamee);
}

void User::setFullName(string fullNamee) {
    this->fullName = std::move(fullNamee);
}

std::ostream &operator<<(std::ostream &os, const User &u) {
    os << "Username: " << u.userName << std::endl;
    os << "Full Name: " << u.fullName << std::endl;
    return os;
}

string User::getPassword() {
    return this->password;
}


