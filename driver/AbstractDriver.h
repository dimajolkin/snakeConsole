//
// Created by dima on 15.06.16.
//

#ifndef SNAKE_ABSTRACTDRIVER_H
#define SNAKE_ABSTRACTDRIVER_H
class AbstractDriver {
public:
    AbstractDriver() {}
    virtual void drawBar(float left, float top, float width, float height, int color) = 0;
    virtual void setColor(int color) = 0;

};
#endif //SNAKE_ABSTRACTDRIVER_H
