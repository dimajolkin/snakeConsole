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
    PlayerCollection players;

    FoodCollection foods;

    SnakePlayer *p;

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

    void add(SnakePlayer *player) {
        players.add(player);
//       p = player;
    }

    void add(Food *food) {
        foods.add(food);
    }

    void addFoodInRandomPosition() {
        Point *p = map->getFeeRandomPoint();
        Food *f = new Food(p);
        add(f);
    }

    void refresh() {
        map->refresh();

        players.foreach([&](SnakePlayer *player) {
            if (foods.isEat(player->getPosition())) {
                (*player).incLevel();
                std::cout << "inc level" << std::endl;
            }

        });

        players.draw();
//        for (std::vector<SnakePlayer>::iterator player = players.begin(); player != players.end(); ++player) {


//            player->draw();
//        }


//        p->draw();


        foods.draw();

    }

};


#endif //SNAKE_SCENE_H
