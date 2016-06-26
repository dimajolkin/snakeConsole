//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

template <class Player>
class Controller {
protected:
    char key_top = 'w';
    char key_bottom = 's';
    char key_left = 'a';
    char key_right = 'd';

    char up_key = 'd';
    Player *player;
public:
    /**
     * keys [
     *     0 => TOP,
     *     1 => BOTTOM
     *     2 => LEFT
     *     3 => RIGHT
     * ]
     */
    Controller(Player *p, char top, char bottom, char left, char right) {
        player = p;
        key_top = top;
        key_bottom = bottom;
        key_left = left;
        key_right = right;
    }

    void upKey(char key) {
        if (key == key_top || key == key_bottom || key == key_left || key == key_right) {
            this->up_key = key;
        }
    }


    void move() {
        if (up_key == this->key_top) {
           player->top();
        } else if (up_key == key_bottom) {
            player->bottom();
        } else if (up_key == key_left) {
            player->left();
        } else if (up_key == key_right) {
            player->right();
        }

    }
};

#endif //SNAKE_CONTROLLER_H
