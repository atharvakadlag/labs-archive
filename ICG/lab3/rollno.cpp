#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#define HEIGHT 720
#define WIDTH 720
#define PADDING 10
#define GLFW_KEY_SPACE   32

using namespace std;


float mycolor1[] = {241.0 / 255, 88.0 / 255, 93.0 / 255};
float mycolor5[] = {67.0/255, 192.0/255, 246.0/255};

void draw_ICG()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// DRAW 1
	glColor3f(mycolor1[0], mycolor1[1], mycolor1[2]); // red
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(120, 100);
		glVertex2i(120, 400);
		glVertex2i(100, 400);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(60, 100);
		glVertex2i(60, 80);
		glVertex2i(160, 80);
		glVertex2i(160, 100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(120, 420);
		glVertex2i(120, 380);
		glVertex2i(70, 340);
		glVertex2i(70, 380);
	glEnd();

	// 5
	glColor3f(mycolor5[0], mycolor5[1], mycolor5[2]); // red
	glBegin(GL_POLYGON);
		float radius 	= 100;
		float centerx 	= 280;
		float centery 	= 180;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		radius 	= 80;
		centerx 	= 280;
		centery 	= 180;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glBegin(GL_POLYGON); // hider
		glColor3f(1,1,1); // red
		glVertex2i(240, 270);
		glVertex2i(240, 120);
		glVertex2i(180, 120);
		glVertex2i(180, 270);
	glEnd();

	glColor3f(67.0/255, 192.0/255, 246.0/255); // blue
    glBegin(GL_POLYGON);
		glVertex2i(240, 420);
		glVertex2i(240, 250);
		glVertex2i(220, 250);
		glVertex2i(220, 420);
	glEnd();

    glBegin(GL_POLYGON);
		glVertex2i(240, 420);
		glVertex2i(240, 400);
		glVertex2i(360, 400);
		glVertex2i(360, 420);
	glEnd();

	glFlush();
}

void change_color(unsigned char key, int x, int y) {
	switch(key) {
		case GLFW_KEY_SPACE:
			mycolor1[0] = ((double) rand() / (RAND_MAX));
			mycolor1[1] = ((double) rand() / (RAND_MAX));
			mycolor1[2] = ((double) rand() / (RAND_MAX));
			mycolor5[0] = ((double) rand() / (RAND_MAX));
			mycolor5[1] = ((double) rand() / (RAND_MAX));
			mycolor5[2] = ((double) rand() / (RAND_MAX));
            cout << mycolor1[0] << "\n";
			break;
	}

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// DRAW 1
	glColor3f(mycolor1[0], mycolor1[1], mycolor1[2]); // red
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(120, 100);
		glVertex2i(120, 400);
		glVertex2i(100, 400);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(60, 100);
		glVertex2i(60, 80);
		glVertex2i(160, 80);
		glVertex2i(160, 100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(120, 420);
		glVertex2i(120, 380);
		glVertex2i(70, 340);
		glVertex2i(70, 380);
	glEnd();

	// 5
	glColor3f(mycolor5[0], mycolor5[1], mycolor5[2]); // red
	glBegin(GL_POLYGON);
		float radius 	= 100;
		float centerx 	= 280;
		float centery 	= 180;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		radius 	= 80;
		centerx 	= 280;
		centery 	= 180;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glBegin(GL_POLYGON); // hider
		glColor3f(1,1,1); // red
		glVertex2i(240, 270);
		glVertex2i(240, 120);
		glVertex2i(180, 120);
		glVertex2i(180, 270);
	glEnd();

	glColor3f(mycolor5[0], mycolor5[1], mycolor5[2]); // red
    glBegin(GL_POLYGON);
		glVertex2i(240, 420);
		glVertex2i(240, 250);
		glVertex2i(220, 250);
		glVertex2i(220, 420);
	glEnd();

    glBegin(GL_POLYGON);
		glVertex2i(240, 420);
		glVertex2i(240, 400);
		glVertex2i(360, 400);
		glVertex2i(360, 420);
	glEnd();

	glFlush();

	glFlush();
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
