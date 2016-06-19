//
// Created by dima on 15.06.16.
//

#ifndef SNAKE_GLUTDRIVER_H
#define SNAKE_GLUTDRIVER_H

#include <GL/glut.h>

class Driver: public  AbstractDriver {
protected:

    int width = 500;
    int height = 500;
    int x = 50;
    int y = 50;
    const char *title = "Driver Glut";
    void (* callback)( void );

    static void draw(void)
    {
        Driver::getInstance()->beginFrame();
        if (Driver::getInstance()->callback != NULL) {
            Driver::getInstance()->callback();
        }
        Driver::getInstance()->endFrame();
    }

    void beginFrame()
    {
        // Black background
        glClearColor(0.0f,0.0f,0.0f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void endFrame()
    {
        //        glFlush();
        glutSwapBuffers();
    }

public:


    static Driver *getInstance() {
        static Driver * instance = new Driver;
        return instance;
    }

    Driver() {
    }


    void loop(void (* callback)( void ))
    {
       this->callback = callback;
    }

    void setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void setTitle(const char *title )
    {
        this->title = title;
    }

    void setWindowSize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    void drawLine(float x1, float y1, float x2, float y2)
    {
        glLineWidth(2.5);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0);
        glEnd();
    }

    void drawBar(float left, float top, float width, float height, int color)
    {
        drawRectangle(left, top, width, height, color);
    }

    void drawRectangle(float left, float top, float width, float height, int color)
    {
        this->setColor(color);
        glRectf(left,top, left + width,  top + height);
        glEnd();
    }

    void setColor(int color)
    {
        switch (color) {
            case Color::RED:
                glColor3f(1, 0 , 0);
                break;
            case Color::GREEN:
                glColor3f(0.0f, 1.0f, 0.0f);
                break;
            case Color::BLUE:
                glColor3f(0, 0, 1);
                break;
            case Color::BLACK:
                glColor3f(0, 0, 0);
                break;
            case Color::WHITE:
                glColor3f(1, 1, 1);
                break;

        }
    }

    void run(int argc, char **argv)
    {
        glutInit(&argc, argv);

        /*Setting up  The Display
        /    -RGB color model + Alpha Channel = GLUT_RGBA
        */
        glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

        //Configure Window Postion
        glutInitWindowPosition(this->x, this->y);

        //Configure Window Size
        glutInitWindowSize(this->width,this->height);

        //Create Window
        glutCreateWindow(this->title);

        glutDisplayFunc(draw);

        // Loop require by OpenGL
        glutMainLoop();
    }
};
#endif //SNAKE_GLUTDRIVER_H
