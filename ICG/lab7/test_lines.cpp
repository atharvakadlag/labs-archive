#include <GL/freeglut.h> 
#include <bits/stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#include <iostream>
#include "clipping.hpp"

using namespace std;
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10

int randint(int min, int max) {
    return rand()%(max-min + 1) + min;
}

void draw_car(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int x_min = 360;
	int x_max = 1080;
	int y_min = 360;
	int y_max = 1080;

	ClippingWindow clip = ClippingWindow(x_min, y_min, x_max, y_max);

	glColor3f(0.5, 0.5, 0.5);
	glRectd(x_min, y_min, x_max, y_max);
    glBegin(GL_LINES);
	for (int i = 0; i < 10; i++) {
		Point start = Point(randint(0, 1440), randint(0, 1440));
		Point end = Point(randint(0, 1440), randint(0, 1440));
    	glColor3f(1.0, 0.0, 0.0);
        glVertex2d(start.x, start.y);
        glVertex2d(end.x, end.y);

        Line l = Line(start, end);
        bool accepted = l.cohen_clip(clip);
        if (accepted) {
            glColor3f(0.0, 1.0, 0.0);
            glVertex2d(l.start.x, l.start.y);
            glVertex2d(l.end.x, l.end.y);
        }
	}
    glEnd();
	glFlush();
}

int main(int argc,char** argv) {
	srand(time(0));
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH+PADDING, HEIGHT+PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
    gluOrtho2D(-PADDING, WIDTH*2+2*PADDING*2, -PADDING, HEIGHT*2+2*PADDING);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_car);
	glutMainLoop();
	
	return 0;
}
