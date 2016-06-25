//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H


#include "Sector.h"

class Player {
protected:
    int level = 0;
    bool life = true;

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

    bool isLife() {
        return  life;
    }

    void die() {
        life = false;
    }

    Point * getPosition() {
        return  start->getPosition();
    }

    void incLevel() {
        level++;
    }

    void clearLevels() {
        level = 0;
    }

    void recover() {
        life = true;
    }

    void decLevel() {
        level--;
    }

    virtual void move(char key) {
        switch (key) {
            case InputDriver::KEY_TOP:
                this->top();
                break;
            case InputDriver::KEY_BOTTOM:
                this->bottom();
                break;
            case InputDriver::KEY_LEFT:
                this->left();
                break;
            case InputDriver::KEY_RIGHT:
                this->right();
                break;
        }
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
