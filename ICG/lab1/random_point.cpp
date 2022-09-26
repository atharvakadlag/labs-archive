#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#define PI 3.141
#define radius 10


int x, y;
float r,g,b;
int num_triangles=5;

int num_dots = num_triangles*3;

void magic_dots(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(1,0,0); 	

      	glBegin(GL_POLYGON);          // Each set of 3 vertices form a triangle
      		glColor3f(1.0f, 0.0f, 1.0f); // Blue
      	
		glVertex2f(-0.5f, 0.5f);
      		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
   	glEnd();

   	
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("generated points");
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(magic_dots);
	glutMainLoop();
	
	return 0;
}   
