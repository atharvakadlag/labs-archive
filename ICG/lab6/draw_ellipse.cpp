#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include "ellipse.hpp"

using namespace std;
#define HEIGHT 720
#define WIDTH 720
#define PADDING 10

#define PI 3.14

int ry = 150;
int rx = 300;
int x_center = 720;
int y_center = 720;
float ang1 = 0;
float ang2 = PI / 3;
float r = 0.2;
float g = 0.2;
float b = 0.2;
ellipse E1 = MP_ELLIPSE(rx, ry, x_center, y_center);

float alpha = PI/6;
float beta = PI/4;

void draw_arc()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cout << atan2
	glColor3f(r, g, b);
    glPointSize(2);
	glBegin(GL_POINTS);
		for (auto i: E1) {
            if (alpha <= atan2(i.second, i.first) &&
                atan2(i.second, i.first) <= beta) {
                glVertex2d(i.first, i.second);}
		}
	glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH + PADDING, HEIGHT + PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
	gluOrtho2D(-PADDING, WIDTH * 2 + 2 * PADDING * 2, -PADDING, HEIGHT * 2 + 2 * PADDING);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_arc);
	glutMainLoop();

	return 0;
}
