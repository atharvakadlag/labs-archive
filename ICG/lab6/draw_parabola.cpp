#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#include <iostream>
#include "parabola.hpp"

using namespace std;
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10

int x1_vertex 	= 720;
int y1_vertex 	= 100; 
int a 	= 5;
parabola P1 = MP_PARABOLA(720, 100, 5);
float mycolor[] = {1.0, 0.0, 0.0};

void draw_parabola() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glColor3f(mycolor[0], mycolor[1], mycolor[2]); // white
	glBegin(GL_LINES);
		glVertex2d(x1_vertex, 0);
		glVertex2d(x1_vertex, 1440);


		glVertex2d(0, y1_vertex);
		glVertex2d(1440, y1_vertex);
	glEnd();
	glPointSize(2);
	glBegin(GL_POINTS);
		// glVertex2d(720, 720);
		for (auto i: P1) {
			glVertex2d(i.first, i.second);
		}
	glEnd();

	glFlush();
}

void move_car(unsigned char key, int x, int y) {
	switch(key) {
		case 32:
			x1_vertex 	= int(100 + (rand() % static_cast<int>(1000 - 100 + 1)));
			y1_vertex 	= int(100 + (rand() % static_cast<int>(300 - 100 + 1)));
			a 	= int(50 + 	(rand() % static_cast<int>(100 - 50 + 1)));
			
			mycolor[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			mycolor[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			mycolor[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			P1 = MP_PARABOLA(x1_vertex, y1_vertex, a);
			// cout << "hello\n";
			break;
	}

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	draw_parabola();
}

void move_car_mouse(int button,int state,int x,int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON:
			x1_vertex	= 100 + (rand() % static_cast<int>(1000 - 100 + 1));
			y1_vertex 	= 100 + (rand() % static_cast<int>(300 - 100 + 1));
			a 	= 50 + 	(rand() % static_cast<int>(100 - 50 + 1));
			
			mycolor[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			mycolor[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			mycolor[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			P1 = MP_PARABOLA(x1_vertex, y1_vertex, a);
			break;
	}

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	draw_parabola();
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
	glutDisplayFunc(draw_parabola);
	glutKeyboardFunc(move_car);
	glutMouseFunc(move_car_mouse);
	glutMainLoop();
	
	return 0;
}
