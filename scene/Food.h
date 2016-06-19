//
// Created by dima on 19.06.16.
//

#ifndef SNAKE_EACH_H
#define SNAKE_EACH_H
class Food: public Player {

protected:
    int color = Color::BLUE;
public:
    Food() {}

    Food(Point * point) {
        start = Sector::create(point->getX(), point->getY(), color);
    }


};
#endif //SNAKE_EACH_H
