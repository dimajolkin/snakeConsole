#include "include.h"
#include <thread>

using namespace std;

const unsigned int SPEED = 400; //ms

Driver *driver;
Scene *scene;

SnakePlayer *p = new SnakePlayer(1, 1, Color::RED);

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case InputDriver::KEY_TOP:
        case InputDriver::KEY_BOTTOM:
        case InputDriver::KEY_RIGHT:
        case InputDriver::KEY_LEFT:
            p->setKey(key);
            break;
        case '+':
            p->incLevel();
            break;
        case '1':
            scene->addFoodInRandomPosition();
        default:
            NULL;
    }
    driver->refresh();
}

void timer(int) {
    p->autoMove();
    //синхронизация множества сетевых змей
    driver->refresh();
    driver->setTimer(SPEED, timer);
}


int main(int argc, char *argv[]) {
    scene = new Scene();
    scene->add(p);

    driver = Driver::getInstance();
    driver->setWindowSize(800, 800);
    driver->setTitle("Snake");
    driver->setPosition(50, 50);
    driver->setKeyboard(keyboard);
    driver->loop([](){
        scene->refresh();
    });
    driver->setTimer(0, timer);
    driver->run(argc, argv);

    return 0;
}
