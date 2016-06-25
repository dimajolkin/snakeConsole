//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SECTOR_H
#define SNAKE_SECTOR_H


#include "../driver/glut/Driver.h"
#include "Color.h"

class Sector {

    int x;
    int y;
    int color;
    Driver *driver;
    float lenX, lenY;
public:

    static Sector *create(int x, int y, int color) {
        return new Sector(Driver::getInstance(), x, y, color);
    }

    static Sector *create(int x, int y) {
        return new Sector(Driver::getInstance(), x, y, Color::WHITE);
    }

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

    Point * getPosition() {
        return  new Point(x, y);
    }

    std::string toString() {
        return " position ";
    }

    int getColor()
    {
        return this->color;
    }

    void draw()
    {
        float d = 0.02;
        float width =  0.080;
        float height = 0.080;
        driver->setColor(color);
        driver->drawBar(
                (float) (-0.99 + width * x + d * x),
                (float) (0.9 - height * y - d * y),
                width,
                height,
                this->color
        );
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
