#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include "parabola.hpp"

using namespace std;
#define HEIGHT 720
#define WIDTH 720
#define PADDING 10

#define PI 3.14

int rx = 300;
int ry = 100;
int x_center = 720;
int y_center = 720;
float ang1 = 0;
float ang2 = PI / 3;
float r = 0.2;
float g = 0.2;
float b = 0.2;

void show_point(GLint x, GLint y)
{
	glPointSize(2);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void draw_arc()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex2d(x_center, 0);
	glVertex2d(x_center, 1440);

	glVertex2d(0, y_center);
	glVertex2d(1440, y_center);
	glEnd();
	float x = 0;
	float y = ry;
	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
	float dx = 2 * (ry * ry) * x;
	float dy = 2 * (rx * rx) * y;
	while (dx < dy)
	{

		if ((x > (int)rx * cos(ang1 + ang2) &&
			 x < (int)rx * cos(ang1) &&
			 y > (int)ry * sin(ang1) &&
			 y < (int)ry * sin(ang1 + ang2)))
		{
			show_point(x_center + x, y_center + y);
		}

		if (p1 < 0)
		{
			x = x + 1;
			dx = 2 * (ry * ry) * x;
			p1 = p1 + dx + (ry * ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p1 = p1 + dx - dy + (ry * ry);
		}
	}

	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);

	while (y > 0)
	{

		if ((x > (int)rx * cos(ang1 + ang2) &&
			 x < (int)rx * cos(ang1) &&
			 y > (int)ry * sin(ang1) &&
			 y < (int)ry * sin(ang1 + ang2)))
		{
			show_point(x_center + x, y_center + y);
		}

		if (p2 > 0)
		{
			x = x;
			y = y - 1;
			dy = 2 * (rx * rx) * y;
			p2 = p2 - dy + (rx * rx);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			p2 = p2 + dx -
				 dy + (rx * rx);
		}
	}

	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		int random1 = (1 + rand() % 5);
		int random2 = (5 + rand() % 10);

		ang1 = PI / random1;
		ang2 = PI / random2;

		r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		break;
	}

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	draw_arc();
}

void move_arc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 32:
		int random1 = (0 + rand() % 6);
		int random2 = (6 + rand() % 12);

		ang1 = PI / random1;
		ang2 = PI / random2;

		r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		break;
	}

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	draw_arc();
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(move_arc);
	glutMainLoop();

	return 0;
}
