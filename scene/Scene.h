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

    void add(Player *player) {
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

        //проверка всех игроков
        players.foreach([&](Player *player) {

            //не вышли ли за пределы и не врезались ли в стену
            if (!map->isValid(player->getPosition())) {
                map->moveInOppositeSide(player->getPosition());
            }


            //может еду съели?
            if (foods.isEat(player->getPosition())) {
                player->incLevel();
                addFoodInRandomPosition();
            }

            //мы ещё живы?
            if (!player->isLife()) {
                std::cout << "Player die \n";
                player->clearLevels();
                player->recover();
            }

        });

        players.draw();
        foods.draw();
    }

};


#endif //SNAKE_SCENE_H
