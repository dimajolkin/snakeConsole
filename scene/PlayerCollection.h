//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_PLAYERCOLLECTION_H
#define SNAKE_PLAYERCOLLECTION_H
class PlayerCollection {

   std::vector<Player*> players;
public:
    void add(Player *player) {
        players.push_back(&(*player));
    }

    PlayerCollection() {
        players.reserve(1);
    }

    template<class UnaryFunction>
    void foreach(UnaryFunction callback) {

        for (std::vector<Player*>::iterator p = players.begin(); p != players.end(); ++p) {
            callback(*p);
        }

    }

    void draw() {
       foreach([](Player *player) {
           player->draw();
       });
    }

};
#endif //SNAKE_PLAYERCOLLECTION_H
