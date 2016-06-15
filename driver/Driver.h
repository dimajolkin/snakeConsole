//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_DRIVER_H
#define SNAKE_DRIVER_H

#include <graphics.h>
#include <X11/Xlib.h>

class Driver {
private:
    int gd;
    int gm;



public:
    Driver() {
        std::cout << "init driver" << std::endl;
        gm = DETECT;
        XInitThreads();
        initgraph(&gd, &gm, NULL);
    }
    static Driver *getInstance() {
        static Driver * instance = new Driver;
        return instance;
    }

    int getMaxX() {
        return getmaxx();
    }

    int getMaxY() {
        return getmaxy();
    }

    ~Driver() {
        closegraph();
    }


    void run() {
//        bar(left + 300, top, right + 300, bottom);
//        line(left - 10, top + 150, left + 410, top + 150);
//        ellipse(x, y + 200, 0, 360, 100, 50);
    }

    void drawRectangle(int left, int top, int right, int bottom) {
        rectangle(left, top, right, bottom);
    }

    void drawCircle(int x, int y, int radius) {
        circle(x, y, radius);
    }

    void drawBar(int left, int top, int width, int height) {
        try {
            if (left > 0 && top > 0) {
                bar(left, top, left + width, top + height);
            }
        } catch(...) {

        }

    }
};


#endif //SNAKE_DRIVER_H
