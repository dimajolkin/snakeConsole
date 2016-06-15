//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SCENE_H
#define SNAKE_SCENE_H


#include <vector>
#include <iostream>
#include "../driver/Driver.h"
#include "Map.h"
#include "Player.h"

class Scene {
    Map *map;
    std::vector<Player> players;

    void init() {
        map = new Map(20, 20);
        map->refresh();
    }

public:

    Scene() {
        this->init();
    }

    Map *getMap() {
        return map;
    }

    void add(Player *player) {
        players.push_back(*player);
    }

    void refresh() {
        map->refresh();
        for (std::vector<Player>::iterator player = players.begin(); player != players.end(); ++player) {
            (*player).draw();
        }
    }

};


#endif //SNAKE_SCENE_H
