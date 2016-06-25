//
// Created by dima on 25.06.16.
//

#ifndef SNAKE_FOODCOLLECTION_H
#define SNAKE_FOODCOLLECTION_H

class FoodCollection {
protected:
    std::vector<Food> foods;
public:
    FoodCollection() {}

    void draw() {
        for (std::vector<Food>::iterator food = foods.begin(); food != foods.end(); ++food) {
            (*food).draw();
        }
    }

    void add(Food * food) {
        foods.push_back(*food);
    }

    bool isEat(Point *point) {

        for (std::vector<Food>::iterator food = foods.begin(); food != foods.end(); ++food) {

            if (point->compare(food->getPosition())) {
                foods.erase(food);
                return true;
            }
        }

        return false;
    }
};
#endif //SNAKE_FOODCOLLECTION_H
