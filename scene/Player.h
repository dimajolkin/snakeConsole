//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H


#include "Sector.h"

class Player {
    Sector *start;
public:

    Player() {

    }

    Player(int x, int y, int color) {
        start = Sector::create(x, y, color);
    }

    void draw() {
        start->draw();
    }

    virtual void left() {
        start->left();
    }

    virtual void right() {
        start->right();
    }

    virtual void top() {
        start->top();
    }

    virtual void bottom() {
        start->bottom();
    }


};


#endif //SNAKE_PLAYER_H
