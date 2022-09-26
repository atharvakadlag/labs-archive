// ANIRUDH SAMAZDER
// CED19I044

// WEEK 5 - Arc

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>

using namespace std;

float alpha;
float beta;
float Rad_Arc;

float chk_angle;

struct circle
{
    float c[2];
    float r;
};


//Function Initialisation
void changeViewPort(int w, int h) ;
void myinit(void);
void Pixel(float x, float y);
void PlotOctants(float c[2], float x, float y);
void Draw_Arc(float c[2], float x, float y);
void mcd(circle cir, int mode);
void BLD(float point1[2], float point2[2]);
void Draw_Arc(float c[2], float x, float y);
void draw_arcs();

void changeViewPort(int w, int h) 
{
	if(w>=h)
		glViewport(w/2-h/2, 0, h, h);
	else
		glViewport(0, h/2-w/2, w, w);
}

void myinit(void)
{
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void Pixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void PlotOctants(float c[2], float x, float y)
{
    Pixel(c[0] + y, c[1] + x); //O1
    Pixel(c[0] + x, c[1] + y); //O2
    Pixel(c[0] - x, c[1] + y); //O3
    Pixel(c[0] - y, c[1] + x); //O4

    Pixel(c[0] - y, c[1] - x); //O5
    Pixel(c[0] - x, c[1] - y); //O6
    Pixel(c[0] + x, c[1] - y); //O7
    Pixel(c[0] + y, c[1] - x); //O8
}

void mcd(circle cir, int mode)
{
    float x = 0;
    float y = cir.r;

    float p = 1 - cir.r;

    int x_limit = cir.r / sqrt(2);

    for (int i = 0; i < x_limit; i++)
    {

        if (mode == 0)
            PlotOctants(cir.c, x, y);
        else
            Draw_Arc(cir.c, x, y);
        if (p < 0) //y does not change
            p += 2 * x + 3;
        else //y decrement
        {
            p += 2 * x - 2 * y + 5;
            y--;
        }
        x++;
    }
}

void BLD(float point1[2], float point2[2])
{
	int x1 = point1[0], y1 = point1[1];
	int x2 = point2[0], y2 = point2[1];

	int dx = (int)(x2 - x1);
	int dy = (int)(y2 - y1);
	int p;

	if (abs(dy) <= abs(dx))
	{
		p = 2 * abs(dy) - abs(dx);
		for (int i = 0; i < abs(dx); i++)
		{
			
			if (p >= 0)
			{
				p += (2 * abs(dy) - 2 * abs(dx));
				y1 += dy / abs(dy);
			}
			else
			{
				p += (2 * abs(dy));
			}
			x1 += dx / (abs(dx));

			
			Pixel(round(x1), round(y1));
			

			
		}
	}
	else
	{
		p = 2 * abs(dx) - abs(dy);
		for (int i = 0; i < abs(dy); i++)
		{
            

			if (p >= 0)
			{
				p += (2 * abs(dx) - 2 * abs(dy));
				x1 += dx / abs(dx);
			}
			else
			{
				p += (2 * abs(dx));
			}
			y1 += dy / (abs(dy));

			Pixel(round(x1), round(y1));

		}
	}
}

void Draw_Arc(float c[2], float x, float y)
{
    float lwr = 0;
    float upr = beta;

    chk_angle = (180 / M_PI) * atan2(x, y) + 0; //O1 y,x
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] + y, c[1] + x); //O1

    chk_angle = (180 / M_PI) * atan2(y, x) + 0; //O2 x,y
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] + x, c[1] + y); //O2

    chk_angle = (180 / M_PI) * atan2(y, -x) + 0; //O3 -x,y
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] - x, c[1] + y); //O3

    chk_angle = (180 / M_PI) * atan2(x, -y) + 0; //O4 -y,x
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] - y, c[1] + x); //O4

    chk_angle = (180 / M_PI) * atan2(-x, -y) + 360; //O5 -y,-x
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] - y, c[1] - x); //O5

    chk_angle = (180 / M_PI) * atan2(-y, -x) + 360; //O6 -x,-y
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] - x, c[1] - y); //O6

    chk_angle = (180 / M_PI) * atan2(-y, x) + 360; //O7 x,-y
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] + x, c[1] - y); //O7

    chk_angle = (180 / M_PI) * atan2(-x, y) + 360; //O8 y,-x
    if (chk_angle >= lwr && chk_angle <= upr)
        Pixel(c[0] + y, c[1] - x); //O8
}

void draw_arcs()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    circle arc = {{500, 500}, Rad_Arc};
    float xAxis[2][2] = {{arc.c[0] - 1000, arc.c[1]},
                         {arc.c[0] + 1000, arc.c[1]}};

    float yAxis[2][2] = {{arc.c[0], arc.c[1] - 1000},
                         {arc.c[0], arc.c[1] + 1000}};

    float Beg_Arc[2] = {arc.c[0] + Rad_Arc * (float)cos(0 * M_PI / 180), arc.c[1] + Rad_Arc * (float)sin(0 * M_PI / 180)};
    float End_Arc[2] = {arc.c[0] + Rad_Arc * (float)cos((beta) * M_PI / 180), arc.c[1] + Rad_Arc * (float)sin((beta) * M_PI / 180)};
    glPointSize(1);
    glColor3f(0.5, 0.5, 0.5);
    BLD(xAxis[0], xAxis[1]);
    BLD(yAxis[0], yAxis[1]);
    //rotate
    glTranslatef(arc.c[0], arc.c[1], 0);
    glRotatef(alpha, 0, 0, 1);
    glTranslatef(-arc.c[0], -arc.c[1], 0);

    BLD(arc.c, Beg_Arc);
    BLD(arc.c, End_Arc);
    glPointSize(5);
    glColor3f(0, 0, 0);
    mcd(arc, 1);

    glutSwapBuffers();
}


int main(int argc, char **argv)
{
    srand(time(0));
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);

    cout<<"Alpha: ";
    cin>>alpha;
    cout<<"Beta: ";
    cin>>beta;
    cout<<"Radius of Circle: "<<endl;
    cin>>Rad_Arc;

    glutCreateWindow("Arc Drawing");
    myinit();
    glutDisplayFunc(draw_arcs);
    glutReshapeFunc(changeViewPort);
    glutMainLoop();
}
