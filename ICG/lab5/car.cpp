#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#include <iostream>
#include "circle_draw.hpp"
#include "line_draw.hpp"

using namespace std;
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10

float car_x = WIDTH*8/9;

void draw_car(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0, 0, 0);
	// glBegin(GL_POLYGON);
   	// 	glVertex2i(car_x+0, WIDTH*1.0/7);
   	// 	glVertex2i(car_x+0, WIDTH*1.0/7 + HEIGHT*1.75/10);
   	// 	glVertex2i(car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10);
   	// 	glVertex2i(car_x+WIDTH, WIDTH*1.0/7);
	// glEnd();
	line l1;
	BLD(car_x+0, WIDTH*1.0/7, car_x+0, WIDTH*1.0/7 + HEIGHT*1.75/10, &l1);
	BLD(car_x+0, WIDTH*1.0/7 + HEIGHT*1.75/10, car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10, &l1);
	BLD(car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10, car_x+WIDTH, WIDTH*1.0/7, &l1);
	BLD(car_x+WIDTH, WIDTH*1.0/7, car_x+0, WIDTH*1.0/7, &l1);

	BLD(car_x+WIDTH*2.0/7, WIDTH*1.0/7 + HEIGHT*1.75/10, car_x+WIDTH*3.5/7, WIDTH*1.0/7 + HEIGHT*3/10, &l1);
	BLD(car_x+WIDTH*3.5/7, WIDTH*1.0/7 + HEIGHT*3/10, car_x+WIDTH*6/7, WIDTH*1.0/7 + HEIGHT*3/10, &l1);
	BLD(car_x+WIDTH*6/7, WIDTH*1.0/7 + HEIGHT*3/10, car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10, &l1);
	BLD(car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10, car_x+WIDTH*2.0/7, WIDTH*1.0/7 + HEIGHT*1.75/10, &l1);

	BLD(car_x+WIDTH*2.3/7, WIDTH*1.0/7 + HEIGHT*1.85/10, car_x+WIDTH*6.8/7, WIDTH*1.0/7 + HEIGHT*1.85/10, &l1);
	BLD(car_x+WIDTH*3.60/7, WIDTH*1.0/7 + HEIGHT*2.9/10, car_x+WIDTH*2.3/7, WIDTH*1.0/7 + HEIGHT*1.85/10, &l1);
	BLD(car_x+WIDTH*5.9/7, WIDTH*1.0/7 + HEIGHT*2.9/10, car_x+WIDTH*3.60/7, WIDTH*1.0/7 + HEIGHT*2.9/10, &l1);
	BLD(car_x+WIDTH*6.8/7, WIDTH*1.0/7 + HEIGHT*1.85/10, car_x+WIDTH*5.9/7, WIDTH*1.0/7 + HEIGHT*2.9/10, &l1);

	glPointSize(2);
	glBegin(GL_POINTS);
		for (auto i: l1) {
			glVertex2d(i.first, i.second);
		}
	glEnd();
	glFlush();
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON);

	glEnd();

	int radius 	= WIDTH*0.8/7;
	int centerx = car_x+WIDTH*2.0/7;
	int centery = WIDTH*1.0/7;
	circle wheel1 = MCD(centerx, centery, radius);
	// cout << centerx << ", " << centery << "\n";
	
	glPointSize(5);
	glColor3f(0.86,0.86,0.86);
	glBegin(GL_POINTS);
		glVertex2d(centerx, centery);

		for (auto i: wheel1) {
			glVertex2d(i.first, i.second);
		}
	glEnd();
	glFlush();

	radius 	= WIDTH*0.8/7;
	centerx = car_x+WIDTH*5.5/7;
	centery = WIDTH*1.0/7;
	circle wheel2 = MCD(centerx, centery, radius);
	// cout << centerx << ", " << centery << "\n";
	
	glPointSize(2);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2d(centerx, centery);

		for (auto i: wheel2) {
			glVertex2d(i.first, i.second);
		}
	glEnd();
	glFlush();
}

void move_car(unsigned char key, int x, int y) {
	switch(key) {
		case 32:
			car_x -= WIDTH/9;
			// cout << "hello\n";
			break;
	}

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	draw_car();
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH+PADDING, HEIGHT+PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
    gluOrtho2D(-PADDING, WIDTH*2+2*PADDING*2, -PADDING, HEIGHT*2+2*PADDING);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_car);
	glutKeyboardFunc(move_car);
	glutMainLoop();
	
	return 0;
}
