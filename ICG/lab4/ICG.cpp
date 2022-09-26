#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#define HEIGHT 720
#define WIDTH 720
#define PADDING 10
#define GLFW_KEY_SPACE   32

using namespace std;

float mycolorI[] = {1.0, 0.0, 1.0};
float mycolorC[] = {0.0, 1.0, 1.0};
float mycolorG[] = {0.0, 0.0, 1.0};

void draw_ICG()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// DRAW I
	glColor3f(mycolorI[0], mycolorI[1], mycolorI[2]); // red
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(120, 100);
		glVertex2i(120, 400);
		glVertex2i(100, 400);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(30, 100);
		glVertex2i(30, 80);
		glVertex2i(190, 80);
		glVertex2i(190, 100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(30, 400);
		glVertex2i(30, 420);
		glVertex2i(190, 420);
		glVertex2i(190, 400);
	glEnd();

	// C
	glColor3f(mycolorC[0], mycolorC[1], mycolorC[2]); // red
	glBegin(GL_POLYGON);
		float radius 	= 180;
		float centerx 	= 320;
		float centery 	= 250;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		radius 	= 160;
		centerx 	= 320;
		centery 	= 250;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,1,1); // red
		glVertex2i(380, 450);
		glVertex2i(380, 70);
		glVertex2i(500, 70);
		glVertex2i(500, 450);
	glEnd();

	// G
	glColor3f(mycolorG[0], mycolorG[1], mycolorG[2]); // red
	glBegin(GL_POLYGON);
		radius 	= 180;
		centerx 	= 570;
		centery 	= 250;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		radius 	= 160;
		centerx 	= 570;
		centery 	= 250;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,1,1); // red
		glVertex2i(680, 450);
		glVertex2i(680, 70);
		glVertex2i(750, 70);
		glVertex2i(750, 450);
	glEnd();

	glColor3f(mycolorG[0], mycolorG[1], mycolorG[2]); // red
	glBegin(GL_POLYGON);
		glVertex2i(680, 250);
		glVertex2i(680, 70);
		glVertex2i(700, 70);
		glVertex2i(700, 250);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(630, 250);
		glVertex2i(630, 270);
		glVertex2i(720, 270);
		glVertex2i(720, 250);
	glEnd();

	glFlush();
}

void change_color(unsigned char key, int x, int y) {
	switch(key) {
		case GLFW_KEY_SPACE:
			mycolorI[0] = ((double) rand() / (RAND_MAX));
			mycolorI[1] = ((double) rand() / (RAND_MAX));
			mycolorI[2] = ((double) rand() / (RAND_MAX));
			mycolorC[0] = ((double) rand() / (RAND_MAX));
			mycolorC[1] = ((double) rand() / (RAND_MAX));
			mycolorC[2] = ((double) rand() / (RAND_MAX));
			mycolorG[0] = ((double) rand() / (RAND_MAX));
			mycolorG[1] = ((double) rand() / (RAND_MAX));
			mycolorG[2] = ((double) rand() / (RAND_MAX));
			break;
	}

	draw_ICG();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH + PADDING, HEIGHT + PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
	gluOrtho2D(0.0, WIDTH + 2 * PADDING, 0.0, HEIGHT + 2 * PADDING);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_ICG);
	glutKeyboardFunc(change_color);
	glutMainLoop();

	return 0;
}
