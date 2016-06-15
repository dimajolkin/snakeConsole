//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "../driver/Driver.h"
#include "Sector.h"
#include "SectorTypeEnum.h"

class Map {
    int _width;
    int _height;

    Sector map[100][100];

public:

    Map(int width, int height) {
        _width = width;
        _height = height;

        int lenX = 5;//driver->getMaxX() / _width - 1;
        int lenY = 5;//driver->getMaxY() / _height;
        int kef = 2;

        for (int i = 0; i <= _width; ++i) {
            for (int j = 0; j <= _height; ++j) {
                Sector *sector = Sector::create(i, j);
                sector->draw();
                this->set(i, j, sector);
            }
        }
    }

    int getMaxX() {
        return _width;
    }

    int getMaxY() {
        return _height;
    }


    Sector *get(int x, int y) {
        return &map[x][y];
    }

    void set(int x, int y, Sector *sector) {
        map[x][y] = *sector;
    }

    void refresh() {
//        cleardevice();
        for (int i = 0; i <= _width; ++i) {
            for (int j = 0; j <= _height; ++j) {
                get(i,j)->draw();
            }
        }
    }

};


#endif //SNAKE_MAP_H
