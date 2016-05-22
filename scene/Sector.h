//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SECTOR_H
#define SNAKE_SECTOR_H


#include "../driver/Driver.h"

class Sector {

    int x;
    int y;
    int color;

    int lenX, lenY;
    Driver *driver;
public:

    Sector()
    {

    }

    Sector(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Sector(Driver *driver, int x, int y, int color) {
        this->x = x;
        this->y = y;
        this->color = color;
        this->driver = driver;
    }

    void setColor(int color)
    {
        this->color = color;
        this->draw();
    }

    void draw()
    {
        lenX = 50;
        lenY = 50;
        setcolor(color);
        driver->drawBar(lenX * x + 10 * (x - 1), lenX * y + 10 * (y - 1), lenX, lenX);
    }


    virtual void left() {
        x--;
    }

    virtual void right() {
        x++;
    }

    virtual void top() {
        y--;
    }

    virtual void bottom() {
        y++;
    }



};
#endif //SNAKE_SECTOR_H
