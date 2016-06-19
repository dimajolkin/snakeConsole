//
// Created by dima on 16.06.16.
//

#ifndef SNAKE_INPUTDRIVER_H
#define SNAKE_INPUTDRIVER_H
class InputDriver {
    char simbol;
public:

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
