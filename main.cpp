#include "include.h"
#include <thread>

using namespace std;

const unsigned int SPEED = 200; //ms

Driver *driver;
Scene *scene;


SnakePlayer *p = new SnakePlayer(1, 1, Color::RED);
Controller<SnakePlayer> controller1(p, 'w', 's', 'a', 'd');

Player *p2 = new Player(1, 5, Color::GREEN);
Controller<Player> controller2(p2, 't', 'g', 'f', 'h');

void keyboard(unsigned char key, int x, int y) {

    controller1.upKey(key);
    controller2.upKey(key);

    switch (key) {
        case '+':
            p->incLevel();
            break;
        case '1':
            scene->addFoodInRandomPosition();
        default:
            NULL;
    }
}

void timer(int) {
    controller1.move();
    controller2.move();
    //синхронизация множества сетевых змей
    driver->refresh();
    driver->setTimer(SPEED, timer);
}


int main(int argc, char *argv[]) {
    scene = new Scene();
    scene->addFoodInRandomPosition();
    scene->add(p);
    scene->add(p2);

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
