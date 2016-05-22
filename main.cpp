#include "driver/Driver.h"
#include "scene/Map.h"
#include "scene/Color.h"
#include "scene/Scene.h"

#include "iostream"
#include "scene/SectorFactory.h"

class InputDriver {
    char simbol;
public:

    bool isRun() {
        return simbol != '0';
    }

    char getKey() {
        simbol = (char) getch();
        return simbol;
    }

};


using namespace std;

int main() {
    Scene *scene = new Scene();
    Player *p = new Player(3, 3, Color::BLUE);
    scene->add(p);
    scene->refresh();


    InputDriver *inputDriver = new InputDriver;
    while (inputDriver->isRun()) {
        switch (inputDriver->getKey()) {
            case 'w':
                p->top();
                break;
            case 's':
                p->bottom();
                break;
            case 'a':
                p->left();
                break;
            case 'd':
                p->right();
                break;
            default:
                NULL;
        }
        scene->refresh();
    }

    delay(500);
    return 0;
}