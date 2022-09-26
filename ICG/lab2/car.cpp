#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#include <iostream>

using namespace std;
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10

float car_x = WIDTH*8/9;

void draw_house(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		// glColor3f(67.0/255, 192.0/255, 246.0/255);
		glColor3f(0, 0, 0);
   		glVertex2i(WIDTH*8/9+0, WIDTH*1.0/7);
   		glVertex2i(WIDTH*8/9+0, WIDTH*1.0/7 + HEIGHT*1.75/10);
   		glVertex2i(WIDTH*8/9+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10);
   		glVertex2i(WIDTH*8/9+WIDTH, WIDTH*1.0/7);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(WIDTH*8/9+WIDTH*2.0/7, WIDTH*1.0/7 + HEIGHT*1.75/10);
		glVertex2i(WIDTH*8/9+WIDTH*3.5/7, WIDTH*1.0/7 + HEIGHT*3/10);
		glVertex2i(WIDTH*8/9+WIDTH*6/7, WIDTH*1.0/7 + HEIGHT*3/10);
		glVertex2i(WIDTH*8/9+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(WIDTH*8/9+WIDTH*2.3/7, WIDTH*1.0/7 + HEIGHT*1.85/10);
		glVertex2i(WIDTH*8/9+WIDTH*3.60/7, WIDTH*1.0/7 + HEIGHT*2.9/10);
		glVertex2i(WIDTH*8/9+WIDTH*5.9/7, WIDTH*1.0/7 + HEIGHT*2.9/10);
		glVertex2i(WIDTH*8/9+WIDTH*6.8/7, WIDTH*1.0/7 + HEIGHT*1.85/10);
	glEnd();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glColor3f(0.86,0.86,0.86);
		float radius 	= WIDTH*0.8/7;
		float centerx 	= WIDTH*8/9+WIDTH*2.0/7;
		float centery 	= WIDTH*1.0/7;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.86,0.86,0.86);
		radius 	= WIDTH*0.8/7;
		centerx = WIDTH*8/9+WIDTH*5.5/7;
		centery = WIDTH*1.0/7;
		int j = 50;
		for(int i=0;i<1000;++i) {
			glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
						 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glFlush();
}

void move_car(unsigned char key, int x, int y) {
	switch(key) {
		case 32:
			car_x -= WIDTH/9;
			cout << "hello\n";
			break;
	}

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		// glColor3f(67.0/255, 192.0/255, 246.0/255);
		glColor3f(0, 0, 0);
   		glVertex2i(car_x+0, WIDTH*1.0/7);
   		glVertex2i(car_x+0, WIDTH*1.0/7 + HEIGHT*1.75/10);
   		glVertex2i(car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10);
   		glVertex2i(car_x+WIDTH, WIDTH*1.0/7);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(car_x+WIDTH*2.0/7, WIDTH*1.0/7 + HEIGHT*1.75/10);
		glVertex2i(car_x+WIDTH*3.5/7, WIDTH*1.0/7 + HEIGHT*3/10);
		glVertex2i(car_x+WIDTH*6/7, WIDTH*1.0/7 + HEIGHT*3/10);
		glVertex2i(car_x+WIDTH, WIDTH*1.0/7 + HEIGHT*1.75/10);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(car_x+WIDTH*2.3/7, WIDTH*1.0/7 + HEIGHT*1.85/10);
		glVertex2i(car_x+WIDTH*3.60/7, WIDTH*1.0/7 + HEIGHT*2.9/10);
		glVertex2i(car_x+WIDTH*5.9/7, WIDTH*1.0/7 + HEIGHT*2.9/10);
		glVertex2i(car_x+WIDTH*6.8/7, WIDTH*1.0/7 + HEIGHT*1.85/10);
	glEnd();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glColor3f(0.86,0.86,0.86);
		float radius 	= WIDTH*0.8/7;
		float centerx 	= car_x+WIDTH*2.0/7;
		float centery 	= WIDTH*1.0/7;
		for(int i=0;i<1000;++i) {
		  glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
		  			 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.86,0.86,0.86);
		radius 	= WIDTH*0.8/7;
		centerx = car_x+WIDTH*5.5/7;
		centery = WIDTH*1.0/7;
		int j = 50;
		for(int i=0;i<1000;++i) {
			glVertex2f(centerx + radius*cos(2*3.14159*i/1000.0),
						 centery + radius*sin(2*3.14159*i/1000.0));
		}
	glEnd();
	glFlush();

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
	glutDisplayFunc(draw_house);
	glutKeyboardFunc(move_car);
	glutMainLoop();
	
	return 0;
}
