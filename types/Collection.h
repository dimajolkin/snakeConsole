//
// Created by dima on 26.06.16.
//

#ifndef SNAKE_COLLECTION_H
#define SNAKE_COLLECTION_H
template <class Entity>
class Collection {
protected:
    std::vector<Entity *> collection;
public:

    void add(Entity *object) {
        collection.push_back(&(*object));
    }


    template<class UnaryFunction>
    void foreach(UnaryFunction callback) {
        for (auto p = collection.begin(); p != collection.end(); ++p) {
            callback(*p);
        }
    }


};
#endif //SNAKE_COLLECTION_H
