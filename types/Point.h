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
};

//bool operator==(const Point& p1, const Point& p2) {
//    return p1.getX() == p2.getX() && p1.getY() == p2.getY();
//}
#endif //SNAKE_POINT_H
