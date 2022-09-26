#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#define HEIGHT 	1024
#define WIDTH	720
#define PADDING	10
#include <iostream>

using namespace std;

float mycolor[] = {1.0, 1.0, 1.0};

void draw_house(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

   	glBegin(GL_TRIANGLES);
		glColor3f(241.0/255, 88.0/255, 93.0/255); // red
		glVertex2i(PADDING, 			HEIGHT*6/9+PADDING);
		glVertex2i(PADDING+WIDTH*0.5, 	HEIGHT+PADDING);
		glVertex2i(PADDING+WIDTH, 		HEIGHT*6/9+PADDING);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(67.0/255, 192.0/255, 246.0/255); // blue
		glVertex2i(PADDING, 		PADDING);
		glVertex2i(PADDING+WIDTH, 	PADDING);
		glVertex2i(PADDING+WIDTH,	PADDING+HEIGHT*2/3-HEIGHT*0.005);
		glVertex2i(PADDING,			PADDING+HEIGHT*2/3-HEIGHT*0.005);
		cout << mycolor[0];
	glEnd();

	
	glFlush();
}

void change_color(unsigned char key, int x, int y) {
	switch(key) {
		case 32:
			mycolor[0] -= 0.1;
			mycolor[1] -= 0.1;
			mycolor[2] -= 0.1;
			cout << "hello\n";
			break;
	}

	glBegin(GL_QUADS);
	glColor3f(mycolor[0], mycolor[1], mycolor[2]); // white
	glVertex2i(PADDING+WIDTH*1/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*2/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*2/7, PADDING+HEIGHT*3/9);
	glVertex2i(PADDING+WIDTH*1/7, PADDING+HEIGHT*3/9);

	glColor3f(mycolor[0], mycolor[1], mycolor[2]); // white
	glVertex2i(PADDING+WIDTH*3/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*4/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*4/7, PADDING+HEIGHT*0/9+HEIGHT*0.005);
	glVertex2i(PADDING+WIDTH*3/7, PADDING+HEIGHT*0/9+HEIGHT*0.005);

	glColor3f(mycolor[0], mycolor[1], mycolor[2]); // white
	glVertex2i(PADDING+WIDTH*5/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*6/7, PADDING+HEIGHT*4/9);
	glVertex2i(PADDING+WIDTH*6/7, PADDING+HEIGHT*3/9);
	glVertex2i(PADDING+WIDTH*5/7, PADDING+HEIGHT*3/9);
	glEnd();

	glFlush();
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH+PADDING, HEIGHT+PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
    gluOrtho2D(0.0, WIDTH+2*PADDING, 0.0, HEIGHT+2*PADDING);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_house);
	glutKeyboardFunc(change_color);
	glutMainLoop();
	
	return 0;
}
