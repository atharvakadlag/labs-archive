#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#include <bits/stdc++.h>
#include "circle_draw.hpp"
#include "line_draw.hpp"

using namespace std;

#define arc vector<pair<int, int>>
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10


arc get_arc(int radius, float alpha, float beta) {
    arc a1;
    circle c1 = MCD(0,0,radius);

    float start_slope = tan(alpha);
    float end_slope = tan(alpha+beta);
    cout << start_slope << " " << end_slope << endl;
    for (auto i: c1) {
        // float slope = 1;
        float slope = i.second/(i.first+0.00000001);
        if (slope < end_slope && slope > start_slope) {
            a1.push_back(point(i.first, i.second));
        } else {
            // cout << slope << endl;
        }
    }

    return a1;
}

void draw_arc(void) {
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    arc a1 = get_arc(100, 3*M_PI/4, M_PI/2.6);
    cout << a1.size() << endl;
	glColor3f(0, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
		for (auto i: a1) {
			glVertex2d(i.first, i.second);
            // cout << i.first << ", " << i.second << endl;
		}
        glVertex2d(0,0);
	glEnd();
	glFlush();
    glFlush();
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH+PADDING, HEIGHT+PADDING);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("generated points");
    gluOrtho2D(-320, 320, -320, 320);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_arc);
	// glutKeyboardFunc(move_car);
	glutMainLoop();
	
	return 0;
}