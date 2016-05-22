//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SECTORFACTORY_H
#define SNAKE_SECTORFACTORY_H


#include "Sector.h"
#include "Color.h"

Driver *driver = new Driver;

class SectorFactory {
private:
public:

    static Sector *create(int x, int y, int color) {
        return new Sector(driver, x, y, color);
    }

    static Sector *create(int x, int y) {
        return new Sector(driver, x, y, Color::WHITE);
    }
};

#endif //SNAKE_SECTORFACTORY_H
