//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SECTOR_H
#define SNAKE_SECTOR_H


#include "../driver/glut/Driver.h"
#include "Color.h"

class Sector {
protected:
    int color;
    Driver *driver;
    Point *point;
    float lenX, lenY;

public:

    static Sector *create(int x, int y, int color) {
        return new Sector(Driver::getInstance(), x, y, color);
    }

    static Sector *create(int x, int y) {
        return new Sector(Driver::getInstance(), x, y, Color::WHITE);
    }

    Sector() {

    }

    Sector(int x, int y) {
        point = new Point(x, y);
    }

    Sector(Driver *driver, int x, int y, int color) {
        this->color = color;
        this->driver = driver;
        point = new Point(x, y);
    }

    void setColor(int color) {
        this->color = color;
        this->draw();
    }

    Point * getPosition() {
        return point;
    }

    std::string toString() {
        return " position ";
    }

    int getColor() {
        return this->color;
    }

    void draw() {
        float d = 0.02;
        float width =  0.080;
        float height = 0.080;
        driver->setColor(color);
        driver->drawBar(
                (float) (-0.99 + width * point->getX() + d * point->getX()),
                (float) (0.9 - height * point->getY() - d * point->getY()),
                width,
                height,
                this->color
        );
    }


    virtual void left() {
        point->setX(point->getX() - 1);
    }

    virtual void right() {
        point->setX(point->getX() + 1);
    }

    virtual void top() {
        point->setY(point->getY() - 1);
    }

    virtual void bottom() {
        point->setY(point->getY() + 1);
    }

};
#endif //SNAKE_SECTOR_H
