#include "include.h"
#include <thread>

using namespace std;

Driver *driver;
Scene *scene;

Player *p = new Player(1, 1, Color::RED);

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
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
        case '1':
            scene->addFoodInRandomPosition();
        default:
            NULL;
    }

    driver->refresh();
}


int main(int argc, char *argv[]) {
    scene = new Scene();
    scene->add(p);

    driver = Driver::getInstance();
    driver->setWindowSize(800, 800);
    driver->setTitle("Snake");
    driver->setPosition(50, 50);
    driver->setKeyboard(keyboard);
    driver->loop([]() {
        scene->refresh();
    });
    driver->run(argc, argv);

    return 0;
}
