//
// Created by dima on 19.06.16.
//

#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H

class Point {
protected:
    int x;
    int y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    bool compare(Point *point) {
        return  this->getX() == point->getX() && this->getY() == point->getY();
    }
};

#endif //SNAKE_POINT_H
