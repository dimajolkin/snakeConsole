//
// Created by dima on 13.06.16.
//

#ifndef SNAKE_SNAKEPLAYER_H
#define SNAKE_SNAKEPLAYER_H
class SnakePlayer : public Player {
    std::vector<Sector> sectors;

public:
    virtual void left() {
        start->left();
    }

    virtual void right() {
        start->right();
    }

    virtual void top() {
        start->top();
    }

    virtual void bottom() {
        start->bottom();
    }
};

#endif //SNAKE_SNAKEPLAYER_H
