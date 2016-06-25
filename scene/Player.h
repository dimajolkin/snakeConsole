//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H


#include "Sector.h"

class Player {
protected:
    int level = 1;

    Sector *start;
public:

    Player() {

    }

    Player(int x, int y, int color) {
        start = Sector::create(x, y, color);
    }

    Player(Point * point, int color) {
        start = Sector::create(point->getX(), point->getY(), color);
    }

    Point * getPosition() {
        return  start->getPosition();
    }
    void incLevel() {
        level++;
    }

    void decLevel() {
        level--;
    }

    bool isLife() {
        return level > 0;
    }

    virtual void draw() {
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
