#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <unistd.h> 
#define HEIGHT 	720
#define WIDTH	720
#define PADDING	10
#include <iostream>
#include "bits/stdc++.h"
#include "draw_line.hpp"

using namespace std;

float mycolor[] = {1.0, 0.0, 0.0};


void draw_hexagon(void) {
	glColor3f(mycolor[0], mycolor[1], mycolor[2]); // red
	vector<pair<int, int>> hex_points;

	float radius 	= 200;
	float centerx 	= 360;
	float centery 	= 360;
	for(int i=0;i<6;++i) {
		hex_points.push_back(make_pair(centerx + radius*cos(2*3.14159*i/6.0),
										centery + radius*sin(2*3.14159*i/6.0)));
	}
	vector<pair<int, int>> line_points;
	glPointSize(10);
	glBegin(GL_POINTS);
		for(int i = 0; i < 1; i++) {
			// cout << hex_points[i].first << " " << hex_points[i].second << endl;
			// cout << hex_points[(i+1)%6].first << " " << hex_points[(i+1)%6].second << endl << endl;
			line_points = DDA(hex_points[(i+1)%6].first, hex_points[(i+1)%6].second,
								hex_points[i].first, hex_points[i].second);
		
			for (pair<int, int> a: line_points) {
				glVertex2i(a.first, a.second);
			}
		}
	glEnd();

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
	glutDisplayFunc(draw_hexagon);
	// glutKeyboardFunc(change_color);
	glutMainLoop();

	return 0;
}
