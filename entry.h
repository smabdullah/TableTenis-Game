#ifndef ENTRY_H
#define ENTRY_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define WIDTH 1024
#define HEIGHT 768

int x1 = 0;
int yp1 = 0;
int z1 = 0;
float x2 = 0;
float yp2 = 0;
float z2 = 0;
int ballx = 0;
int bally = 0;
int ballz = 0;
int prevx = 512;
float alpha = 0.0;
float a1 = 0.0;
float a = 0.0;
float b = -62.0;
float b1 = 62.0;
float initX = 0.0;
float initY = 23.0;
float initZ = -58.0;
float prevballx = 0.0;
float prevbally = 23.0;
float prevballz = -58.0;
float ballradious = 1.00;
float xc = 0.0;
float yc = 0.0;
float zc = 0.0;
float ac = 0.0;
int flag = -1;
float batminY = 18.0f;
float batmaxY = 23.0f;
float camera = -95.0f;

#endif