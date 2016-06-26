//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_PLAYERCOLLECTION_H
#define SNAKE_PLAYERCOLLECTION_H
class PlayerCollection {

   std::vector<SnakePlayer*> players;
public:
    void add(SnakePlayer *player) {
        players.push_back(&(*player));
    }

    PlayerCollection() {
        players.reserve(1);
    }

    template<class UnaryFunction>
    void foreach(UnaryFunction callback) {

        for (std::vector<SnakePlayer*>::iterator p = players.begin(); p != players.end(); ++p) {
            callback(*p);
        }

    }

    void draw() {
       foreach([](SnakePlayer *player) {
           player->draw();
       });
    }

};
#endif //SNAKE_PLAYERCOLLECTION_H
