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
	vector<pair<int, int>> line_points;

    //sq1
	vector<pair<int, int>> sq1;
    sq1.push_back(make_pair(100,50));
    sq1.push_back(make_pair(300,50));
    sq1.push_back(make_pair(300, 300));
    sq1.push_back(make_pair(100,300));
    //tri
	vector<pair<int, int>> tri;
    tri.push_back(make_pair(100,300));
    tri.push_back(make_pair(200,400));
    tri.push_back(make_pair(300,300));

    //window
	vector<pair<int, int>> wind1;
    wind1.push_back(make_pair(130,130));
    wind1.push_back(make_pair(160,130));
    wind1.push_back(make_pair(160,160));
    wind1.push_back(make_pair(130,160));

    //win
	vector<pair<int, int>> wind2;
    wind2.push_back(make_pair(240,130));
    wind2.push_back(make_pair(270,130));
    wind2.push_back(make_pair(270,160));
    wind2.push_back(make_pair(240,160));

    //door
	vector<pair<int, int>> door;
    door.push_back(make_pair(180,50));
    door.push_back(make_pair(180,160));
    door.push_back(make_pair(220,160));
    door.push_back(make_pair(220,50));
    
	glPointSize(10);
	glBegin(GL_POINTS);
        for(int i=0; i<sq1.size(); i++) {
            line_points = DDA(sq1[i].first, sq1[i].second,
            sq1[(i+1)%sq1.size()].first, sq1[(i+1)%sq1.size()].second);
        }
        for(int i=0; i<wind1.size(); i++) {
            line_points = DDA(wind1[i].first, wind1[i].second,
            wind1[(i+1)%wind1.size()].first, wind1[(i+1)%wind1.size()].second);
        }
        for(int i=0; i<wind2.size(); i++) {
            line_points = DDA(wind2[i].first, wind2[i].second,
            wind2[(i+1)%wind2.size()].first, wind2[(i+1)%wind2.size()].second);
        }
        for(int i=0; i<door.size(); i++) {
            line_points = DDA(door[i].first, door[i].second,
            door[(i+1)%door.size()].first, door[(i+1)%door.size()].second);
        }
        for(int i=0; i<tri.size(); i++) {
            line_points = DDA(tri[i].first, tri[i].second,
            tri[(i+1)%tri.size()].first, tri[(i+1)%tri.size()].second);
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
