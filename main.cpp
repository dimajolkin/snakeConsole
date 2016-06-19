#include "include.h"
#include <thread>

using namespace std;

Driver *driver;
Scene *scene;

InputDriver *inputDriver = new InputDriver;
Player *p;

void loop(int argc, char *argv[]) {

    driver->loop([]() {
        scene->refresh();
    });
    driver->run(argc, argv);
}


int main(int argc, char *argv[]) {
    driver = Driver::getInstance();
    driver->setWindowSize(800, 800);
    driver->setTitle("Snake");
    driver->setPosition(50, 50);

    p = new Player(3, 3, Color::RED);
    scene = new Scene();
    scene->add(p);

    std::thread render(loop, argc, argv);
    std::cout << "Start loop" ;

    while (inputDriver->isRun()) {
        std::cout << "-> loop \n" ;
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

    }

    std::cout << "Stop input commands" ;
    render.join();
    return 0;
}
