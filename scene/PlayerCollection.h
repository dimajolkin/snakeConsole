//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_PLAYERCOLLECTION_H
#define SNAKE_PLAYERCOLLECTION_H
class PlayerCollection {

    SnakePlayer *p;
public:
    void add(SnakePlayer *player) {
        p =player;
    }


    template<class UnaryFunction>
    void foreach(UnaryFunction callback) {
        callback(p);
    }

    void draw() {
        p->draw();
    }
};
#endif //SNAKE_PLAYERCOLLECTION_H
