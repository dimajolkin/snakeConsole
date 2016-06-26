//
// Created by dima on 25.06.16.
//

#ifndef SNAKE_FOODCOLLECTION_H
#define SNAKE_FOODCOLLECTION_H

class FoodCollection : public Collection<Food> {
public:
    FoodCollection() {}

    void draw() {
        foreach([](Food * food){
            food->draw();
        });
    }

    bool isEat(Point *point) {

        for (auto food = collection.begin(); food != collection.end(); ++food) {
            if (point->compare((*food)->getPosition())) {
                collection.erase(food);
                return true;
            }
        }

        return false;
    }
};
#endif //SNAKE_FOODCOLLECTION_H
