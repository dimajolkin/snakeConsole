//
// Created by dima on 22.05.16.
//

#ifndef SNAKE_SCENE_H
#define SNAKE_SCENE_H


#include <vector>
#include <iostream>
#include "../driver/glut/Driver.h"
#include "Map.h"
#include "Player.h"
#include "Food.h"

class Scene {
    Map *map;
    std::vector<Player> players;
    std::vector<Food> foods;

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

    void add(Food * food) {
        foods.push_back(*food);
    }

    void addFoodInRandomPosition() {
        Point *p = map->getFeeRandomPoint();
        Food * f = new Food(p);
        add(f);
    }

    void refresh() {
        map->refresh();

        for (std::vector<Player>::iterator player = players.begin(); player != players.end(); ++player) {

            for (std::vector<Food>::iterator food = foods.begin(); food != foods.end(); ++food) {
//                if ((*player).getPosition() == (*food).getPosition()) {
//                    (*player).incLevel();
//                    std::cout << "inc level" << std::endl;
//                }
            }

            (*player).draw();

        }

        for (std::vector<Food>::iterator food = foods.begin(); food != foods.end(); ++food) {
            (*food).draw();
        }
    }

};


#endif //SNAKE_SCENE_H
