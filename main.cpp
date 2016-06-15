#include "include.h"
using namespace std;

Driver *driver;
Scene  *scene;

int main(int argc, char* argv[]) {
    driver = Driver::getInstance();
    driver->setWindowSize(500,500);
    driver->setTitle("Snake");
    driver->setPosition(50, 50);

    scene =  new Scene();

    driver->loop([](){
        driver->drawLine(0,0,1,1);

    });

//    Player *p = new Player(3, 3, Color::BLUE);
//    scene->add(p);


//    InputDriver *inputDriver = new InputDriver();
//    while (inputDriver->isRun()) {
//        switch (inputDriver->getKey()) {
//            case 'w':
//                p->top();
//                break;
//            case 's':
//                p->bottom();
//                break;
//            case 'a':
//                p->left();
//                break;
//            case 'd':
//                p->right();
//                break;
//            default:
//                NULL;
//        }
//        scene->refresh();
//        p->draw();
//    }

    driver->run(argc, argv);
    return 0;
}
