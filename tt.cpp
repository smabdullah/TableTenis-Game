#include "entry.h"
#include "draw.h"

void ballMotion(){
	//touch the net
	if((ballx+initX-ballradious <= 25.0 || ballx+initX+ballradious >= -25.0) 
		&& (bally+initY-ballradious >= 13.0 && bally+initY-ballradious <= 16.0)
		&& (ballz+initZ+ballradious == 0.0 || ballz+initZ-ballradious == 0.0)){
		yc = 0.0;
	}
	if(bally+initY-ballradious >= 13.0 && !flag){
		initX+= xc;
		initY+= yc;
		initZ+= zc;
		alpha = 1.0f;
	}
	else{
		if(flag != -1){
			yc = 0.18f;
			initX+= xc;
			initY+= yc;
			initZ+= zc;
			flag = 1;
			alpha = 1.0f;
		}

		if(((ballx+initX+ballradious <= a1+x2 && ballx+initX+ballradious >= a1+x2-5.0) ||  ballx+initX+ballradious >= a1+x2)
		&&(bally+initY+ballradious >= batminY+yp2 && bally+initY-ballradious <= batmaxY+yp2)
		&&(ballz+initZ+ballradious == b1+z2)){
			alpha = -1.0f;
			if(a1+x2 == 0){
				xc = 0.0f;
				yc = -0.10f;
				zc = -1.0f;
				flag = 0;
			}
			else if(a1+x2 > 0){
				xc = -0.2f;
				yc = -0.10f;
				zc = -1.0f;
				flag = 0;
			}
			else if(a1+x2 < 0){
				xc = 0.2f;
				yc = -0.10f;
				zc = -1.0f;
				flag = 0;
			}
		}

		if(((ballx+initX+ballradious <= a+x1 && ballx+initX+ballradious >= a+x1-5.0) ||  ballx+initX+ballradious >= a+x1)
		&&(bally+initY+ballradious >= batminY+yp1 && bally+initY-ballradious <= batmaxY+yp1)
		&&(ballz+initZ-ballradious == b+z1)){
			alpha = 1.2f;
			if(a+x1 == 0){
				xc = 0.0f;
				yc = -0.10f;
				zc = 1.0f;
				flag = 0;
			}
			else if(a+x1 > 0.0){
					xc=-0.2f;
					yc=-0.10f;
					zc=1.0f;
					flag = 0;
			}
			else if(a+x1 < 0.0){
					xc=0.2f;
					yc=-0.10f;
					zc=1.0f;
					flag = 0;
			}
		}
	}
	if(initX - prevballx >= 0.0){
		x2+= (initX - prevballx) * 1.05;
	}
	if(initX - prevballx < 0.0){
		x2+= (initX - prevballx) * 1.05;
	}

	if(initY - prevbally >= 0.0){
		yp2+= (initY - prevbally) * 0.30;
	}
	if(initY - prevbally < 0.0){
		yp2+= (initY - prevbally) * 0.30;
	}

	/*if(initZ - prevballz >= 0.0){
		z2-= (initZ - prevballz) * 0.10;
	}
	if(initZ - prevballz < 0.0){
		z2+= (prevballz - initZ) * 0.10;
	}*/
	prevballx = initX;
	prevbally = initY;
	//prevballz = initZ;
}

void startGame(){
	if(((ballx+initX+ballradious <= a+x1 && ballx+initX+ballradious >= a+x1-5.0) ||  ballx+initX+ballradious >= a+x1)
		&&(bally+initY+ballradious >= batminY+yp1 && bally+initY-ballradious <= batmaxY+yp1)
		&&(ballz+initZ-ballradious == b+z1)){
			alpha = 1.0f;
			if(a+x1 == 0){
				xc = 0.0f;
				yc = -0.10f;
				zc = 1.0f;
				flag = 0;
				ballMotion();
			}
			else if(a+x1 > 0.0){
					xc=-0.2f;
					yc=-0.10f;
					zc=1.0f;
					flag = 0;
					ballMotion();
			}
			else if(a+x1 < 0.0){
					xc=0.2f;
					yc=-0.10f;
					zc=1.0f;
					flag = 0;
					ballMotion();
			}
	}
}

void processSpecialKey(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			z1++;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			z1--;
			glutPostRedisplay();
			break;
	}
}

void processNormalKey(unsigned char key, int x, int y){
	if(key == 27)
		exit(0);
}

void passiveMouse(int x,int y){
	if(x < 512){
		x1 = (512 - x) / 16;
	}
	else if(x > 512){
		x1 = (512 - x) / 16;
	}
	
	if(y < 485){
		yp1 = (485 - y) / 16;
	}
	else if(y > 485){
		yp1 = (485 - y) / 16;
	}
}

void reshape(int width, int height){
	double aspect = (double)width / (double)height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,aspect,0.1f,200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	obj = gluNewQuadric();
	glPushMatrix();
		camera = camera+alpha;
		if(camera > 95.0f)
			camera = 95.0f;
		else if(camera < -95.0f)
			camera = -95.0f;
		gluLookAt(
				  0.0,30.0,-95.0,  
				  0.0,30.0,0.0,
				  0.0,1.0,0.0
		);
		drawWindow();
		drawRoom();
		drawTable();
		drawTableLeg();
		drawTableNet();
		drawWindow();
		
		glPushMatrix();
			float angle,anglez;
			if(x1 >= 25)
				x1 = 25;
			else if(x1 <= -25)
				x1 = -25;
			if(z1 >= 50)
				z1 = 50;
			
			if(a+x1 == 0.0f){
				angle = 0.0f;
				anglez = 0.0f;
			}
			else if(a+x1 < 0.0f){
				angle = 30.0f;
				anglez = -10.0f;
			}
			else{
				angle = -30.0f;
				anglez = 10.0f;
			}

			glTranslatef(a+x1,18.0f+yp1,b+z1);
			glRotatef(angle,0.0,1.0,0.0);
			glRotatef(anglez,0.0,0.0,1.0);
			drawBat();
		glPopMatrix();

		glPushMatrix();
			float angle1,anglez1;
			if(x2 >= 25)
				x2 = 25;
			else if(x2 <= -25)
				x2 = -25;
			if(z2 <= -50)
				z2 = -50;

			if(a1+x2 == 0.0f){
				angle1 = 0.0f;
				anglez1 = 0.0f;
			}
			else if(a1+x2 < 0.0f){
				angle1 = -30.0f;
				anglez1 = 10.0f;
			}
			else{
				angle1 = 30.0f;
				anglez1 = -10.0f;
			}
			glTranslatef(a1+x2,18.0f+yp2,b1+z2);
			glRotatef(angle1,0.0,1.0,0.0);
			drawBat();
		glPopMatrix();

		glPushMatrix();
			drawBall();
		glPopMatrix();

		glPushMatrix();
			startGame();
		glPopMatrix();
	
	glPopMatrix();
	glutSwapBuffers();
}

void init(void){
	glClearColor(0.0,0.0,0.0,1.0);
	glEnable(GL_DEPTH_TEST);
}

void Timer(int ex){
	glutPostRedisplay();
	ballMotion();
	glutTimerFunc(20,Timer,0);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Table Tennis Game");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(processSpecialKey);
	glutKeyboardFunc(processNormalKey);
	glutPassiveMotionFunc(passiveMouse);
	//glutMouseFunc(activeMouse);
	glutTimerFunc(0,Timer,0);
	glutMainLoop();
return 0;
}
