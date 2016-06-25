//
// Created by dima on 13.06.16.
//

#ifndef SNAKE_SNAKEPLAYER_H
#define SNAKE_SNAKEPLAYER_H
class SnakePlayer : public Player {
protected:
    std::vector<Sector> sectors;
    Sector *last;
    void saveLastSector() {
        last = Sector::create(
                start->getPosition()->getX() ,
                start->getPosition()->getY(),
                Color::RED
        );
        sectors.push_back(*last);

        while (sectors.size() > level) {
            sectors.erase(sectors.begin());
        }
    }

public:
    int count;
    SnakePlayer(int x, int y, int color) {
        sectors.reserve(100);
        start = Sector::create(x, y, color);
    }

    void left() {
        saveLastSector();
        start->left();

    }

    void right() {
        saveLastSector();
        start->right();

    }

    void top() {
        saveLastSector();
        start->top();

    }

    void bottom() {
        saveLastSector();
        start->bottom();

    }

    virtual void draw() {
        for (std::vector<Sector>::iterator sector = sectors.begin(); sector != sectors.end(); ++sector) {
            (*sector).draw();
        }
        start->draw();
    }

};

#endif //SNAKE_SNAKEPLAYER_H
