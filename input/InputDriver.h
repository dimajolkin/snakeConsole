//
// Created by dima on 16.06.16.
//

#ifndef SNAKE_INPUTDRIVER_H
#define SNAKE_INPUTDRIVER_H
class InputDriver {
    char simbol;
public:
    static const int KEY_TOP = 'w';
    static const int KEY_BOTTOM = 's';
    static const int KEY_LEFT = 'a';
    static const int KEY_RIGHT = 'd';

    bool isRun() {
        return simbol != '0';
    }

    char getKey() {
        simbol = (char) getchar();
//        std::cin >> simbol;
        return simbol;
    }

};

#endif //SNAKE_INPUTDRIVER_H
