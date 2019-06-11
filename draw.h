#ifndef DRAW_H
#define DRAW_H
#include "entry.h"

GLUquadricObj *obj;

void lightSetup(){
	float ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	float diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
	float lightPos[] = { 10.0f, 60.0f, -45.0f, 1.0f };
	float specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos) ;
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	glMateriali(GL_FRONT,GL_SHININESS,128);
}

void drawBall(){
	glColor3f(0.99f,0.64f,0.06f);
	glEnable(GL_LIGHTING);
	lightSetup();
	glTranslatef(initX+ballx,initY+bally,initZ+ballz);
	gluSphere(obj,ballradious,32,32);
	glDisable(GL_LIGHTING);
}

void drawBat(void){
	//floor
	glBegin(GL_QUADS);
		glColor3f(0.82f,0.07f,0.09f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(-5.0f,0.0f,0.0f);
		glVertex3f(-5.0f,5.0f,0.0f);
		glVertex3f(0.0f,5.0f,0.0f);
	glEnd();

	//ceil
	glBegin(GL_QUADS);
		glColor3f(0.82f,0.07f,0.09f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(-5.0f,0.0f,1.0f);
		glVertex3f(-5.0f,5.0f,1.0f);
		glVertex3f(0.0f,5.0f,1.0f);
	glEnd();

	//front
	glBegin(GL_QUADS);
		glColor3f(0.97f,0.60f,0.49f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(-5.0f,0.0f,0.0f);
		glVertex3f(-5.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,1.0f);
	glEnd();

	//rear
	glBegin(GL_QUADS);
		glColor3f(0.97f,0.60f,0.49f);
		glVertex3f(-5.0f,5.0f,0.0f);
		glVertex3f(0.0f,5.0f,0.0f);
		glVertex3f(0.0f,5.0f,1.0f);
		glVertex3f(-5.0f,5.0f,1.0f);
	glEnd();

	//left
	glBegin(GL_QUADS);
		glColor3f(0.97f,0.49f,0.36f);
		glVertex3f(-5.0f,0.0f,0.0f);
		glVertex3f(-5.0f,5.0f,0.0f);
		glVertex3f(-5.0f,5.0f,1.0f);
		glVertex3f(-5.0f,0.0f,1.0f);
	glEnd();

	//right
	glBegin(GL_QUADS);
		glColor3f(0.97f,0.49f,0.36f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,5.0f,0.0f);
		glVertex3f(0.0f,5.0f,1.0f);
		glVertex3f(0.0f,0.0f,1.0f);
	glEnd();
	
	//draw bat handle
	glBegin(GL_QUADS);
		glColor3f(0.87f,0.86f,0.53f);
		glVertex3f(-2.0f,0.0f,0.25f);
		glVertex3f(-3.0f,0.0f,0.25f);
		glVertex3f(-3.0f,-2.0f,0.25f);
		glVertex3f(-2.0f,-2.0f,0.25f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.87f,0.86f,0.53f);
		glVertex3f(-2.0f,0.0f,0.75f);
		glVertex3f(-3.0f,0.0f,0.75f);
		glVertex3f(-3.0f,-2.0f,0.75f);
		glVertex3f(-2.0f,-2.0f,0.75f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.81f,0.88f,0.42f);
		glVertex3f(-2.0f,0.0f,0.25f);
		glVertex3f(-2.0f,-2.0f,0.25f);
		glVertex3f(-2.0f,-2.0f,0.75f);
		glVertex3f(-2.0f,0.0f,0.75f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.81f,0.88f,0.42f);
		glVertex3f(-3.0f,0.0f,0.25f);
		glVertex3f(-3.0f,-2.0f,0.25f);
		glVertex3f(-3.0f,-2.0f,0.75f);
		glVertex3f(-3.0f,0.0f,0.75f);
	glEnd();
}

void drawTableLeg(void){
	glBegin(GL_QUADS);
		glColor3f(0.41f,0.21f,0.09f);
		glVertex3f(25.0f,0.0f,-50.0f);
		glVertex3f(23.0f,0.0f,-50.0f);
		glVertex3f(23.0f,10.0f,-50.0f);
		glVertex3f(25.0f,10.0f,-50.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.41f,0.21f,0.09f);
		glVertex3f(-25.0f,0.0f,-50.0f);
		glVertex3f(-23.0f,0.0f,-50.0f);
		glVertex3f(-23.0f,10.0f,-50.0f);
		glVertex3f(-25.0f,10.0f,-50.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.41f,0.21f,0.09f);
		glVertex3f(25.0f,0.0f,50.0f);
		glVertex3f(23.0f,0.0f,50.0f);
		glVertex3f(23.0f,10.0f,50.0f);
		glVertex3f(25.0f,10.0f,50.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.41f,0.21f,0.09f);
		glVertex3f(-25.0f,0.0f,50.0f);
		glVertex3f(-23.0f,0.0f,50.0f);
		glVertex3f(-23.0f,10.0f,50.0f);
		glVertex3f(-25.0f,10.0f,50.0f);
	glEnd();
}

void drawTableNet(void){
	float i;
	glBegin(GL_LINES);
		glColor3f(0.63f,0.63f,0.61f);
		
		glVertex3f(-25.0f,13.0f,0.0f);
		glVertex3f(25.0f,13.0f,0.0f);
		
		glVertex3f(25.0f,14.0f,0.0f);
		glVertex3f(-25.0f,14.0f,0.0f);

		glVertex3f(25.0f,15.0f,0.0f);
		glVertex3f(-25.0f,15.0f,0.0f);

		glVertex3f(25.0f,16.0f,0.0f);
		glVertex3f(-25.0f,16.0f,0.0f);

		for(i = -25.0f ; i <= 25.0f ; i+= 1.0f){
			glVertex3f(i,13.0f,0.0f);
			glVertex3f(i,16.0f,0.0f);
		}
	glEnd();
}

void drawTable(void){
	//ceil
	//glEnable(GL_LIGHTING);
	//lightSetup();
	glBegin(GL_QUADS);
		glColor3f(0.32f,0.45f,0.69f);
		glVertex3f(25.0f,13.0f,-50.0f);
		glVertex3f(-25.0f,13.0f,-50.0f);
		glVertex3f(-25.0f,13.0f,50.0f);
		glVertex3f(25.0f,13.0f,50.0f);
	glEnd();
	
	//front
	glBegin(GL_QUADS);
		glColor3f(0.33f,0.33f,0.32f);
		glVertex3f(25.0f,10.0f,-50.0f);
		glVertex3f(-25.0f,10.0f,-50.0f);
		glVertex3f(-25.0f,13.0f,-50.0f);
		glVertex3f(25.0f,13.0f,-50.0f);
	glEnd();

	//rear
	glBegin(GL_QUADS);
		glColor3f(0.33f,0.33f,0.32f);
		glVertex3f(25.0f,10.0f,50.0f);
		glVertex3f(-25.0f,10.0f,50.0f);
		glVertex3f(-25.0f,13.0f,50.0f);
		glVertex3f(25.0f,13.0f,50.0f);
	glEnd();

	//left
	glBegin(GL_QUADS);
		glColor3f(0.46f,0.50f,0.52f);
		glVertex3f(-25.0f,10.0f,-50.0f);
		glVertex3f(-25.0f,10.0f,50.0f);
		glVertex3f(-25.0f,13.0f,50.0f);
		glVertex3f(-25.0f,13.0f,-50.0f);
	glEnd();

	//right
	glBegin(GL_QUADS);
		glColor3f(0.46f,0.50f,0.52f);
		glVertex3f(25.0f,10.0f,-50.0f);
		glVertex3f(25.0f,10.0f,50.0f);
		glVertex3f(25.0f,13.0f,50.0f);
		glVertex3f(25.0f,13.0f,-50.0f);
	glEnd();
	//glDisable(GL_LIGHTING);
}

void drawRoom(void){
	//roof
	glBegin(GL_QUADS);
		glColor3f(0.42f,0.42f,0.42f);
		glVertex3f(100.0f,0.0f,-100.0f);
		glVertex3f(-100.0f,0.0f,-100.0f);
		glVertex3f(-100.0f,0.0f,100.0f);
		glVertex3f(100.0f,0.0f,100.0f);
	glEnd();

	//ceil
	glBegin(GL_QUADS);
		glColor3f(0.42f,0.42f,0.42f);
		glVertex3f(100.0f,200.0f,-100.0f);
		glVertex3f(-100.0f,200.0f,-100.0f);
		glVertex3f(-100.0f,200.0f,100.0f);
		glVertex3f(100.0f,200.0f,100.0f);
	glEnd();
	
	//rear
	glBegin(GL_QUADS);
		glColor3f(0.93f,0.80f,0.61f);
		glVertex3f(100.0f,0.0f,100.0f);
		glVertex3f(-100.0f,0.0f,100.0f);
		glVertex3f(-100.0f,200.0f,100.0f);
		glVertex3f(100.0f,200.0f,100.0f);
	glEnd();

	//front
	glBegin(GL_QUADS);
		glColor3f(0.93f,0.80f,0.61f);
		glVertex3f(100.0f,0.0f,-100.0f);
		glVertex3f(-100.0f,0.0f,-100.0f);
		glVertex3f(-100.0f,200.0f,-100.0f);
		glVertex3f(100.0f,200.0f,-100.0f);
	glEnd();
	
	//left
	glBegin(GL_QUADS);
		glColor3f(0.96f,0.84f,0.64f);
		glVertex3f(-100.0f,0.0f,-100.0f);
		glVertex3f(-100.0f,0.0f,100.0f);
		glVertex3f(-100.0f,200.0f,100.0f);
		glVertex3f(-100.0f,200.0f,-100.0f);
	glEnd();
	
	//right
	glBegin(GL_QUADS);
		glColor3f(0.94f,0.81f,0.62f);
		glVertex3f(100.0f,0.0f,100.0f);
		glVertex3f(100.0f,0.0f,-100.0f);
		glVertex3f(100.0f,200.0f,-100.0f);
		glVertex3f(100.0f,200.0f,100.0f);
	glEnd();
}

void drawWindow(){
	//front
	glBegin(GL_QUADS);
		glColor3f(0.74f,0.89f,0.95f);
		glVertex3f(75.0f,60.0f,96.0f);
		glVertex3f(-75.0f,60.0f,96.0f);
		glVertex3f(-75.0f,110.0f,96.0f);
		glVertex3f(75.0f,110.0f,96.0f);
	glEnd();

	//rear
	/*glBegin(GL_QUADS);
		glColor3f(0.74,0.89,0.95);
		glVertex3f(75.0,60.0,100.0);
		glVertex3f(-75.0,60.0,100.0);
		glVertex3f(-75.0,110.0,100.0);
		glVertex3f(75.0,110.0,100.0);
	glEnd();*/

	//left
	glBegin(GL_QUADS);
		glColor3f(0.99f,0.98f,1.00f);
		glVertex3f(75.0f,60.0f,100.0f);
		glVertex3f(75.0f,110.0f,100.0f);
		glVertex3f(75.0f,110.0f,96.0f);
		glVertex3f(75.0f,60.0f,96.0f);
	glEnd();

	//right
	glBegin(GL_QUADS);
		glColor3f(0.99f,0.98f,1.00f);
		glVertex3f(-75.0f,60.0f,100.0f);
		glVertex3f(-75.0f,110.0f,100.0f);
		glVertex3f(-75.0f,110.0f,96.0f);
		glVertex3f(-75.0f,60.0f,96.0f);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
		glColor3f(0.99f,0.99f,0.98f);
		glVertex3f(75.0f,60.0f,100.0f);
		glVertex3f(-75.0f,60.0f,100.0f);
		glVertex3f(-75.0f,60.0f,96.0f);
		glVertex3f(75.0f,60.0f,96.0f);
	glEnd();

	//top
	glBegin(GL_QUADS);
		glColor3f(0.99f,0.99f,0.98f);
		glVertex3f(-75.0f,110.0f,100.0f);
		glVertex3f(75.0f,110.0f,100.0f);
		glVertex3f(75.0f,110.0f,96.0f);
		glVertex3f(-75.0f,110.0f,96.0f);
	glEnd();
}

#endif