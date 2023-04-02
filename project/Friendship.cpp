//
// Created by bienu on 5/22/2022.
//

#include "Friendship.h"

Friendship::Friendship() {

}

Friendship::Friendship(User u1, User u2) {
    this->user1=u1;
    this->user2=u2;

}

Friendship::~Friendship() = default;

User& Friendship::getFriend1() {
    return this->user1;
}

User& Friendship::getFriend2() {
    return this->user2;
}

bool Friendship::operator==(const Friendship &f) {
    return ((this->user1==f.user1&&this->user2==f.user2)||(this->user1==f.user2&&this->user2==f.user1));
}

Friendship &Friendship::operator=(const Friendship &f) {
    this->user1=f.user1;
    this->user2=f.user2;
    return *this;
}
