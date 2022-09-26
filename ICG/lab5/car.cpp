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

	int radius 	= 360;
	int centerx = 720;
	int centery = 720;
	circle wheel1 = MCD(centerx, centery, radius);
	cout << wheel1.size() << "\n";
	int alpha = 90;
	int beta = 180;

	// int alpha_idx = alpha * wheel1.size() / 360;
	// int beta_idx = beta * wheel1.size() / 360;

	int alpha_idx = 0;
	int beta_idx = 100;

	glPointSize(5);
	glColor3f(0.0, 1.00, 0.0);
	glBegin(GL_POINTS);
		// for (int i = alpha_idx; i < beta_idx; i++) {
		// 	glVertex2d(wheel1[i].first, wheel1[i].second);
		// }
		for (auto i: wheel1) {
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
