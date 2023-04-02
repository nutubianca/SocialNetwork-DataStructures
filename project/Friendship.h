//
// Created by bienu on 5/22/2022.
//

#ifndef ARRAY_H_FRIENDSHIP_H
#define ARRAY_H_FRIENDSHIP_H

#include "User.h"

class Friendship {
private:
    User user1;
    User user2;
public:
    Friendship();
    Friendship(User u1, User u2);
    ~Friendship();

    User& getFriend1();
    User& getFriend2();

    Friendship &operator=(const Friendship &f);
    bool operator==(const Friendship &f);

};


#endif //ARRAY_H_FRIENDSHIP_H
