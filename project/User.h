//
// Created by bienu on 5/3/2022.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include "array.h"
#include <string>
using namespace std;

class User {
private:
    string userName;
    string password;
    string fullName;
public:
    User();
    User(const string& userNamee, const string& passwordd, const string& fullNamee);
    User(const User &user);
    ~User();
    bool operator==(const User& u);
    string getUserName();
    string getPassword();
    string getFullName();
    void setUserName(string userNamee);
    void setFullName(string fullNamee);
    friend std::ostream& operator<<(std::ostream& os, const User& u);
};


#endif //PROJECT_USER_H
