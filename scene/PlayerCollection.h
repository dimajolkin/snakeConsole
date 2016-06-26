//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_PLAYERCOLLECTION_H
#define SNAKE_PLAYERCOLLECTION_H
class PlayerCollection : public Collection<Player>  {

public:
    PlayerCollection() {}

    void draw() {
       foreach([](Player *player) {
           player->draw();
       });
    }

};
#endif //SNAKE_PLAYERCOLLECTION_H
