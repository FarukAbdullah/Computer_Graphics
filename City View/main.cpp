#include<windows.h>
#include<math.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.14159265358979323846

GLfloat positionTrain = 0.0f;
GLfloat speedTrain = 0.006f;

GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.009f;

GLfloat positionBus = 0.0f;
GLfloat speedBus = 0.004f;

GLfloat positionSun = 0.0f;
GLfloat speedSun = 0.0008f;

GLfloat positionMoon = 0.0f;
GLfloat speedMoon = 0.0006f;

GLfloat positionCloud = 0.0f;
GLfloat speedCloud = 0.00099f;

GLfloat positionBoat = 0.0f;
GLfloat speedBoat = 0.0007f;
GLfloat positionBoat1 = 0.0f;
GLfloat speedBoat1 = 0.0008f;

GLfloat positionCar1 = 0.0f;
GLfloat speedCar1 = 0.001f;

GLfloat positionNCar1 = 0.0f;
GLfloat speedNCar1 = 0.002f;

GLfloat positionCar2 = 0.0f;
GLfloat speedCar2 = 0.002f;


void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{

case 's':
    speedCloud = 0.0f;

    break;
case 'h':
    speedCloud = 0.001f;
    break;

case 'l':
    speedCloud = 0.00001f;

    break;


glutPostRedisplay();


	}
}


void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
//do something here
   speedTrain=0.007;
break;
case GLUT_KEY_DOWN:

   speedTrain=0.004;
break;
case GLUT_KEY_LEFT:
    speedTrain=0.0f;


break;

case GLUT_KEY_RIGHT:
    speedTrain=0.00008f;

//do something here
break;
}
glutPostRedisplay();
}


void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{

			speedBoat = 0.0008f;
			speedBoat1 = 0.0009f;


	}

		if (button == GLUT_RIGHT_BUTTON)
	{

			speedBoat1 = 0.0003f;
			speedBoat = 0.0003f;


	}



	glutPostRedisplay();
}





void updateTrain(int value) {
    if(positionTrain <-6.0)
        positionTrain = 6.0f;
    positionTrain -= speedTrain;
	glutPostRedisplay();
	glutTimerFunc(1, updateTrain, 0);
}


void updateBus(int value) {
    if(positionBus <-8.0)
        positionBus = 8.0f;
    positionBus -= speedBus;
	glutPostRedisplay();
	glutTimerFunc(1, updateBus, 0);
}
void updateCloud(int value) {
    if(positionCloud <-6.0)
        positionCloud = 6.0f;
    positionCloud -= speedCloud;
	glutPostRedisplay();
	glutTimerFunc(1, updateCloud, 0);
}

void updateBoat(int value) {
    if(positionBoat <-6.0)
        positionBoat = 6.0f;
    positionBoat -= speedBoat;
	glutPostRedisplay();
	glutTimerFunc(1, updateBoat, 0);
}

void updateBoat1(int value) {
    if(positionBoat1 > 6.0)
        positionBoat1 = -6.0f;
    positionBoat1 += speedBoat1;
	glutPostRedisplay();
	glutTimerFunc(1, updateBoat1, 0);
}

void updateSun(int value) {
    if(positionSun <-4.0)
        positionSun = 4.0f;
    positionSun -= speedSun;
	glutPostRedisplay();
	glutTimerFunc(1, updateSun, 0);
}

void updateRain(int value) {
    if(positionRain <-6.0)
        positionRain = 5.0f;
    positionRain -= speedRain;
	glutPostRedisplay();
	glutTimerFunc(1, updateRain, 0);
}
void updateMoon(int value) {
    if(positionMoon >4.0)
        positionMoon = -2.0f;
    positionMoon += speedMoon;
	glutPostRedisplay();
	glutTimerFunc(1, updateMoon, 0);
}
void updateCar1(int value) {
    if(positionCar1 > 6.0)
        positionCar1 = -6.0f;
    positionCar1 += speedCar1;
	glutPostRedisplay();
	glutTimerFunc(1, updateCar1, 0);
}
void updateNCar1(int value) {
    if(positionNCar1 > 6.0)
        positionNCar1 = -6.0f;
    positionNCar1 += speedNCar1;
	glutPostRedisplay();
	glutTimerFunc(1, updateNCar1, 0);
}

void updateCar2(int value) {
    if(positionCar2 <-6.0)
        positionCar2 = 6.0f;
    positionCar2 -= speedCar2;
	glutPostRedisplay();
	glutTimerFunc(1, updateCar2, 0);
}


void soundCar()
{


    PlaySound("bmw.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void soundRain()
{


    PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void soundtraffic()
{


    PlaySound("traffic.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void displayNightVer2() {

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
gluOrtho2D(-5,5,-4,4);

//sky
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient[] = {0.0,0.0,2.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

glColor3ub(128, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,4);
	glVertex2f(-5,.5);
	glVertex2f(5,.5);
	glVertex2f(5,4);
	glEnd();
  glDisable(GL_LIGHTING);
	 int i1;
//Moon

	GLfloat x1=0; GLfloat y1=3.5; GLfloat radius1 =.4f;
	int triangleAmount = 100; //# of triangles used to draw circle


	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,230);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPushMatrix();
glTranslatef(positionCloud,0.0, 0.0f);
//clouds
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient2[] = {3.5,3.5,3.5, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
	GLfloat x2=-2.5; GLfloat y2=3.5; GLfloat radius2 =.3f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x2, y2); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x2 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x3=-2.9; GLfloat y3=3.3;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x3, y3); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x3 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y3 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x4=-2.65; GLfloat y4=2.95;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x4, y4); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x4 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y4 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x5=2; GLfloat y5=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x5 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y5 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x6=2.26; GLfloat y6=3.04;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x6, y6); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x6 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y6 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x7=1.8; GLfloat y7=3;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x7, y7); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x7 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y7 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x8=-2.2; GLfloat y8=3.2;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191,191,191);
		glVertex2f(x8, y8); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x8 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y8 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x9=1.6; GLfloat y9=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x9, y9); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x9 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y9 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	glDisable(GL_LIGHTING);

	glPopMatrix();

//building
glColor3ub(255, 140, 26);
	glBegin(GL_QUADS);
	glVertex2f(-5,3);
	glVertex2f(-5,.5);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.9,3);
	glEnd();
glColor3ub(204, 102, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.9,3);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.7,.5);
	glVertex2f(-3.7,2.7);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(-4.85,2.8);
	glVertex2f(-4.85,2.4);
	glVertex2f(-4.5,2.4);
	glVertex2f(-4.5,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.4,2.8);
	glVertex2f(-4.4,2.4);
	glVertex2f(-4.05,2.4);
	glVertex2f(-4.05,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,2.2);
	glVertex2f(-4.85,1.8);
	glVertex2f(-4.5,1.8);
	glVertex2f(-4.5,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1.6);
	glVertex2f(-4.85,1.2);
	glVertex2f(-4.5,1.2);
	glVertex2f(-4.5,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1);
	glVertex2f(-4.85,.5);
	glVertex2f(-4.5,.5);
	glVertex2f(-4.5,1);
	glEnd();
	////
glColor3ub(204, 102, 153);
	glBegin(GL_QUADS);
	glVertex2f(-4.6,2.5);
	glVertex2f(-4.6,.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.5,2.5);
	glEnd();
glColor3ub(172, 57, 115);
	glBegin(GL_QUADS);
	glVertex2f(-3.5,2.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.3,.5);
	glVertex2f(-3.3,2.2);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(-4.45,2.3);
	glVertex2f(-4.45,1.9);
	glVertex2f(-4.1,1.9);
	glVertex2f(-4.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,2.3);
	glVertex2f(-4,1.9);
	glVertex2f(-3.65,1.9);
	glVertex2f(-3.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.7);
	glVertex2f(-4.45,1.3);
	glVertex2f(-4.1,1.3);
	glVertex2f(-4.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.7);
	glVertex2f(-4,1.3);
	glVertex2f(-3.65,1.3);
	glVertex2f(-3.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.1);
	glVertex2f(-4.45,.7);
	glVertex2f(-4.1,.7);
	glVertex2f(-4.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.1);
	glVertex2f(-4,.7);
	glVertex2f(-3.65,.7);
	glVertex2f(-3.65,1.1);
	glEnd();
	////
glColor3ub(178, 178, 102);
	glBegin(GL_QUADS);
	glVertex2f(-2.6,2.5);
	glVertex2f(-2.6,.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,2.5);
	glEnd();
glColor3ub(136, 136, 68);
	glBegin(GL_QUADS);
	glVertex2f(-1.5,2.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,2.2);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(-2.45,2.3);
	glVertex2f(-2.45,1.9);
	glVertex2f(-2.1,1.9);
	glVertex2f(-2.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,2.3);
	glVertex2f(-2,1.9);
	glVertex2f(-1.65,1.9);
	glVertex2f(-1.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.7);
	glVertex2f(-2.45,1.3);
	glVertex2f(-2.1,1.3);
	glVertex2f(-2.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.7);
	glVertex2f(-2,1.3);
	glVertex2f(-1.65,1.3);
	glVertex2f(-1.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.1);
	glVertex2f(-2.45,.7);
	glVertex2f(-2.1,.7);
	glVertex2f(-2.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.1);
	glVertex2f(-2,.7);
	glVertex2f(-1.65,.7);
	glVertex2f(-1.65,1.1);
	glEnd();

	////
glColor3ub(204, 102, 204);
	glBegin(GL_QUADS);
	glVertex2f(-3.25,2);
	glVertex2f(-3.25,.5);
	glVertex2f(-2.2,.5);
	glVertex2f(-2.2,2);
	glEnd();
glColor3ub(191, 64, 191);
	glBegin(GL_QUADS);
	glVertex2f(-2.2,2);
	glVertex2f(-2.2,.5);
	glVertex2f(-2,.5);
	glVertex2f(-2,1.7);
	glEnd();
////windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(-3.15,1.8);
	glVertex2f(-3.15,1.4);
	glVertex2f(-2.8,1.4);
	glVertex2f(-2.8,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.8);
	glVertex2f(-2.7,1.4);
	glVertex2f(-2.35,1.4);
	glVertex2f(-2.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-3.15,1.2);
	glVertex2f(-3.15,.8);
	glVertex2f(-2.8,.8);
	glVertex2f(-2.8,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.2);
	glVertex2f(-2.7,.8);
	glVertex2f(-2.35,.8);
	glVertex2f(-2.35,1.2);
	glEnd();

	////
glColor3ub(102, 153, 153);
	glBegin(GL_QUADS);
	glVertex2f(-1.1,2.5);
	glVertex2f(-1.1,.5);
	glVertex2f(0,.5);
	glVertex2f(0,2.5);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(0,2.5);
	glVertex2f(0,.5);
	glVertex2f(.2,.5);
	glVertex2f(.2,2.2);
	glEnd();

//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(-.95,2.3);
	glVertex2f(-.95,1.9);
	glVertex2f(-.6,1.9);
	glVertex2f(-.6,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,2.3);
	glVertex2f(-.5,1.9);
	glVertex2f(-.15,1.9);
	glVertex2f(-.15,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.7);
	glVertex2f(-.95,1.3);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.3);
	glVertex2f(-.15,1.3);
	glVertex2f(-.15,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.1);
	glVertex2f(-.95,.7);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5,.7);
	glVertex2f(-.15,.7);
	glVertex2f(-.15,1.1);
	glEnd();
////
glColor3ub(133, 133, 173);
	glBegin(GL_QUADS);
	glVertex2f(.4,2);
	glVertex2f(.4,.5);
	glVertex2f(1.5,.5);
	glVertex2f(1.5,2);
	glEnd();
////windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(.55,1.8);
	glVertex2f(.55,1.4);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.8);
	glVertex2f(1,1.4);
	glVertex2f(1.35,1.4);
	glVertex2f(1.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(.55,1.2);
	glVertex2f(.55,.8);
	glVertex2f(.9,.8);
	glVertex2f(.9,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.2);
	glVertex2f(1,.8);
	glVertex2f(1.35,.8);
	glVertex2f(1.35,1.2);
	glEnd();

////
glColor3ub(71, 107, 107);
	glBegin(GL_QUADS);
	glVertex2f(1.7,2.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,3);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(1.9,3);
	glVertex2f(1.9,.5);
	glVertex2f(3,.5);
	glVertex2f(3,3);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(2.05,2.8);
	glVertex2f(2.05,2.4);
	glVertex2f(2.4,2.4);
	glVertex2f(2.4,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.8);
	glVertex2f(2.5,2.4);
	glVertex2f(2.85,2.4);
	glVertex2f(2.85,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,2.2);
	glVertex2f(2.05,1.8);
	glVertex2f(2.4,1.8);
	glVertex2f(2.4,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.2);
	glVertex2f(2.5,1.8);
	glVertex2f(2.85,1.8);
	glVertex2f(2.85,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1.6);
	glVertex2f(2.05,1.2);
	glVertex2f(2.4,1.2);
	glVertex2f(2.4,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1.6);
	glVertex2f(2.5,1.2);
	glVertex2f(2.85,1.2);
	glVertex2f(2.85,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1);
	glVertex2f(2.05,.5);
	glVertex2f(2.4,.5);
	glVertex2f(2.4,1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1);
	glVertex2f(2.5,.5);
	glVertex2f(2.85,.5);
	glVertex2f(2.85,1);
	glEnd();

////
glColor3ub(0, 134, 179);
	glBegin(GL_QUADS);
	glVertex2f(3.8,3.2);
	glVertex2f(3.8,.5);
	glVertex2f(4,.5);
	glVertex2f(4,3.5);
	glEnd();
glColor3ub(0, 153, 204);
	glBegin(GL_QUADS);
	glVertex2f(4,3.5);
	glVertex2f(4,.5);
	glVertex2f(5,.5);
	glVertex2f(5,3.5);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(4.15,3.3);
	glVertex2f(4.15,2.9);
	glVertex2f(4.5,2.9);
	glVertex2f(4.5,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,3.3);
	glVertex2f(4.6,2.9);
	glVertex2f(4.95,2.9);
	glVertex2f(4.95,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.7);
	glVertex2f(4.15,2.3);
	glVertex2f(4.5,2.3);
	glVertex2f(4.5,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.7);
	glVertex2f(4.6,2.3);
	glVertex2f(4.95,2.3);
	glVertex2f(4.95,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.1);
	glVertex2f(4.15,1.7);
	glVertex2f(4.5,1.7);
	glVertex2f(4.5,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.1);
	glVertex2f(4.6,1.7);
	glVertex2f(4.95,1.7);
	glVertex2f(4.95,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,1.5);
	glVertex2f(4.15,1.1);
	glVertex2f(4.5,1.1);
	glVertex2f(4.5,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,1.5);
	glVertex2f(4.6,1.1);
	glVertex2f(4.95,1.1);
	glVertex2f(4.95,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,.9);
	glVertex2f(4.15,.7);
	glVertex2f(4.5,.7);
	glVertex2f(4.5,.9);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,.9);
	glVertex2f(4.6,.7);
	glVertex2f(4.95,.7);
	glVertex2f(4.95,.9);
	glEnd();
////
glColor3ub(122, 122, 82);
	glBegin(GL_QUADS);
	glVertex2f(3.1,2.2);
	glVertex2f(3.1,.5);
	glVertex2f(3.3,.5);
	glVertex2f(3.3,2.5);
	glEnd();
glColor3ub(138, 138, 92);
	glBegin(GL_QUADS);
	glVertex2f(3.3,2.5);
	glVertex2f(3.3,.5);
	glVertex2f(4.4,.5);
	glVertex2f(4.4,2.5);
	glEnd();
//windows
glColor3ub(160, 160, 160);
	glBegin(GL_QUADS);
	glVertex2f(3.45,2.3);
	glVertex2f(3.45,1.9);
	glVertex2f(3.8,1.9);
	glVertex2f(3.8,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,2.3);
	glVertex2f(3.9,1.9);
	glVertex2f(4.25,1.9);
	glVertex2f(4.25,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.7);
	glVertex2f(3.45,1.3);
	glVertex2f(3.8,1.3);
	glVertex2f(3.8,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.7);
	glVertex2f(3.9,1.3);
	glVertex2f(4.25,1.3);
	glVertex2f(4.25,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.1);
	glVertex2f(3.45,.7);
	glVertex2f(3.8,.7);
	glVertex2f(3.8,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.1);
	glVertex2f(3.9,.7);
	glVertex2f(4.25,.7);
	glVertex2f(4.25,1.1);
	glEnd();


//river
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient1[] = {0.0,0.0,3.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);


glColor3ub(26, 198, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2.3);
	glVertex2f(-5,-4);
	glVertex2f(5,-4);
	glVertex2f(5,-2.3);
	glEnd();

glDisable(GL_LIGHTING);



//road
glColor3ub(61, 61, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,.2);
	glVertex2f(-5,-2);
	glVertex2f(5,-2);
	glVertex2f(5,.2);
	glEnd();

//divider
glColor3ub(61, 0, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,-.8);
	glVertex2f(-5,-1);
	glVertex2f(5,-1);
	glVertex2f(5,-.8);
	glEnd();

glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-5,.4);
	glVertex2f(-5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();
glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-4.5,.4);
	glVertex2f(-4.5,.2);
	glVertex2f(-4,.2);
	glVertex2f(-4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-3.5,.4);
	glVertex2f(-3.5,.2);
	glVertex2f(-3,.2);
	glVertex2f(-3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.5,.4);
	glVertex2f(-2.5,.2);
	glVertex2f(-2,.2);
	glVertex2f(-2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-1.5,.4);
	glVertex2f(-1.5,.2);
	glVertex2f(-1,.2);
	glVertex2f(-1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-.5,.4);
	glVertex2f(-.5,.2);
	glVertex2f(0,.2);
	glVertex2f(0,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(.5,.4);
	glVertex2f(.5,.2);
	glVertex2f(1,.2);
	glVertex2f(1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(1.5,.4);
	glVertex2f(1.5,.2);
	glVertex2f(2,.2);
	glVertex2f(2,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(2.5,.4);
	glVertex2f(2.5,.2);
	glVertex2f(3,.2);
	glVertex2f(3,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(3.5,.4);
	glVertex2f(3.5,.2);
	glVertex2f(4,.2);
	glVertex2f(4,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(4.5,.4);
	glVertex2f(4.5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();





//border of river
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2);
	glVertex2f(-5,-2.3);
	glVertex2f(4,-2.3);
	glVertex2f(4,-2);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(-4,-2);
	glVertex2f(-4,-2.3);
	glVertex2f(-3,-2.3);
	glVertex2f(-3,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-2,-2);
	glVertex2f(-2,-2.3);
	glVertex2f(-1,-2.3);
	glVertex2f(-1,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(0,-2);
	glVertex2f(0,-2.3);
	glVertex2f(1,-2.3);
	glVertex2f(1,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2,-2);
	glVertex2f(2,-2.3);
	glVertex2f(3,-2.3);
	glVertex2f(3,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4,-2);
	glVertex2f(4,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();



glLineWidth(5.5);
glColor3ub(220,220,220);

glBegin(GL_LINES);
glVertex2f(-4.4,-1.5);
glVertex2f(-4.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-1.5);
glVertex2f(-3.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-1.5);
glVertex2f(-2.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-1.5);
glVertex2f(-1.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-1.5);
glVertex2f(-0.5,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-1.5);
glVertex2f(0.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-1.5);
glVertex2f(1.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-1.5);
glVertex2f(2.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-1.5);
glVertex2f(3.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-1.5);
glVertex2f(4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-1.5);
glVertex2f(4.9,-1.5);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.4,-.3);
glVertex2f(-4.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-.3);
glVertex2f(-3.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-.3);
glVertex2f(-2.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-.3);
glVertex2f(-1.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-.3);
glVertex2f(-0.5,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-.3);
glVertex2f(0.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-.3);
glVertex2f(1.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-.3);
glVertex2f(2.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-.3);
glVertex2f(3.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-.3);
glVertex2f(4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-.3);
glVertex2f(4.9,-.3);
glEnd();
////


    int ib;
    GLfloat radiusb =.12f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;

    int jb;
    GLfloat radb =.12f;
	int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;


	glColor3f(1.0f,1.0f,1.0f);

   GLfloat radi =.08f;



//pillar
glColor3ub(153, 153, 102);
	glBegin(GL_QUADS);
	glVertex2f(-4,.5);
	glVertex2f(-4,-.9);
	glVertex2f(-3.8,-.9);
	glVertex2f(-3.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,.5);
	glVertex2f(-2,-.9);
	glVertex2f(-1.8,-.9);
	glVertex2f(-1.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(0,.5);
	glVertex2f(0,-.9);
	glVertex2f(.2,-.9);
	glVertex2f(.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2,.5);
	glVertex2f(2,-.9);
	glVertex2f(2.2,-.9);
	glVertex2f(2.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4,.5);
	glVertex2f(4,-.9);
	glVertex2f(4.2,-.9);
	glVertex2f(4.2,.5);
	glEnd();

glColor3ub(123, 25, 25);
glBegin(GL_QUADS);
	glVertex2f(-5,.7);
	glVertex2f(-5,.4);
	glVertex2f(5,.4);
	glVertex2f(5,.7);
	glEnd();


///light 1

  glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
     glVertex2f(-3.0f,-0.9f);
    glVertex2f(-3.1f,-0.9f);
    glVertex2f(-3.1f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-3.0f,-0.4f);
    glVertex2f(-2.8f,-0.4f);
    glVertex2f(-2.8f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

   glBegin(GL_TRIANGLES);
    glVertex2f(-2.9f,-0.5f);
    glVertex2f(-2.7f,-0.5f);
    glVertex2f(-2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-2.9f,-0.9f);
    glVertex2f(-2.7f,-0.9f);
    glVertex2f(-2.8f,-0.5f);
    glEnd();




	///light 2

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.9f);
    glVertex2f(-1.1f,-0.9f);
    glVertex2f(-1.1f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(-0.8f,-0.4f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.8f,-0.4f);
    glEnd();


    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-0.9f,-0.9f);
    glVertex2f(-0.7f,-0.9f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();


	///light 3

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.9f);
    glVertex2f(1.1f,-0.9f);
    glVertex2f(1.1f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(0.8f,-0.4f);
    glVertex2f(0.8f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.8f,-0.4f);
    glEnd();



    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(0.9f,-0.9f);
    glVertex2f(0.7f,-0.9f);
    glVertex2f(0.8f,-0.5f);
    glEnd();

	///light 4
   glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.9f);
    glVertex2f(3.1f,-0.9f);
    glVertex2f(3.1f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.4f);
    glVertex2f(2.8f,-0.4f);
    glVertex2f(2.8f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(2.9f,-0.5f);
    glVertex2f(2.7f,-0.5f);
    glVertex2f(2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(2.9f,-0.9f);
    glVertex2f(2.7f,-0.9f);
    glVertex2f(2.8f,-0.5f);
    glEnd();



//soundCar();
	//train
glPushMatrix();
glTranslatef(positionTrain,0.0, 0.0f);

glColor3ub(25, 255, 255);
glBegin(GL_POLYGON);
	glVertex2f(-3,1.2);
	glVertex2f(-3.5,.7);
	glVertex2f(-3.5,.6);
	glVertex2f(-.8,.6);
	glVertex2f(-.8,1.2);
	glEnd();
glColor3ub(25, 25, 255);
glBegin(GL_QUADS);
	glVertex2f(-3.5,.7);
	glVertex2f(-3.5,.6);
	glVertex2f(-.8,.6);
	glVertex2f(-.8,.7);
	glEnd();
//glass of train
glColor3ub(25, 90, 215);
glBegin(GL_TRIANGLES);
	glVertex2f(-3,1.1);
	glVertex2f(-3.3,.8);
	glVertex2f(-3,.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.8,1.1);
	glVertex2f(-2.8,.7);
	glVertex2f(-2.5,.7);
	glVertex2f(-2.5,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.4,1.1);
	glVertex2f(-2.4,.8);
	glVertex2f(-2,.8);
	glVertex2f(-2,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-1.8,1.1);
	glVertex2f(-1.8,.7);
	glVertex2f(-1.5,.7);
	glVertex2f(-1.5,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-1.4,1.1);
	glVertex2f(-1.4,.8);
	glVertex2f(-1,.8);
	glVertex2f(-1,1.1);
	glEnd();
glPopMatrix();


////
//soundCar();
glPushMatrix();
glTranslatef(positionCar2,0.0, 0.0f);
//CAR2
  glBegin(GL_QUADS);
{
    glColor3ub(128, 0, 64);
    glVertex2f(0.3f,-1.2f);
    glVertex2f(0.3f,-1.5f);
    glVertex2f(-0.6f,-1.5f);
    glVertex2f(-0.6f,-1.2f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(0.6f, 0.8f, 1.0f); ///blue glass    (1/255)*X  {if its 153 then (1/255)*153}
    glVertex2f(0.15f,-1.2f);
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.45f,-1.2f);
    glEnd();
}
glLineWidth(1.2);
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.15f,-01.2f);
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.45f,-01.2f);
    glEnd();
}
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.35f,-01.2f);
    glVertex2f(0.0f,-01.2f);
    glEnd();
}

glColor3f(0.0f,0.0f,0.0f);
   GLfloat xbp=0.05f; GLfloat ybp=-1.5f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


	glColor3f(0.0f,0.0f,0.0f);
    GLfloat pbp=-0.35f; GLfloat qbp=-1.5f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();


	glColor3f(1.0f,1.0f,1.0f);
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radi * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();



   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();

//rain
//soundRain();
glPushMatrix();
glTranslatef(0,positionRain,0);
glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.5,4);
glVertex2f(4.5,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.8,4);
glVertex2f(4.8,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,4);
glVertex2f(0,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.3,4);
glVertex2f(.3,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.6,4);
glVertex2f(.6,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.9,4);
glVertex2f(.9,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(1.2,4);
glVertex2f(1.2,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.5,4);
glVertex2f(1.5,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.8,4);
glVertex2f(1.8,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.1,4);
glVertex2f(2.1,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.4,4);
glVertex2f(2.4,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.7,4);
glVertex2f(2.7,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3,4);
glVertex2f(3,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.3,4);
glVertex2f(3.3,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.6,4);
glVertex2f(3.6,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.9,4);
glVertex2f(3.9,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.2,4);
glVertex2f(4.2,3.8);
glEnd();

glVertex2f(4.5,4);
glVertex2f(4.5,3.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-4.5,4);
glVertex2f(-4.5,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,4);
glVertex2f(-4.8,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,4);
glVertex2f(0,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.3,4);
glVertex2f(-.3,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.6,4);
glVertex2f(-.6,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.9,4);
glVertex2f(-.9,3.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-1.2,4);
glVertex2f(-1.2,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.5,4);
glVertex2f(-1.5,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.8,4);
glVertex2f(-1.8,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.1,4);
glVertex2f(-2.1,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.4,4);
glVertex2f(-2.4,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.7,4);
glVertex2f(-2.7,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,4);
glVertex2f(-3,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,4);
glVertex2f(-3.3,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,4);
glVertex2f(-3.6,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,4);
glVertex2f(-3.9,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,4);
glVertex2f(-4.2,3.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.5,4);
glVertex2f(-4.5,3.8);
glEnd();



glBegin(GL_LINES);
glVertex2f(4.5,5);
glVertex2f(4.5,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.8,5);
glVertex2f(4.8,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,5);
glVertex2f(0,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.3,5);
glVertex2f(.3,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.6,5);
glVertex2f(.6,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.9,5);
glVertex2f(.9,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(1.2,5);
glVertex2f(1.2,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.5,5);
glVertex2f(1.5,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.8,5);
glVertex2f(1.8,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.1,5);
glVertex2f(2.1,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.4,5);
glVertex2f(2.4,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.7,5);
glVertex2f(2.7,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3,5);
glVertex2f(3,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.3,5);
glVertex2f(3.3,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.6,5);
glVertex2f(3.6,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.9,5);
glVertex2f(3.9,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.2,5);
glVertex2f(4.2,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.5,5);
glVertex2f(4.5,4.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-4.5,5);
glVertex2f(-4.5,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,5);
glVertex2f(-4.8,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,5);
glVertex2f(0,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.3,5);
glVertex2f(-.3,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.6,5);
glVertex2f(-.6,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.9,5);
glVertex2f(-.9,4.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-1.2,5);
glVertex2f(-1.2,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.5,5);
glVertex2f(-1.5,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.8,5);
glVertex2f(-1.8,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.1,5);
glVertex2f(-2.1,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.4,5);
glVertex2f(-2.4,4.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.7,6);
glVertex2f(-2.7,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,6);
glVertex2f(-3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,6);
glVertex2f(-3.3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,6);
glVertex2f(-3.6,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,6);
glVertex2f(-3.9,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,6);
glVertex2f(-4.2,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.5,6);
glVertex2f(-4.5,5.8);
glEnd();


glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.5,6);
glVertex2f(4.5,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.8,6);
glVertex2f(4.8,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,6);
glVertex2f(0,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.3,6);
glVertex2f(.3,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.6,6);
glVertex2f(.6,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.9,6);
glVertex2f(.9,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(1.2,6);
glVertex2f(1.2,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.5,6);
glVertex2f(1.5,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.8,6);
glVertex2f(1.8,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.1,6);
glVertex2f(2.1,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.4,6);
glVertex2f(2.4,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.7,6);
glVertex2f(2.7,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3,6);
glVertex2f(3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.3,6);
glVertex2f(3.3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.6,6);
glVertex2f(3.6,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.9,6);
glVertex2f(3.9,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.2,6);
glVertex2f(4.2,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.5,6);
glVertex2f(4.5,5.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-4.5,6);
glVertex2f(-4.5,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,6);
glVertex2f(-4.8,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,6);
glVertex2f(0,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.3,6);
glVertex2f(-.3,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.6,6);
glVertex2f(-.6,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.9,6);
glVertex2f(-.9,5.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-1.2,6);
glVertex2f(-1.2,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.5,6);
glVertex2f(-1.5,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.8,6);
glVertex2f(-1.8,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.1,6);
glVertex2f(-2.1,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.4,6);
glVertex2f(-2.4,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.7,6);
glVertex2f(-2.7,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,6);
glVertex2f(-3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,6);
glVertex2f(-3.3,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,6);
glVertex2f(-3.6,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,6);
glVertex2f(-3.9,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,6);
glVertex2f(-4.2,5.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.5,6);
glVertex2f(-4.5,5.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-2.7,7);
glVertex2f(-2.7,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,7);
glVertex2f(-3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,7);
glVertex2f(-3.3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,7);
glVertex2f(-3.6,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,7);
glVertex2f(-3.9,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,7);
glVertex2f(-4.2,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.5,7);
glVertex2f(-4.5,6.8);
glEnd();


glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.5,7);
glVertex2f(4.5,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.8,7);
glVertex2f(4.8,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,7);
glVertex2f(0,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.3,7);
glVertex2f(.3,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.6,7);
glVertex2f(.6,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.9,7);
glVertex2f(.9,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(1.2,7);
glVertex2f(1.2,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.5,7);
glVertex2f(1.5,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.8,7);
glVertex2f(1.8,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.1,7);
glVertex2f(2.1,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.4,7);
glVertex2f(2.4,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.7,7);
glVertex2f(2.7,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3,7);
glVertex2f(3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.3,7);
glVertex2f(3.3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.6,7);
glVertex2f(3.6,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.9,7);
glVertex2f(3.9,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.2,7);
glVertex2f(4.2,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.5,7);
glVertex2f(4.5,6.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-4.5,7);
glVertex2f(-4.5,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,7);
glVertex2f(-4.8,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,7);
glVertex2f(0,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.3,7);
glVertex2f(-.3,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.6,7);
glVertex2f(-.6,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.9,7);
glVertex2f(-.9,6.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-1.2,7);
glVertex2f(-1.2,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.5,7);
glVertex2f(-1.5,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.8,7);
glVertex2f(-1.8,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.1,7);
glVertex2f(-2.1,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.4,7);
glVertex2f(-2.4,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.7,7);
glVertex2f(-2.7,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,7);
glVertex2f(-3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,7);
glVertex2f(-3.3,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,7);
glVertex2f(-3.6,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,7);
glVertex2f(-3.9,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,7);
glVertex2f(-4.2,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.5,7);
glVertex2f(-4.5,6.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.8,7);
glVertex2f(-4.8,6.8);
glEnd();


////////////


glPushMatrix();
glTranslatef(0,positionRain,0);
glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.5,8);
glVertex2f(4.5,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(4.8,8);
glVertex2f(4.8,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,8);
glVertex2f(0,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.3,8);
glVertex2f(.3,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.6,8);
glVertex2f(.6,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(.9,8);
glVertex2f(.9,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(1.2,8);
glVertex2f(1.2,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.5,8);
glVertex2f(1.5,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(1.8,8);
glVertex2f(1.8,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.1,8);
glVertex2f(2.1,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.4,8);
glVertex2f(2.4,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(2.7,8);
glVertex2f(2.7,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3,8);
glVertex2f(3,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.3,8);
glVertex2f(3.3,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.6,8);
glVertex2f(3.6,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(3.9,8);
glVertex2f(3.9,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.2,8);
glVertex2f(4.2,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(4.5,8);
glVertex2f(4.5,7.8);
glEnd();


glBegin(GL_LINES);
glVertex2f(-4.5,8);
glVertex2f(-4.5,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,8);
glVertex2f(-4.8,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(0,8);
glVertex2f(0,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.3,8);
glVertex2f(-.3,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.6,8);
glVertex2f(-.6,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-.9,8);
glVertex2f(-.9,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-1.2,8);
glVertex2f(-1.2,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.5,8);
glVertex2f(-1.5,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-1.8,8);
glVertex2f(-1.8,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.1,8);
glVertex2f(-2.1,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.4,8);
glVertex2f(-2.4,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-2.7,8);
glVertex2f(-2.7,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3,8);
glVertex2f(-3,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.3,8);
glVertex2f(-3.3,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.6,8);
glVertex2f(-3.6,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-3.9,8);
glVertex2f(-3.9,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.2,8);
glVertex2f(-4.2,7.8);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.8,8);
glVertex2f(-4.5,7.8);
glEnd();



glBegin(GL_LINES);
glVertex2f(-4.5,8);
glVertex2f(-4.5,7.8);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-4.8,8);
glVertex2f(-4.8,7.8);
glEnd();


glPopMatrix();




	glFlush();

}





void displayNightToNight(int val) {

 glutDisplayFunc(displayNightVer2);

}





void displayNight() {
//soundCar();
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
gluOrtho2D(-5,5,-4,4);

//sky
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient[] = {0.0,0.0,2.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

glColor3ub(128, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,4);
	glVertex2f(-5,.5);
	glVertex2f(5,.5);
	glVertex2f(5,4);
	glEnd();
  glDisable(GL_LIGHTING);
	 int i1;
//Moon
glPushMatrix();
glTranslatef(0.0f,positionMoon, 0.0f);


	GLfloat x1=0; GLfloat y1=3; GLfloat radius1 =.4f;
	int triangleAmount = 100; //# of triangles used to draw circle


	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,230);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(positionCloud,0, 0.0f);
//clouds
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient2[] = {3.5,3.5,3.5, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
	GLfloat x2=-2.5; GLfloat y2=3.5; GLfloat radius2 =.3f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x2, y2); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x2 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x3=-2.9; GLfloat y3=3.3;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x3, y3); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x3 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y3 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x4=-2.65; GLfloat y4=2.95;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x4, y4); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x4 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y4 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x5=2; GLfloat y5=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x5 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y5 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x6=2.26; GLfloat y6=3.04;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x6, y6); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x6 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y6 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x7=1.8; GLfloat y7=3;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x7, y7); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x7 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y7 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x8=-2.2; GLfloat y8=3.2;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191,191,191);
		glVertex2f(x8, y8); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x8 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y8 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x9=1.6; GLfloat y9=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191, 191, 191);
		glVertex2f(x9, y9); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x9 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y9 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	glDisable(GL_LIGHTING);

	glPopMatrix();

//building
glColor3ub(255, 140, 26);
	glBegin(GL_QUADS);
	glVertex2f(-5,3);
	glVertex2f(-5,.5);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.9,3);
	glEnd();
glColor3ub(204, 102, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.9,3);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.7,.5);
	glVertex2f(-3.7,2.7);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(-4.85,2.8);
	glVertex2f(-4.85,2.4);
	glVertex2f(-4.5,2.4);
	glVertex2f(-4.5,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.4,2.8);
	glVertex2f(-4.4,2.4);
	glVertex2f(-4.05,2.4);
	glVertex2f(-4.05,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,2.2);
	glVertex2f(-4.85,1.8);
	glVertex2f(-4.5,1.8);
	glVertex2f(-4.5,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1.6);
	glVertex2f(-4.85,1.2);
	glVertex2f(-4.5,1.2);
	glVertex2f(-4.5,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1);
	glVertex2f(-4.85,.5);
	glVertex2f(-4.5,.5);
	glVertex2f(-4.5,1);
	glEnd();
	////
glColor3ub(204, 102, 153);
	glBegin(GL_QUADS);
	glVertex2f(-4.6,2.5);
	glVertex2f(-4.6,.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.5,2.5);
	glEnd();
glColor3ub(172, 57, 115);
	glBegin(GL_QUADS);
	glVertex2f(-3.5,2.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.3,.5);
	glVertex2f(-3.3,2.2);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(-4.45,2.3);
	glVertex2f(-4.45,1.9);
	glVertex2f(-4.1,1.9);
	glVertex2f(-4.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,2.3);
	glVertex2f(-4,1.9);
	glVertex2f(-3.65,1.9);
	glVertex2f(-3.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.7);
	glVertex2f(-4.45,1.3);
	glVertex2f(-4.1,1.3);
	glVertex2f(-4.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.7);
	glVertex2f(-4,1.3);
	glVertex2f(-3.65,1.3);
	glVertex2f(-3.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.1);
	glVertex2f(-4.45,.7);
	glVertex2f(-4.1,.7);
	glVertex2f(-4.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.1);
	glVertex2f(-4,.7);
	glVertex2f(-3.65,.7);
	glVertex2f(-3.65,1.1);
	glEnd();
	////
glColor3ub(178, 178, 102);
	glBegin(GL_QUADS);
	glVertex2f(-2.6,2.5);
	glVertex2f(-2.6,.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,2.5);
	glEnd();
glColor3ub(136, 136, 68);
	glBegin(GL_QUADS);
	glVertex2f(-1.5,2.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,2.2);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(-2.45,2.3);
	glVertex2f(-2.45,1.9);
	glVertex2f(-2.1,1.9);
	glVertex2f(-2.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,2.3);
	glVertex2f(-2,1.9);
	glVertex2f(-1.65,1.9);
	glVertex2f(-1.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.7);
	glVertex2f(-2.45,1.3);
	glVertex2f(-2.1,1.3);
	glVertex2f(-2.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.7);
	glVertex2f(-2,1.3);
	glVertex2f(-1.65,1.3);
	glVertex2f(-1.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.1);
	glVertex2f(-2.45,.7);
	glVertex2f(-2.1,.7);
	glVertex2f(-2.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.1);
	glVertex2f(-2,.7);
	glVertex2f(-1.65,.7);
	glVertex2f(-1.65,1.1);
	glEnd();

	////
glColor3ub(204, 102, 204);
	glBegin(GL_QUADS);
	glVertex2f(-3.25,2);
	glVertex2f(-3.25,.5);
	glVertex2f(-2.2,.5);
	glVertex2f(-2.2,2);
	glEnd();
glColor3ub(191, 64, 191);
	glBegin(GL_QUADS);
	glVertex2f(-2.2,2);
	glVertex2f(-2.2,.5);
	glVertex2f(-2,.5);
	glVertex2f(-2,1.7);
	glEnd();
////windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(-3.15,1.8);
	glVertex2f(-3.15,1.4);
	glVertex2f(-2.8,1.4);
	glVertex2f(-2.8,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.8);
	glVertex2f(-2.7,1.4);
	glVertex2f(-2.35,1.4);
	glVertex2f(-2.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-3.15,1.2);
	glVertex2f(-3.15,.8);
	glVertex2f(-2.8,.8);
	glVertex2f(-2.8,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.2);
	glVertex2f(-2.7,.8);
	glVertex2f(-2.35,.8);
	glVertex2f(-2.35,1.2);
	glEnd();

	////
glColor3ub(102, 153, 153);
	glBegin(GL_QUADS);
	glVertex2f(-1.1,2.5);
	glVertex2f(-1.1,.5);
	glVertex2f(0,.5);
	glVertex2f(0,2.5);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(0,2.5);
	glVertex2f(0,.5);
	glVertex2f(.2,.5);
	glVertex2f(.2,2.2);
	glEnd();

//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(-.95,2.3);
	glVertex2f(-.95,1.9);
	glVertex2f(-.6,1.9);
	glVertex2f(-.6,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,2.3);
	glVertex2f(-.5,1.9);
	glVertex2f(-.15,1.9);
	glVertex2f(-.15,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.7);
	glVertex2f(-.95,1.3);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.3);
	glVertex2f(-.15,1.3);
	glVertex2f(-.15,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.1);
	glVertex2f(-.95,.7);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5,.7);
	glVertex2f(-.15,.7);
	glVertex2f(-.15,1.1);
	glEnd();
////
glColor3ub(133, 133, 173);
	glBegin(GL_QUADS);
	glVertex2f(.4,2);
	glVertex2f(.4,.5);
	glVertex2f(1.5,.5);
	glVertex2f(1.5,2);
	glEnd();
////windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(.55,1.8);
	glVertex2f(.55,1.4);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.8);
	glVertex2f(1,1.4);
	glVertex2f(1.35,1.4);
	glVertex2f(1.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(.55,1.2);
	glVertex2f(.55,.8);
	glVertex2f(.9,.8);
	glVertex2f(.9,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.2);
	glVertex2f(1,.8);
	glVertex2f(1.35,.8);
	glVertex2f(1.35,1.2);
	glEnd();

////
glColor3ub(71, 107, 107);
	glBegin(GL_QUADS);
	glVertex2f(1.7,2.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,3);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(1.9,3);
	glVertex2f(1.9,.5);
	glVertex2f(3,.5);
	glVertex2f(3,3);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(2.05,2.8);
	glVertex2f(2.05,2.4);
	glVertex2f(2.4,2.4);
	glVertex2f(2.4,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.8);
	glVertex2f(2.5,2.4);
	glVertex2f(2.85,2.4);
	glVertex2f(2.85,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,2.2);
	glVertex2f(2.05,1.8);
	glVertex2f(2.4,1.8);
	glVertex2f(2.4,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.2);
	glVertex2f(2.5,1.8);
	glVertex2f(2.85,1.8);
	glVertex2f(2.85,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1.6);
	glVertex2f(2.05,1.2);
	glVertex2f(2.4,1.2);
	glVertex2f(2.4,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1.6);
	glVertex2f(2.5,1.2);
	glVertex2f(2.85,1.2);
	glVertex2f(2.85,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1);
	glVertex2f(2.05,.5);
	glVertex2f(2.4,.5);
	glVertex2f(2.4,1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1);
	glVertex2f(2.5,.5);
	glVertex2f(2.85,.5);
	glVertex2f(2.85,1);
	glEnd();

////
glColor3ub(0, 134, 179);
	glBegin(GL_QUADS);
	glVertex2f(3.8,3.2);
	glVertex2f(3.8,.5);
	glVertex2f(4,.5);
	glVertex2f(4,3.5);
	glEnd();
glColor3ub(0, 153, 204);
	glBegin(GL_QUADS);
	glVertex2f(4,3.5);
	glVertex2f(4,.5);
	glVertex2f(5,.5);
	glVertex2f(5,3.5);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(4.15,3.3);
	glVertex2f(4.15,2.9);
	glVertex2f(4.5,2.9);
	glVertex2f(4.5,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,3.3);
	glVertex2f(4.6,2.9);
	glVertex2f(4.95,2.9);
	glVertex2f(4.95,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.7);
	glVertex2f(4.15,2.3);
	glVertex2f(4.5,2.3);
	glVertex2f(4.5,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.7);
	glVertex2f(4.6,2.3);
	glVertex2f(4.95,2.3);
	glVertex2f(4.95,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.1);
	glVertex2f(4.15,1.7);
	glVertex2f(4.5,1.7);
	glVertex2f(4.5,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.1);
	glVertex2f(4.6,1.7);
	glVertex2f(4.95,1.7);
	glVertex2f(4.95,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,1.5);
	glVertex2f(4.15,1.1);
	glVertex2f(4.5,1.1);
	glVertex2f(4.5,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,1.5);
	glVertex2f(4.6,1.1);
	glVertex2f(4.95,1.1);
	glVertex2f(4.95,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,.9);
	glVertex2f(4.15,.7);
	glVertex2f(4.5,.7);
	glVertex2f(4.5,.9);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,.9);
	glVertex2f(4.6,.7);
	glVertex2f(4.95,.7);
	glVertex2f(4.95,.9);
	glEnd();
////
glColor3ub(122, 122, 82);
	glBegin(GL_QUADS);
	glVertex2f(3.1,2.2);
	glVertex2f(3.1,.5);
	glVertex2f(3.3,.5);
	glVertex2f(3.3,2.5);
	glEnd();
glColor3ub(138, 138, 92);
	glBegin(GL_QUADS);
	glVertex2f(3.3,2.5);
	glVertex2f(3.3,.5);
	glVertex2f(4.4,.5);
	glVertex2f(4.4,2.5);
	glEnd();
//windows
glColor3ub(255,255,0);
	glBegin(GL_QUADS);
	glVertex2f(3.45,2.3);
	glVertex2f(3.45,1.9);
	glVertex2f(3.8,1.9);
	glVertex2f(3.8,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,2.3);
	glVertex2f(3.9,1.9);
	glVertex2f(4.25,1.9);
	glVertex2f(4.25,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.7);
	glVertex2f(3.45,1.3);
	glVertex2f(3.8,1.3);
	glVertex2f(3.8,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.7);
	glVertex2f(3.9,1.3);
	glVertex2f(4.25,1.3);
	glVertex2f(4.25,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.1);
	glVertex2f(3.45,.7);
	glVertex2f(3.8,.7);
	glVertex2f(3.8,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.1);
	glVertex2f(3.9,.7);
	glVertex2f(4.25,.7);
	glVertex2f(4.25,1.1);
	glEnd();




//river
glEnable(GL_LIGHTING);//Enable Light Effect
  GLfloat global_ambient1[] = {0.0,0.0,3.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);


glColor3ub(26, 198, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2.3);
	glVertex2f(-5,-4);
	glVertex2f(5,-4);
	glVertex2f(5,-2.3);
	glEnd();

glDisable(GL_LIGHTING);



//road
glColor3ub(61, 61, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,.2);
	glVertex2f(-5,-2);
	glVertex2f(5,-2);
	glVertex2f(5,.2);
	glEnd();

//divider
glColor3ub(61, 0, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,-.8);
	glVertex2f(-5,-1);
	glVertex2f(5,-1);
	glVertex2f(5,-.8);
	glEnd();

glColor3ub(255,255,255);
	glBegin(GL_QUADS);
	glVertex2f(-5,.4);
	glVertex2f(-5,.2);
	glVertex2f(-4.5,.2);
	glVertex2f(-4.5,.4);
	glEnd();
glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-4.5,.4);
	glVertex2f(-4.5,.2);
	glVertex2f(-4,.2);
	glVertex2f(-4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-3.5,.4);
	glVertex2f(-3.5,.2);
	glVertex2f(-3,.2);
	glVertex2f(-3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.5,.4);
	glVertex2f(-2.5,.2);
	glVertex2f(-2,.2);
	glVertex2f(-2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-1.5,.4);
	glVertex2f(-1.5,.2);
	glVertex2f(-1,.2);
	glVertex2f(-1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-.5,.4);
	glVertex2f(-.5,.2);
	glVertex2f(0,.2);
	glVertex2f(0,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(.5,.4);
	glVertex2f(.5,.2);
	glVertex2f(1,.2);
	glVertex2f(1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(1.5,.4);
	glVertex2f(1.5,.2);
	glVertex2f(2,.2);
	glVertex2f(2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.5,.4);
	glVertex2f(2.5,.2);
	glVertex2f(3,.2);
	glVertex2f(3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(3.5,.4);
	glVertex2f(3.5,.2);
	glVertex2f(4,.2);
	glVertex2f(4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4.5,.4);
	glVertex2f(4.5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();

//border of river
glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2);
	glVertex2f(-5,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(-4,-2);
	glVertex2f(-4,-2.3);
	glVertex2f(-3,-2.3);
	glVertex2f(-3,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2,-2);
	glVertex2f(-2,-2.3);
	glVertex2f(-1,-2.3);
	glVertex2f(-1,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(0,-2);
	glVertex2f(0,-2.3);
	glVertex2f(1,-2.3);
	glVertex2f(1,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2,-2);
	glVertex2f(2,-2.3);
	glVertex2f(3,-2.3);
	glVertex2f(3,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4,-2);
	glVertex2f(4,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();

glLineWidth(5.5);
glColor3ub(255, 255, 255);

glBegin(GL_LINES);
glVertex2f(-4.4,-1.5);
glVertex2f(-4.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-1.5);
glVertex2f(-3.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-1.5);
glVertex2f(-2.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-1.5);
glVertex2f(-1.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-1.5);
glVertex2f(-0.5,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-1.5);
glVertex2f(0.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-1.5);
glVertex2f(1.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-1.5);
glVertex2f(2.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-1.5);
glVertex2f(3.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-1.5);
glVertex2f(4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-1.5);
glVertex2f(4.9,-1.5);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.4,-.3);
glVertex2f(-4.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-.3);
glVertex2f(-3.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-.3);
glVertex2f(-2.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-.3);
glVertex2f(-1.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-.3);
glVertex2f(-0.5,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-.3);
glVertex2f(0.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-.3);
glVertex2f(1.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-.3);
glVertex2f(2.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-.3);
glVertex2f(3.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-.3);
glVertex2f(4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-.3);
glVertex2f(4.9,-.3);
glEnd();
////
glPushMatrix();
glTranslatef(positionCar1,0.0, 0.0f);
//CAR1
  glBegin(GL_QUADS);
{
    glColor3f(1.0f,0.0f,0.0f); //red
    glVertex2f(0.3f,-.2f);
    glVertex2f(0.3f,-0.5f);
    glVertex2f(-0.6f,-0.5f);
    glVertex2f(-0.6f,-.2f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(0.6f, 0.8f, 1.0f); ///blue glass    (1/255)*X  {if its 153 then (1/255)*153}
    glVertex2f(0.15f,-0.2f);
    glVertex2f(0.0f,0.02f);
    glVertex2f(-0.35f,0.02f);
    glVertex2f(-0.45f,-0.2f);
    glEnd();
}
glLineWidth(1.2);
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.15f,-0.2f);
    glVertex2f(0.0f,0.02f);
    glVertex2f(-0.35f,0.02f);
    glVertex2f(-0.45f,-0.2f);
    glEnd();
}
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.0f,0.02f);
    glVertex2f(-0.35f,0.02f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(0.0f,-0.2f);
    glEnd();
}

glColor3f(0.0f,0.0f,0.0f);
    int ib;
    GLfloat xb=0.05f; GLfloat yb=-.5f; GLfloat radiusb =.12f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


	glColor3f(0.0f,0.0f,0.0f);
    int jb;
    GLfloat pb=-0.35f; GLfloat qb=-0.5f; GLfloat radb =.12f;
	int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);

   GLfloat radi =.09f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radi * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();



   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();

//pillar
glColor3ub(153, 153, 102);
	glBegin(GL_QUADS);
	glVertex2f(-4,.5);
	glVertex2f(-4,-.9);
	glVertex2f(-3.8,-.9);
	glVertex2f(-3.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,.5);
	glVertex2f(-2,-.9);
	glVertex2f(-1.8,-.9);
	glVertex2f(-1.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(0,.5);
	glVertex2f(0,-.9);
	glVertex2f(.2,-.9);
	glVertex2f(.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2,.5);
	glVertex2f(2,-.9);
	glVertex2f(2.2,-.9);
	glVertex2f(2.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4,.5);
	glVertex2f(4,-.9);
	glVertex2f(4.2,-.9);
	glVertex2f(4.2,.5);
	glEnd();

glColor3ub(123, 25, 25);
glBegin(GL_QUADS);
	glVertex2f(-5,.7);
	glVertex2f(-5,.4);
	glVertex2f(5,.4);
	glVertex2f(5,.7);
	glEnd();

////

////light 1

  glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
     glVertex2f(-3.0f,-0.9f);
    glVertex2f(-3.1f,-0.9f);
    glVertex2f(-3.1f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-3.0f,-0.4f);
    glVertex2f(-2.8f,-0.4f);
    glVertex2f(-2.8f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

   glBegin(GL_TRIANGLES);
    glVertex2f(-2.9f,-0.5f);
    glVertex2f(-2.7f,-0.5f);
    glVertex2f(-2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-2.9f,-0.9f);
    glVertex2f(-2.7f,-0.9f);
    glVertex2f(-2.8f,-0.5f);
    glEnd();




	////light 2

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.9f);
    glVertex2f(-1.1f,-0.9f);
    glVertex2f(-1.1f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(-0.8f,-0.4f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.8f,-0.4f);
    glEnd();


    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-0.9f,-0.9f);
    glVertex2f(-0.7f,-0.9f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();


	////light 3

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.9f);
    glVertex2f(1.1f,-0.9f);
    glVertex2f(1.1f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(0.8f,-0.4f);
    glVertex2f(0.8f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.8f,-0.4f);
    glEnd();



    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(0.9f,-0.9f);
    glVertex2f(0.7f,-0.9f);
    glVertex2f(0.8f,-0.5f);
    glEnd();

	////light 4
   glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.9f);
    glVertex2f(3.1f,-0.9f);
    glVertex2f(3.1f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.4f);
    glVertex2f(2.8f,-0.4f);
    glVertex2f(2.8f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(2.9f,-0.5f);
    glVertex2f(2.7f,-0.5f);
    glVertex2f(2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(2.9f,-0.9f);
    glVertex2f(2.7f,-0.9f);
    glVertex2f(2.8f,-0.5f);
    glEnd();






///Bus
glPushMatrix();
glTranslatef(positionBus,0.0, 0.0f);
  glBegin(GL_QUADS);
    glColor3ub(179, 255, 102);
    glVertex2f(3.0f,-1.8f);
    glVertex2f(4.5f,-1.8f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(3.0f,-1.6f);
    glEnd();

   glBegin(GL_QUADS);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(4.5f,-1.1f);
    glVertex2f(3.2f,-1.1f);
    glEnd();

     glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.4f,-1.6f);
    glVertex2f(3.55f,-1.6f);
    glVertex2f(3.55f,-1.3f);
    glVertex2f(3.4f,-1.3f);
    glEnd();

         glBegin(GL_QUADS);
    glVertex2f(3.6f,-1.6f);
    glVertex2f(3.8f,-1.6f);
    glVertex2f(3.8f,-1.4f);
    glVertex2f(3.6f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.6f);
    glVertex2f(4.1f,-1.6f);
    glVertex2f(4.1f,-1.4f);
    glVertex2f(3.9f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.6f);
    glVertex2f(4.4f,-1.6f);
    glVertex2f(4.4f,-1.4f);
    glVertex2f(4.2f,-1.4f);
    glEnd();

////

     glBegin(GL_QUADS);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.5f,-1.2f);
    glVertex2f(3.5f,-1.2f);
    glEnd();

         glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.6f,-1.3f);
    glVertex2f(3.8f,-1.3f);
    glVertex2f(3.8f,-1.2f);
    glVertex2f(3.6f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.3f);
    glVertex2f(4.1f,-1.3f);
    glVertex2f(4.1f,-1.2f);
    glVertex2f(3.9f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.3f);
    glVertex2f(4.4f,-1.3f);
    glVertex2f(4.4f,-1.2f);
    glVertex2f(4.2f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(230, 255, 255);
    glVertex2f(3.0f,-1.6f);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.0f,-1.4f);
    glEnd();

       glBegin(GL_TRIANGLES);
    glVertex2f(3.0f,-1.4f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.2f,-1.1f);
   glEnd();


     glBegin(GL_QUADS);
   glColor3ub(1,0,0);
    glVertex2f(3.1f,-1.7f);
    glVertex2f(3.3f,-1.7f);
    glVertex2f(3.3f,-1.4f);
    glVertex2f(3.1f,-1.4f);
    glEnd();

   ///wheel
glColor3f(0,0,0);
   GLfloat xbpr=3.4f; GLfloat ybpr=-1.8f,radbw=.13,radiw=.09;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radbw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radbw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0,0,0);

    GLfloat pbpt=4.2f; GLfloat qbpt=-1.8f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radbw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radbw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1,1,1);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radiw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radiw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radiw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radiw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();
	glPopMatrix();


glPushMatrix();
glTranslatef(positionBoat1,0,0);
//boat
glColor3ub(12,134,143);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(2.5,-2.8);
	glVertex2f(2.7,-3.2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.8,-3);
	glVertex2f(2.7,-3.2);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.5,-3);
	glEnd();

	glBegin(GL_TRIANGLES);
     glVertex2f(3.5,-3);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.8,-2.8);
    glEnd();

glColor3ub(12,13,13);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(3,-3);
	glVertex2f(2.9,-2.7);
	glEnd();
glColor3ub(12,153,13);
    glBegin(GL_QUADS);
    glVertex2f(2.9,-2.7);
	glVertex2f(3,-3);
	glVertex2f(3.5,-3);
    glVertex2f(3.4,-2.7);
	glEnd();
glPopMatrix();

glutTimerFunc(7450,displayNightToNight,0);
	glFlush();

}

















void displayDayToNight(int val) {

 glutDisplayFunc(displayNight);

}



void displayNoon() {
//soundCar();
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
gluOrtho2D(-5,5,-4,4);

//sky
glColor3ub(128, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,4);
	glVertex2f(-5,.5);
	glVertex2f(5,.5);
	glVertex2f(5,4);
	glEnd();

	 int i1;
//sun
glPushMatrix();
glTranslatef(0.0f,positionSun, 0.0f);


	GLfloat x1=0; GLfloat y1=4; GLfloat radius1 =.4f;
	int triangleAmount = 100; //# of triangles used to draw circle


	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(positionCloud,0.0f, 0.0f);

//clouds
	GLfloat x2=-2.5; GLfloat y2=3.5; GLfloat radius2 =.3f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x2, y2); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x2 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x3=-2.9; GLfloat y3=3.3;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x3, y3); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x3 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y3 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x4=-2.65; GLfloat y4=2.95;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,245);
		glVertex2f(x4, y4); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x4 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y4 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x5=2; GLfloat y5=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x5 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y5 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x6=2.26; GLfloat y6=3.04;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x6, y6); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x6 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y6 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x7=1.8; GLfloat y7=3;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,245);
		glVertex2f(x7, y7); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x7 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y7 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x8=-2.2; GLfloat y8=3.2;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x8, y8); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x8 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y8 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x9=1.6; GLfloat y9=3.4;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250,255,253);
		glVertex2f(x9, y9); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x9 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y9 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();
//building
glColor3ub(255, 140, 26);
	glBegin(GL_QUADS);
	glVertex2f(-5,3);
	glVertex2f(-5,.5);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.9,3);
	glEnd();
glColor3ub(204, 102, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.9,3);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.7,.5);
	glVertex2f(-3.7,2.7);
	glEnd();
//windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(-4.85,2.8);
	glVertex2f(-4.85,2.4);
	glVertex2f(-4.5,2.4);
	glVertex2f(-4.5,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.4,2.8);
	glVertex2f(-4.4,2.4);
	glVertex2f(-4.05,2.4);
	glVertex2f(-4.05,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,2.2);
	glVertex2f(-4.85,1.8);
	glVertex2f(-4.5,1.8);
	glVertex2f(-4.5,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1.6);
	glVertex2f(-4.85,1.2);
	glVertex2f(-4.5,1.2);
	glVertex2f(-4.5,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1);
	glVertex2f(-4.85,.5);
	glVertex2f(-4.5,.5);
	glVertex2f(-4.5,1);
	glEnd();
	////
glColor3ub(204, 102, 153);
	glBegin(GL_QUADS);
	glVertex2f(-4.6,2.5);
	glVertex2f(-4.6,.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.5,2.5);
	glEnd();
glColor3ub(172, 57, 115);
	glBegin(GL_QUADS);
	glVertex2f(-3.5,2.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.3,.5);
	glVertex2f(-3.3,2.2);
	glEnd();
//windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(-4.45,2.3);
	glVertex2f(-4.45,1.9);
	glVertex2f(-4.1,1.9);
	glVertex2f(-4.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,2.3);
	glVertex2f(-4,1.9);
	glVertex2f(-3.65,1.9);
	glVertex2f(-3.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.7);
	glVertex2f(-4.45,1.3);
	glVertex2f(-4.1,1.3);
	glVertex2f(-4.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.7);
	glVertex2f(-4,1.3);
	glVertex2f(-3.65,1.3);
	glVertex2f(-3.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.1);
	glVertex2f(-4.45,.7);
	glVertex2f(-4.1,.7);
	glVertex2f(-4.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.1);
	glVertex2f(-4,.7);
	glVertex2f(-3.65,.7);
	glVertex2f(-3.65,1.1);
	glEnd();
	////
glColor3ub(178, 178, 102);
	glBegin(GL_QUADS);
	glVertex2f(-2.6,2.5);
	glVertex2f(-2.6,.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,2.5);
	glEnd();
glColor3ub(136, 136, 68);
	glBegin(GL_QUADS);
	glVertex2f(-1.5,2.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,2.2);
	glEnd();
//windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(-2.45,2.3);
	glVertex2f(-2.45,1.9);
	glVertex2f(-2.1,1.9);
	glVertex2f(-2.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,2.3);
	glVertex2f(-2,1.9);
	glVertex2f(-1.65,1.9);
	glVertex2f(-1.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.7);
	glVertex2f(-2.45,1.3);
	glVertex2f(-2.1,1.3);
	glVertex2f(-2.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.7);
	glVertex2f(-2,1.3);
	glVertex2f(-1.65,1.3);
	glVertex2f(-1.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.1);
	glVertex2f(-2.45,.7);
	glVertex2f(-2.1,.7);
	glVertex2f(-2.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.1);
	glVertex2f(-2,.7);
	glVertex2f(-1.65,.7);
	glVertex2f(-1.65,1.1);
	glEnd();

	////
glColor3ub(204, 102, 204);
	glBegin(GL_QUADS);
	glVertex2f(-3.25,2);
	glVertex2f(-3.25,.5);
	glVertex2f(-2.2,.5);
	glVertex2f(-2.2,2);
	glEnd();
glColor3ub(191, 64, 191);
	glBegin(GL_QUADS);
	glVertex2f(-2.2,2);
	glVertex2f(-2.2,.5);
	glVertex2f(-2,.5);
	glVertex2f(-2,1.7);
	glEnd();
////windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(-3.15,1.8);
	glVertex2f(-3.15,1.4);
	glVertex2f(-2.8,1.4);
	glVertex2f(-2.8,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.8);
	glVertex2f(-2.7,1.4);
	glVertex2f(-2.35,1.4);
	glVertex2f(-2.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-3.15,1.2);
	glVertex2f(-3.15,.8);
	glVertex2f(-2.8,.8);
	glVertex2f(-2.8,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.2);
	glVertex2f(-2.7,.8);
	glVertex2f(-2.35,.8);
	glVertex2f(-2.35,1.2);
	glEnd();

	////
glColor3ub(102, 153, 153);
	glBegin(GL_QUADS);
	glVertex2f(-1.1,2.5);
	glVertex2f(-1.1,.5);
	glVertex2f(0,.5);
	glVertex2f(0,2.5);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(0,2.5);
	glVertex2f(0,.5);
	glVertex2f(.2,.5);
	glVertex2f(.2,2.2);
	glEnd();

//windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(-.95,2.3);
	glVertex2f(-.95,1.9);
	glVertex2f(-.6,1.9);
	glVertex2f(-.6,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,2.3);
	glVertex2f(-.5,1.9);
	glVertex2f(-.15,1.9);
	glVertex2f(-.15,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.7);
	glVertex2f(-.95,1.3);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.3);
	glVertex2f(-.15,1.3);
	glVertex2f(-.15,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.1);
	glVertex2f(-.95,.7);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5,.7);
	glVertex2f(-.15,.7);
	glVertex2f(-.15,1.1);
	glEnd();
////
glColor3ub(133, 133, 173);
	glBegin(GL_QUADS);
	glVertex2f(.4,2);
	glVertex2f(.4,.5);
	glVertex2f(1.5,.5);
	glVertex2f(1.5,2);
	glEnd();
////windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(.55,1.8);
	glVertex2f(.55,1.4);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.8);
	glVertex2f(1,1.4);
	glVertex2f(1.35,1.4);
	glVertex2f(1.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(.55,1.2);
	glVertex2f(.55,.8);
	glVertex2f(.9,.8);
	glVertex2f(.9,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.2);
	glVertex2f(1,.8);
	glVertex2f(1.35,.8);
	glVertex2f(1.35,1.2);
	glEnd();

////
glColor3ub(71, 107, 107);
	glBegin(GL_QUADS);
	glVertex2f(1.7,2.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,3);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(1.9,3);
	glVertex2f(1.9,.5);
	glVertex2f(3,.5);
	glVertex2f(3,3);
	glEnd();
//windows
glColor3ub(250, 250, 250);
	glBegin(GL_QUADS);
	glVertex2f(2.05,2.8);
	glVertex2f(2.05,2.4);
	glVertex2f(2.4,2.4);
	glVertex2f(2.4,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.8);
	glVertex2f(2.5,2.4);
	glVertex2f(2.85,2.4);
	glVertex2f(2.85,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,2.2);
	glVertex2f(2.05,1.8);
	glVertex2f(2.4,1.8);
	glVertex2f(2.4,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.2);
	glVertex2f(2.5,1.8);
	glVertex2f(2.85,1.8);
	glVertex2f(2.85,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1.6);
	glVertex2f(2.05,1.2);
	glVertex2f(2.4,1.2);
	glVertex2f(2.4,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1.6);
	glVertex2f(2.5,1.2);
	glVertex2f(2.85,1.2);
	glVertex2f(2.85,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1);
	glVertex2f(2.05,.5);
	glVertex2f(2.4,.5);
	glVertex2f(2.4,1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1);
	glVertex2f(2.5,.5);
	glVertex2f(2.85,.5);
	glVertex2f(2.85,1);
	glEnd();

////
glColor3ub(0, 134, 179);
	glBegin(GL_QUADS);
	glVertex2f(3.8,3.2);
	glVertex2f(3.8,.5);
	glVertex2f(4,.5);
	glVertex2f(4,3.5);
	glEnd();
glColor3ub(0, 153, 204);
	glBegin(GL_QUADS);
	glVertex2f(4,3.5);
	glVertex2f(4,.5);
	glVertex2f(5,.5);
	glVertex2f(5,3.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(4.15,3.3);
	glVertex2f(4.15,2.9);
	glVertex2f(4.5,2.9);
	glVertex2f(4.5,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,3.3);
	glVertex2f(4.6,2.9);
	glVertex2f(4.95,2.9);
	glVertex2f(4.95,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.7);
	glVertex2f(4.15,2.3);
	glVertex2f(4.5,2.3);
	glVertex2f(4.5,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.7);
	glVertex2f(4.6,2.3);
	glVertex2f(4.95,2.3);
	glVertex2f(4.95,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.1);
	glVertex2f(4.15,1.7);
	glVertex2f(4.5,1.7);
	glVertex2f(4.5,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.1);
	glVertex2f(4.6,1.7);
	glVertex2f(4.95,1.7);
	glVertex2f(4.95,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,1.5);
	glVertex2f(4.15,1.1);
	glVertex2f(4.5,1.1);
	glVertex2f(4.5,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,1.5);
	glVertex2f(4.6,1.1);
	glVertex2f(4.95,1.1);
	glVertex2f(4.95,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,.9);
	glVertex2f(4.15,.7);
	glVertex2f(4.5,.7);
	glVertex2f(4.5,.9);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,.9);
	glVertex2f(4.6,.7);
	glVertex2f(4.95,.7);
	glVertex2f(4.95,.9);
	glEnd();
////
glColor3ub(122, 122, 82);
	glBegin(GL_QUADS);
	glVertex2f(3.1,2.2);
	glVertex2f(3.1,.5);
	glVertex2f(3.3,.5);
	glVertex2f(3.3,2.5);
	glEnd();
glColor3ub(138, 138, 92);
	glBegin(GL_QUADS);
	glVertex2f(3.3,2.5);
	glVertex2f(3.3,.5);
	glVertex2f(4.4,.5);
	glVertex2f(4.4,2.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(3.45,2.3);
	glVertex2f(3.45,1.9);
	glVertex2f(3.8,1.9);
	glVertex2f(3.8,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,2.3);
	glVertex2f(3.9,1.9);
	glVertex2f(4.25,1.9);
	glVertex2f(4.25,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.7);
	glVertex2f(3.45,1.3);
	glVertex2f(3.8,1.3);
	glVertex2f(3.8,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.7);
	glVertex2f(3.9,1.3);
	glVertex2f(4.25,1.3);
	glVertex2f(4.25,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.1);
	glVertex2f(3.45,.7);
	glVertex2f(3.8,.7);
	glVertex2f(3.8,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.1);
	glVertex2f(3.9,.7);
	glVertex2f(4.25,.7);
	glVertex2f(4.25,1.1);
	glEnd();


////


//river
glColor3ub(26, 198, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2.3);
	glVertex2f(-5,-4);
	glVertex2f(5,-4);
	glVertex2f(5,-2.3);
	glEnd();





//road
glColor3ub(61, 61, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,.2);
	glVertex2f(-5,-2);
	glVertex2f(5,-2);
	glVertex2f(5,.2);
	glEnd();

//divider
glColor3ub(61, 0, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,-.8);
	glVertex2f(-5,-1);
	glVertex2f(5,-1);
	glVertex2f(5,-.8);
	glEnd();

glColor3ub(255,255,255);
	glBegin(GL_QUADS);
	glVertex2f(-5,.4);
	glVertex2f(-5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();
glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-4.5,.4);
	glVertex2f(-4.5,.2);
	glVertex2f(-4,.2);
	glVertex2f(-4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-3.5,.4);
	glVertex2f(-3.5,.2);
	glVertex2f(-3,.2);
	glVertex2f(-3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.5,.4);
	glVertex2f(-2.5,.2);
	glVertex2f(-2,.2);
	glVertex2f(-2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-1.5,.4);
	glVertex2f(-1.5,.2);
	glVertex2f(-1,.2);
	glVertex2f(-1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-.5,.4);
	glVertex2f(-.5,.2);
	glVertex2f(0,.2);
	glVertex2f(0,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(.5,.4);
	glVertex2f(.5,.2);
	glVertex2f(1,.2);
	glVertex2f(1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(1.5,.4);
	glVertex2f(1.5,.2);
	glVertex2f(2,.2);
	glVertex2f(2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.5,.4);
	glVertex2f(2.5,.2);
	glVertex2f(3,.2);
	glVertex2f(3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(3.5,.4);
	glVertex2f(3.5,.2);
	glVertex2f(4,.2);
	glVertex2f(4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4.5,.4);
	glVertex2f(4.5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();

//border of river
glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2);
	glVertex2f(-5,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(-4,-2);
	glVertex2f(-4,-2.3);
	glVertex2f(-3,-2.3);
	glVertex2f(-3,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-2,-2);
	glVertex2f(-2,-2.3);
	glVertex2f(-1,-2.3);
	glVertex2f(-1,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0,-2);
	glVertex2f(0,-2.3);
	glVertex2f(1,-2.3);
	glVertex2f(1,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2,-2);
	glVertex2f(2,-2.3);
	glVertex2f(3,-2.3);
	glVertex2f(3,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4,-2);
	glVertex2f(4,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();

glLineWidth(5.5);
glColor3ub(255, 255, 255);

glBegin(GL_LINES);
glVertex2f(-4.4,-1.5);
glVertex2f(-4.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-1.5);
glVertex2f(-3.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-1.5);
glVertex2f(-2.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-1.5);
glVertex2f(-1.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-1.5);
glVertex2f(-0.5,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-1.5);
glVertex2f(0.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-1.5);
glVertex2f(1.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-1.5);
glVertex2f(2.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-1.5);
glVertex2f(3.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-1.5);
glVertex2f(4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-1.5);
glVertex2f(4.9,-1.5);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.4,-.3);
glVertex2f(-4.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-.3);
glVertex2f(-3.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-.3);
glVertex2f(-2.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-.3);
glVertex2f(-1.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-.3);
glVertex2f(-0.5,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-.3);
glVertex2f(0.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-.3);
glVertex2f(1.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-.3);
glVertex2f(2.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-.3);
glVertex2f(3.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-.3);
glVertex2f(4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-.3);
glVertex2f(4.9,-.3);
glEnd();
////
glPushMatrix();
glTranslatef(positionCar1,0.0, 0.0f);
//CAR1
  glBegin(GL_QUADS);
{
    glColor3f(1.0f,0.0f,0.0f); //red
    glVertex2f(0.3f,0.1f);
    glVertex2f(0.3f,-0.2f);
    glVertex2f(-0.6f,-0.2f);
    glVertex2f(-0.6f,0.1f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(0.6f, 0.8f, 1.0f); ///blue glass    (1/255)*X  {if its 153 then (1/255)*153}
    glVertex2f(0.15f,0.1f);
    glVertex2f(0.0f,0.32f);
    glVertex2f(-0.35f,0.32f);
    glVertex2f(-0.45f,0.1f);
    glEnd();
}
glLineWidth(1.2);
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.15f,0.1f);
    glVertex2f(0.0f,0.32f);
    glVertex2f(-0.35f,0.32f);
    glVertex2f(-0.45f,0.1f);
    glEnd();
}
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.0f,0.32f);
    glVertex2f(-0.35f,0.32f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(0.0f,0.1f);
    glEnd();
}

glColor3f(0.0f,0.0f,0.0f);
    int ib;
    GLfloat xb=0.05f; GLfloat yb=-.2f; GLfloat radiusb =.12f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
    int jb;
    GLfloat pb=-0.35f; GLfloat qb=-0.2f; GLfloat radb =.12f;
	int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);

   GLfloat radi =.08f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xb + (radi * cos(ib *  twicePib / triangleAmountb)),
			    yb + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();



   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pb, qb);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pb + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qb + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();



glPushMatrix();
glTranslatef(positionNCar1,0.0, 0.0f);

///new car
 glColor3ub(120, 0, 0);
 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.5f);
    glVertex2f(4.5f,-0.5f);
    glVertex2f(4.5f,-0.4f);
    glVertex2f(3.0f,-0.4f);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2f(3.2f,-0.4f);
    glVertex2f(4.3f,-0.4f);
    glVertex2f(4.3f,-0.1f);
    glVertex2f(3.2f,-0.1f);
    glEnd();

      glBegin(GL_TRIANGLES);
    glVertex2f(4.3f,-0.4f);
    glVertex2f(4.5f,-0.4f);
    glVertex2f(4.3f,-0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
   glVertex2f(3.0f,-0.4f);
    glVertex2f(3.2f,-0.4f);
    glVertex2f(3.2f,-0.3f);
    glEnd();

    glColor3ub(0, 51, 0);
    glBegin(GL_QUADS);
    glVertex2f(3.3f,-0.3f);
    glVertex2f(3.6f,-0.3f);
    glVertex2f(3.6f,-0.15f);
    glVertex2f(3.3f,-0.15f);
    glEnd();

       glBegin(GL_QUADS);
    glVertex2f(3.7f,-0.3f);
    glVertex2f(4.0f,-0.3f);
    glVertex2f(4.0f,-0.15f);
    glVertex2f(3.7f,-0.15f);
    glEnd();


       glBegin(GL_QUADS);
    glVertex2f(4.1f,-0.3f);
    glVertex2f(4.3f,-0.3f);
    glVertex2f(4.3f,-0.15f);
    glVertex2f(4.1f,-0.15f);
    glEnd();



   ///wheel
glColor3f(0,0,0);
   GLfloat xbprz=3.4f; GLfloat ybprz=-0.5f,radbwz=.12,radiwz=.08;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbprz, ybprz);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbprz + (radbwz * cos(ib *  twicePib / triangleAmountb)),
			    ybprz + (radbwz * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0,0,0);

    GLfloat pbptz=4.2f; GLfloat qbptz=-0.5f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbptz, qbptz);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbptz + (radbwz * cos(jb *  twicepib / triangleAmtb)),
			    qbptz + (radbwz * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1,1,1);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbprz, ybprz);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbprz + (radiwz * cos(ib *  twicePib / triangleAmountb)),
			    ybprz + (radiwz * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbptz, qbptz);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbptz + (radiwz * cos(jb *  twicepib / triangleAmtb)),
			    qbptz + (radiwz * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();


glPopMatrix();


//pillar
glColor3ub(153, 153, 102);
	glBegin(GL_QUADS);
	glVertex2f(-4,.5);
	glVertex2f(-4,-.9);
	glVertex2f(-3.8,-.9);
	glVertex2f(-3.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,.5);
	glVertex2f(-2,-.9);
	glVertex2f(-1.8,-.9);
	glVertex2f(-1.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(0,.5);
	glVertex2f(0,-.9);
	glVertex2f(.2,-.9);
	glVertex2f(.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2,.5);
	glVertex2f(2,-.9);
	glVertex2f(2.2,-.9);
	glVertex2f(2.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4,.5);
	glVertex2f(4,-.9);
	glVertex2f(4.2,-.9);
	glVertex2f(4.2,.5);
	glEnd();

glColor3ub(123, 25, 25);
glBegin(GL_QUADS);
	glVertex2f(-5,.7);
	glVertex2f(-5,.4);
	glVertex2f(5,.4);
	glVertex2f(5,.7);
	glEnd();

////


///light 1

  glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
     glVertex2f(-3.0f,-0.9f);
    glVertex2f(-3.1f,-0.9f);
    glVertex2f(-3.1f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-3.0f,-0.4f);
    glVertex2f(-2.8f,-0.4f);
    glVertex2f(-2.8f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

   glBegin(GL_TRIANGLES);
    glVertex2f(-2.9f,-0.5f);
    glVertex2f(-2.7f,-0.5f);
    glVertex2f(-2.8f,-0.4f);
    glEnd();




	///light 2

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.9f);
    glVertex2f(-1.1f,-0.9f);
    glVertex2f(-1.1f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(-0.8f,-0.4f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.8f,-0.4f);
    glEnd();


	///light 3

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.9f);
    glVertex2f(1.1f,-0.9f);
    glVertex2f(1.1f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(0.8f,-0.4f);
    glVertex2f(0.8f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.8f,-0.4f);
    glEnd();





	///light 4
   glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.9f);
    glVertex2f(3.1f,-0.9f);
    glVertex2f(3.1f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.4f);
    glVertex2f(2.8f,-0.4f);
    glVertex2f(2.8f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(2.9f,-0.5f);
    glVertex2f(2.7f,-0.5f);
    glVertex2f(2.8f,-0.4f);
    glEnd();







glPushMatrix();
glTranslatef(positionCar2,0.0, 0.0f);
//CAR2
  glBegin(GL_QUADS);
{
    glColor3f(1.0f,0.67f,0.0f);
    glVertex2f(0.3f,-1.0f);
    glVertex2f(0.3f,-1.3f);
    glVertex2f(-0.6f,-1.3f);
    glVertex2f(-0.6f,-1.0f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(0.6f, 0.8f, 1.0f); ///blue glass    (1/255)*X  {if its 153 then (1/255)*153}
    glVertex2f(0.15f,-1.0f);
    glVertex2f(0.0f,-.80f);
    glVertex2f(-0.35f,-.80f);
    glVertex2f(-0.45f,-1.0f);
    glEnd();
}
glLineWidth(1.2);
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.15f,-01.0f);
    glVertex2f(0.0f,-.80f);
    glVertex2f(-0.35f,-.80f);
    glVertex2f(-0.45f,-01.0f);
    glEnd();
}
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.0f,-.80f);
    glVertex2f(-0.35f,-.80f);
    glVertex2f(-0.35f,-01.0f);
    glVertex2f(0.0f,-01.0f);
    glEnd();
}

glColor3f(0.0f,0.0f,0.0f);
   GLfloat xbp=0.05f; GLfloat ybp=-1.3f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
    GLfloat pbp=-0.35f; GLfloat qbp=-1.3f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radi * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();




///Bus
glPushMatrix();
glTranslatef(positionBus,0.0, 0.0f);
  glBegin(GL_QUADS);
    glColor3ub(179, 255, 102);
    glVertex2f(3.0f,-1.8f);
    glVertex2f(4.5f,-1.8f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(3.0f,-1.6f);
    glEnd();

   glBegin(GL_QUADS);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(4.5f,-1.1f);
    glVertex2f(3.2f,-1.1f);
    glEnd();

     glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.4f,-1.6f);
    glVertex2f(3.55f,-1.6f);
    glVertex2f(3.55f,-1.3f);
    glVertex2f(3.4f,-1.3f);
    glEnd();

         glBegin(GL_QUADS);
    glVertex2f(3.6f,-1.6f);
    glVertex2f(3.8f,-1.6f);
    glVertex2f(3.8f,-1.4f);
    glVertex2f(3.6f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.6f);
    glVertex2f(4.1f,-1.6f);
    glVertex2f(4.1f,-1.4f);
    glVertex2f(3.9f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.6f);
    glVertex2f(4.4f,-1.6f);
    glVertex2f(4.4f,-1.4f);
    glVertex2f(4.2f,-1.4f);
    glEnd();

////

     glBegin(GL_QUADS);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.5f,-1.2f);
    glVertex2f(3.5f,-1.2f);
    glEnd();

         glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.6f,-1.3f);
    glVertex2f(3.8f,-1.3f);
    glVertex2f(3.8f,-1.2f);
    glVertex2f(3.6f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.3f);
    glVertex2f(4.1f,-1.3f);
    glVertex2f(4.1f,-1.2f);
    glVertex2f(3.9f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.3f);
    glVertex2f(4.4f,-1.3f);
    glVertex2f(4.4f,-1.2f);
    glVertex2f(4.2f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(230, 255, 255);
    glVertex2f(3.0f,-1.6f);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.0f,-1.4f);
    glEnd();

       glBegin(GL_TRIANGLES);
    glVertex2f(3.0f,-1.4f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.2f,-1.1f);
   glEnd();


     glBegin(GL_QUADS);
   glColor3ub(1,0,0);
    glVertex2f(3.1f,-1.7f);
    glVertex2f(3.3f,-1.7f);
    glVertex2f(3.3f,-1.4f);
    glVertex2f(3.1f,-1.4f);
    glEnd();

   ///wheel
glColor3f(0,0,0);
   GLfloat xbpr=3.4f; GLfloat ybpr=-1.8f,radbw=.13,radiw=.09;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radbw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radbw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0,0,0);

    GLfloat pbpt=4.2f; GLfloat qbpt=-1.8f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radbw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radbw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1,1,1);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbpr, ybpr);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbpr + (radiw * cos(ib *  twicePib / triangleAmountb)),
			    ybpr + (radiw * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbpt, qbpt);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbpt + (radiw * cos(jb *  twicepib / triangleAmtb)),
			    qbpt + (radiw * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();
	glPopMatrix();





//train
glPushMatrix();
glTranslatef(positionTrain,0.0, 0.0f);

glColor3ub(25, 255, 255);
glBegin(GL_POLYGON);
	glVertex2f(-3,1.2);
	glVertex2f(-3.5,.7);
	glVertex2f(-3.5,.6);
	glVertex2f(-.8,.6);
	glVertex2f(-.8,1.2);
	glEnd();
glColor3ub(25, 25, 255);
glBegin(GL_QUADS);
	glVertex2f(-3.5,.7);
	glVertex2f(-3.5,.6);
	glVertex2f(-.8,.6);
	glVertex2f(-.8,.7);
	glEnd();
//glass of train
glColor3ub(25, 90, 215);
glBegin(GL_TRIANGLES);
	glVertex2f(-3,1.1);
	glVertex2f(-3.3,.8);
	glVertex2f(-3,.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.8,1.1);
	glVertex2f(-2.8,.7);
	glVertex2f(-2.5,.7);
	glVertex2f(-2.5,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.4,1.1);
	glVertex2f(-2.4,.8);
	glVertex2f(-2,.8);
	glVertex2f(-2,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-1.8,1.1);
	glVertex2f(-1.8,.7);
	glVertex2f(-1.5,.7);
	glVertex2f(-1.5,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-1.4,1.1);
	glVertex2f(-1.4,.8);
	glVertex2f(-1,.8);
	glVertex2f(-1,1.1);
	glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(positionBoat,0.0, 0.0f);
//boat
glColor3ub(12,134,143);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(2.5,-2.8);
	glVertex2f(2.7,-3.2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.8,-3);
	glVertex2f(2.7,-3.2);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.5,-3);
	glEnd();

	glBegin(GL_TRIANGLES);
     glVertex2f(3.5,-3);
	glVertex2f(3.6,-3.2);
	glVertex2f(3.8,-2.8);
    glEnd();

glColor3ub(12,13,13);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.8,-3);
	glVertex2f(3,-3);
	glVertex2f(2.9,-2.7);
	glEnd();
glColor3ub(12,153,13);
    glBegin(GL_QUADS);
    glVertex2f(2.9,-2.7);
	glVertex2f(3,-3);
	glVertex2f(3.5,-3);
    glVertex2f(3.4,-2.7);
	glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(positionBoat1,0.0, 0.0f);

////boat2
glColor3ub(12,134,143);
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.8,-2.5);
	glVertex2f(-2.5,-2.3);
	glVertex2f(-2.7,-2.7);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.8,-2.5);
	glVertex2f(-2.7,-2.7);
	glVertex2f(-3.6,-2.7);
	glVertex2f(-3.5,-2.5);
	glEnd();

	glBegin(GL_TRIANGLES);
     glVertex2f(-3.5,-2.5);
	glVertex2f(-3.6,-2.7);
	glVertex2f(-3.8,-2.3);
    glEnd();

glColor3ub(12,13,13);
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.8,-2.5);
	glVertex2f(-3,-2.5);
	glVertex2f(-2.9,-2.2);
	glEnd();
glColor3ub(12,153,13);
    glBegin(GL_QUADS);
    glVertex2f(-2.9,-2.2);
	glVertex2f(-3,-2.5);
	glVertex2f(-3.5,-2.5);
    glVertex2f(-3.4,-2.2);
	glEnd();

	glPopMatrix();
glutTimerFunc(6000,displayDayToNight,0);
	glFlush();

}






void displayMorningToNoon(int value)
{
    glutDisplayFunc(displayNoon);
}









void displayMorning() {

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
gluOrtho2D(-5,5,-4,4);


//sky
glColor3ub(153, 187, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,4);
	glVertex2f(-5,.5);
	glVertex2f(5,.5);
	glVertex2f(5,4);
	glEnd();



//building
glColor3ub(255, 140, 26);
	glBegin(GL_QUADS);
	glVertex2f(-5,3);
	glVertex2f(-5,.5);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.9,3);
	glEnd();
glColor3ub(204, 102, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.9,3);
	glVertex2f(-3.9,.5);
	glVertex2f(-3.7,.5);
	glVertex2f(-3.7,2.7);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-4.85,2.8);
	glVertex2f(-4.85,2.4);
	glVertex2f(-4.5,2.4);
	glVertex2f(-4.5,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.4,2.8);
	glVertex2f(-4.4,2.4);
	glVertex2f(-4.05,2.4);
	glVertex2f(-4.05,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,2.2);
	glVertex2f(-4.85,1.8);
	glVertex2f(-4.5,1.8);
	glVertex2f(-4.5,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1.6);
	glVertex2f(-4.85,1.2);
	glVertex2f(-4.5,1.2);
	glVertex2f(-4.5,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.85,1);
	glVertex2f(-4.85,.5);
	glVertex2f(-4.5,.5);
	glVertex2f(-4.5,1);
	glEnd();
	////
glColor3ub(204, 102, 153);
	glBegin(GL_QUADS);
	glVertex2f(-4.6,2.5);
	glVertex2f(-4.6,.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.5,2.5);
	glEnd();
glColor3ub(172, 57, 115);
	glBegin(GL_QUADS);
	glVertex2f(-3.5,2.5);
	glVertex2f(-3.5,.5);
	glVertex2f(-3.3,.5);
	glVertex2f(-3.3,2.2);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-4.45,2.3);
	glVertex2f(-4.45,1.9);
	glVertex2f(-4.1,1.9);
	glVertex2f(-4.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,2.3);
	glVertex2f(-4,1.9);
	glVertex2f(-3.65,1.9);
	glVertex2f(-3.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.7);
	glVertex2f(-4.45,1.3);
	glVertex2f(-4.1,1.3);
	glVertex2f(-4.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.7);
	glVertex2f(-4,1.3);
	glVertex2f(-3.65,1.3);
	glVertex2f(-3.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4.45,1.1);
	glVertex2f(-4.45,.7);
	glVertex2f(-4.1,.7);
	glVertex2f(-4.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-4,1.1);
	glVertex2f(-4,.7);
	glVertex2f(-3.65,.7);
	glVertex2f(-3.65,1.1);
	glEnd();
	////
glColor3ub(178, 178, 102);
	glBegin(GL_QUADS);
	glVertex2f(-2.6,2.5);
	glVertex2f(-2.6,.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,2.5);
	glEnd();
glColor3ub(136, 136, 68);
	glBegin(GL_QUADS);
	glVertex2f(-1.5,2.5);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,2.2);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-2.45,2.3);
	glVertex2f(-2.45,1.9);
	glVertex2f(-2.1,1.9);
	glVertex2f(-2.1,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,2.3);
	glVertex2f(-2,1.9);
	glVertex2f(-1.65,1.9);
	glVertex2f(-1.65,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.7);
	glVertex2f(-2.45,1.3);
	glVertex2f(-2.1,1.3);
	glVertex2f(-2.1,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.7);
	glVertex2f(-2,1.3);
	glVertex2f(-1.65,1.3);
	glVertex2f(-1.65,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.45,1.1);
	glVertex2f(-2.45,.7);
	glVertex2f(-2.1,.7);
	glVertex2f(-2.1,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,1.1);
	glVertex2f(-2,.7);
	glVertex2f(-1.65,.7);
	glVertex2f(-1.65,1.1);
	glEnd();

	////
glColor3ub(204, 102, 204);
	glBegin(GL_QUADS);
	glVertex2f(-3.25,2);
	glVertex2f(-3.25,.5);
	glVertex2f(-2.2,.5);
	glVertex2f(-2.2,2);
	glEnd();
glColor3ub(191, 64, 191);
	glBegin(GL_QUADS);
	glVertex2f(-2.2,2);
	glVertex2f(-2.2,.5);
	glVertex2f(-2,.5);
	glVertex2f(-2,1.7);
	glEnd();
////windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-3.15,1.8);
	glVertex2f(-3.15,1.4);
	glVertex2f(-2.8,1.4);
	glVertex2f(-2.8,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.8);
	glVertex2f(-2.7,1.4);
	glVertex2f(-2.35,1.4);
	glVertex2f(-2.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-3.15,1.2);
	glVertex2f(-3.15,.8);
	glVertex2f(-2.8,.8);
	glVertex2f(-2.8,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2.7,1.2);
	glVertex2f(-2.7,.8);
	glVertex2f(-2.35,.8);
	glVertex2f(-2.35,1.2);
	glEnd();

	////
glColor3ub(102, 153, 153);
	glBegin(GL_QUADS);
	glVertex2f(-1.1,2.5);
	glVertex2f(-1.1,.5);
	glVertex2f(0,.5);
	glVertex2f(0,2.5);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(0,2.5);
	glVertex2f(0,.5);
	glVertex2f(.2,.5);
	glVertex2f(.2,2.2);
	glEnd();

//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-.95,2.3);
	glVertex2f(-.95,1.9);
	glVertex2f(-.6,1.9);
	glVertex2f(-.6,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,2.3);
	glVertex2f(-.5,1.9);
	glVertex2f(-.15,1.9);
	glVertex2f(-.15,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.7);
	glVertex2f(-.95,1.3);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.3);
	glVertex2f(-.15,1.3);
	glVertex2f(-.15,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.95,1.1);
	glVertex2f(-.95,.7);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5,.7);
	glVertex2f(-.15,.7);
	glVertex2f(-.15,1.1);
	glEnd();
////
glColor3ub(133, 133, 173);
	glBegin(GL_QUADS);
	glVertex2f(.4,2);
	glVertex2f(.4,.5);
	glVertex2f(1.5,.5);
	glVertex2f(1.5,2);
	glEnd();
////windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(.55,1.8);
	glVertex2f(.55,1.4);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.8);
	glVertex2f(1,1.4);
	glVertex2f(1.35,1.4);
	glVertex2f(1.35,1.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(.55,1.2);
	glVertex2f(.55,.8);
	glVertex2f(.9,.8);
	glVertex2f(.9,1.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(1,1.2);
	glVertex2f(1,.8);
	glVertex2f(1.35,.8);
	glVertex2f(1.35,1.2);
	glEnd();

////
glColor3ub(71, 107, 107);
	glBegin(GL_QUADS);
	glVertex2f(1.7,2.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,3);
	glEnd();
glColor3ub(82, 122, 122);
	glBegin(GL_QUADS);
	glVertex2f(1.9,3);
	glVertex2f(1.9,.5);
	glVertex2f(3,.5);
	glVertex2f(3,3);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(2.05,2.8);
	glVertex2f(2.05,2.4);
	glVertex2f(2.4,2.4);
	glVertex2f(2.4,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.8);
	glVertex2f(2.5,2.4);
	glVertex2f(2.85,2.4);
	glVertex2f(2.85,2.8);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,2.2);
	glVertex2f(2.05,1.8);
	glVertex2f(2.4,1.8);
	glVertex2f(2.4,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,2.2);
	glVertex2f(2.5,1.8);
	glVertex2f(2.85,1.8);
	glVertex2f(2.85,2.2);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1.6);
	glVertex2f(2.05,1.2);
	glVertex2f(2.4,1.2);
	glVertex2f(2.4,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1.6);
	glVertex2f(2.5,1.2);
	glVertex2f(2.85,1.2);
	glVertex2f(2.85,1.6);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.05,1);
	glVertex2f(2.05,.5);
	glVertex2f(2.4,.5);
	glVertex2f(2.4,1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2.5,1);
	glVertex2f(2.5,.5);
	glVertex2f(2.85,.5);
	glVertex2f(2.85,1);
	glEnd();

////
glColor3ub(0, 134, 179);
	glBegin(GL_QUADS);
	glVertex2f(3.8,3.2);
	glVertex2f(3.8,.5);
	glVertex2f(4,.5);
	glVertex2f(4,3.5);
	glEnd();
glColor3ub(0, 153, 204);
	glBegin(GL_QUADS);
	glVertex2f(4,3.5);
	glVertex2f(4,.5);
	glVertex2f(5,.5);
	glVertex2f(5,3.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(4.15,3.3);
	glVertex2f(4.15,2.9);
	glVertex2f(4.5,2.9);
	glVertex2f(4.5,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,3.3);
	glVertex2f(4.6,2.9);
	glVertex2f(4.95,2.9);
	glVertex2f(4.95,3.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.7);
	glVertex2f(4.15,2.3);
	glVertex2f(4.5,2.3);
	glVertex2f(4.5,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.7);
	glVertex2f(4.6,2.3);
	glVertex2f(4.95,2.3);
	glVertex2f(4.95,2.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,2.1);
	glVertex2f(4.15,1.7);
	glVertex2f(4.5,1.7);
	glVertex2f(4.5,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,2.1);
	glVertex2f(4.6,1.7);
	glVertex2f(4.95,1.7);
	glVertex2f(4.95,2.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,1.5);
	glVertex2f(4.15,1.1);
	glVertex2f(4.5,1.1);
	glVertex2f(4.5,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,1.5);
	glVertex2f(4.6,1.1);
	glVertex2f(4.95,1.1);
	glVertex2f(4.95,1.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.15,.9);
	glVertex2f(4.15,.7);
	glVertex2f(4.5,.7);
	glVertex2f(4.5,.9);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4.6,.9);
	glVertex2f(4.6,.7);
	glVertex2f(4.95,.7);
	glVertex2f(4.95,.9);
	glEnd();
////
glColor3ub(122, 122, 82);
	glBegin(GL_QUADS);
	glVertex2f(3.1,2.2);
	glVertex2f(3.1,.5);
	glVertex2f(3.3,.5);
	glVertex2f(3.3,2.5);
	glEnd();
glColor3ub(138, 138, 92);
	glBegin(GL_QUADS);
	glVertex2f(3.3,2.5);
	glVertex2f(3.3,.5);
	glVertex2f(4.4,.5);
	glVertex2f(4.4,2.5);
	glEnd();
//windows
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(3.45,2.3);
	glVertex2f(3.45,1.9);
	glVertex2f(3.8,1.9);
	glVertex2f(3.8,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,2.3);
	glVertex2f(3.9,1.9);
	glVertex2f(4.25,1.9);
	glVertex2f(4.25,2.3);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.7);
	glVertex2f(3.45,1.3);
	glVertex2f(3.8,1.3);
	glVertex2f(3.8,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.7);
	glVertex2f(3.9,1.3);
	glVertex2f(4.25,1.3);
	glVertex2f(4.25,1.7);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.45,1.1);
	glVertex2f(3.45,.7);
	glVertex2f(3.8,.7);
	glVertex2f(3.8,1.1);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(3.9,1.1);
	glVertex2f(3.9,.7);
	glVertex2f(4.25,.7);
	glVertex2f(4.25,1.1);
	glEnd();

//river
glColor3ub(35, 200, 255);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2.3);
	glVertex2f(-5,-4);
	glVertex2f(5,-4);
	glVertex2f(5,-2.3);
	glEnd();





//road
glColor3ub(61, 61, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,.2);
	glVertex2f(-5,-2);
	glVertex2f(5,-2);
	glVertex2f(5,.2);
	glEnd();


//divider
glColor3ub(61, 0, 92);
	glBegin(GL_QUADS);
	glVertex2f(-5,-.8);
	glVertex2f(-5,-1);
	glVertex2f(5,-1);
	glVertex2f(5,-.8);
	glEnd();

glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-5,.4);
	glVertex2f(-5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();
glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-4.5,.4);
	glVertex2f(-4.5,.2);
	glVertex2f(-4,.2);
	glVertex2f(-4,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-3.5,.4);
	glVertex2f(-3.5,.2);
	glVertex2f(-3,.2);
	glVertex2f(-3,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-2.5,.4);
	glVertex2f(-2.5,.2);
	glVertex2f(-2,.2);
	glVertex2f(-2,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-1.5,.4);
	glVertex2f(-1.5,.2);
	glVertex2f(-1,.2);
	glVertex2f(-1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-.5,.4);
	glVertex2f(-.5,.2);
	glVertex2f(0,.2);
	glVertex2f(0,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(.5,.4);
	glVertex2f(.5,.2);
	glVertex2f(1,.2);
	glVertex2f(1,.4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(1.5,.4);
	glVertex2f(1.5,.2);
	glVertex2f(2,.2);
	glVertex2f(2,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(2.5,.4);
	glVertex2f(2.5,.2);
	glVertex2f(3,.2);
	glVertex2f(3,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(3.5,.4);
	glVertex2f(3.5,.2);
	glVertex2f(4,.2);
	glVertex2f(4,.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(4.5,.4);
	glVertex2f(4.5,.2);
	glVertex2f(5,.2);
	glVertex2f(5,.4);
	glEnd();

//border of river
glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2f(-5,-2);
	glVertex2f(-5,-2.3);
	glVertex2f(4,-2.3);
	glVertex2f(4,-2);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(-4,-2);
	glVertex2f(-4,-2.3);
	glVertex2f(-3,-2.3);
	glVertex2f(-3,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-2,-2);
	glVertex2f(-2,-2.3);
	glVertex2f(-1,-2.3);
	glVertex2f(-1,-2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(0,-2);
	glVertex2f(0,-2.3);
	glVertex2f(1,-2.3);
	glVertex2f(1,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2,-2);
	glVertex2f(2,-2.3);
	glVertex2f(3,-2.3);
	glVertex2f(3,-2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(4,-2);
	glVertex2f(4,-2.3);
	glVertex2f(5,-2.3);
	glVertex2f(5,-2);
	glEnd();

glLineWidth(5.5);
glColor3ub(220, 220, 220);

glBegin(GL_LINES);
glVertex2f(-4.4,-1.5);
glVertex2f(-4.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-1.5);
glVertex2f(-3.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-1.5);
glVertex2f(-2.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-1.5);
glVertex2f(-1.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-1.5);
glVertex2f(-0.5,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-1.5);
glVertex2f(0.4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-1.5);
glVertex2f(1.3,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-1.5);
glVertex2f(2.2,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-1.5);
glVertex2f(3.1,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-1.5);
glVertex2f(4,-1.5);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-1.5);
glVertex2f(4.9,-1.5);
glEnd();

glBegin(GL_LINES);
glVertex2f(-4.4,-.3);
glVertex2f(-4.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-3.5,-.3);
glVertex2f(-3.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-2.6,-.3);
glVertex2f(-2.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-1.7,-.3);
glVertex2f(-1.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(-0.8,-.3);
glVertex2f(-0.5,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(0.1,-.3);
glVertex2f(0.4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1,-.3);
glVertex2f(1.3,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(1.9,-.3);
glVertex2f(2.2,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(2.8,-.3);
glVertex2f(3.1,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(3.7,-.3);
glVertex2f(4,-.3);
glEnd();
glBegin(GL_LINES);
glVertex2f(4.6,-.3);
glVertex2f(4.9,-.3);
glEnd();
////

int ib;
    GLfloat radiusb =.12f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;

    int jb;
    GLfloat radb =.12f;
	int triangleAmtb = 20;
	GLfloat twicepib = 2.0f * PI;


	glColor3f(1.0f,1.0f,1.0f);

   GLfloat radi =.08f;


   glPushMatrix();
   glTranslatef(positionNCar1,0,0);
///new car
 glColor3ub(120, 0, 0);
 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.5f);
    glVertex2f(4.5f,-0.5f);
    glVertex2f(4.5f,-0.4f);
    glVertex2f(3.0f,-0.4f);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2f(3.2f,-0.4f);
    glVertex2f(4.3f,-0.4f);
    glVertex2f(4.3f,-0.1f);
    glVertex2f(3.2f,-0.1f);
    glEnd();

      glBegin(GL_TRIANGLES);
    glVertex2f(4.3f,-0.4f);
    glVertex2f(4.5f,-0.4f);
    glVertex2f(4.3f,-0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
   glVertex2f(3.0f,-0.4f);
    glVertex2f(3.2f,-0.4f);
    glVertex2f(3.2f,-0.3f);
    glEnd();

    glColor3ub(0, 51, 0);
    glBegin(GL_QUADS);
    glVertex2f(3.3f,-0.3f);
    glVertex2f(3.6f,-0.3f);
    glVertex2f(3.6f,-0.15f);
    glVertex2f(3.3f,-0.15f);
    glEnd();

       glBegin(GL_QUADS);
    glVertex2f(3.7f,-0.3f);
    glVertex2f(4.0f,-0.3f);
    glVertex2f(4.0f,-0.15f);
    glVertex2f(3.7f,-0.15f);
    glEnd();


       glBegin(GL_QUADS);
    glVertex2f(4.1f,-0.3f);
    glVertex2f(4.3f,-0.3f);
    glVertex2f(4.3f,-0.15f);
    glVertex2f(4.1f,-0.15f);
    glEnd();



   ///wheel
glColor3f(0,0,0);
   GLfloat xbprz=3.4f; GLfloat ybprz=-0.5f,radbwz=.12,radiwz=.08;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbprz, ybprz);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbprz + (radbwz * cos(ib *  twicePib / triangleAmountb)),
			    ybprz + (radbwz * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0,0,0);

    GLfloat pbptz=4.2f; GLfloat qbptz=-0.5f;

   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbptz, qbptz);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbptz + (radbwz * cos(jb *  twicepib / triangleAmtb)),
			    qbptz + (radbwz * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1,1,1);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbprz, ybprz);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbprz + (radiwz * cos(ib *  twicePib / triangleAmountb)),
			    ybprz + (radiwz * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbptz, qbptz);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbptz + (radiwz * cos(jb *  twicepib / triangleAmtb)),
			    qbptz + (radiwz * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();


glPopMatrix();

//pillar
glColor3ub(153, 153, 102);
	glBegin(GL_QUADS);
	glVertex2f(-4,.5);
	glVertex2f(-4,-.9);
	glVertex2f(-3.8,-.9);
	glVertex2f(-3.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(-2,.5);
	glVertex2f(-2,-.9);
	glVertex2f(-1.8,-.9);
	glVertex2f(-1.8,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(0,.5);
	glVertex2f(0,-.9);
	glVertex2f(.2,-.9);
	glVertex2f(.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(2,.5);
	glVertex2f(2,-.9);
	glVertex2f(2.2,-.9);
	glVertex2f(2.2,.5);
	glEnd();
glBegin(GL_QUADS);
	glVertex2f(4,.5);
	glVertex2f(4,-.9);
	glVertex2f(4.2,-.9);
	glVertex2f(4.2,.5);
	glEnd();

glColor3ub(123, 25, 25);
glBegin(GL_QUADS);
	glVertex2f(-5,.7);
	glVertex2f(-5,.4);
	glVertex2f(5,.4);
	glVertex2f(5,.7);
	glEnd();

////

///light 1

  glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
     glVertex2f(-3.0f,-0.9f);
    glVertex2f(-3.1f,-0.9f);
    glVertex2f(-3.1f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-3.0f,-0.4f);
    glVertex2f(-2.8f,-0.4f);
    glVertex2f(-2.8f,-0.3f);
    glVertex2f(-3.0f,-0.3f);
    glEnd();

   glBegin(GL_TRIANGLES);
    glVertex2f(-2.9f,-0.5f);
    glVertex2f(-2.7f,-0.5f);
    glVertex2f(-2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-2.9f,-0.9f);
    glVertex2f(-2.7f,-0.9f);
    glVertex2f(-2.8f,-0.5f);
    glEnd();




	///light 2

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.9f);
    glVertex2f(-1.1f,-0.9f);
    glVertex2f(-1.1f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(-0.8f,-0.4f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-1.0f,-0.3f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.8f,-0.4f);
    glEnd();


    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(-0.9f,-0.9f);
    glVertex2f(-0.7f,-0.9f);
    glVertex2f(-0.8f,-0.5f);
    glEnd();


	///light 3

	glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.9f);
    glVertex2f(1.1f,-0.9f);
    glVertex2f(1.1f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(0.8f,-0.4f);
    glVertex2f(0.8f,-0.3f);
    glVertex2f(1.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.8f,-0.4f);
    glEnd();



    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(0.9f,-0.9f);
    glVertex2f(0.7f,-0.9f);
    glVertex2f(0.8f,-0.5f);
    glEnd();

	///light 4
   glColor3ub(214, 214, 194);
	 glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.9f);
    glVertex2f(3.1f,-0.9f);
    glVertex2f(3.1f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();

        glBegin(GL_QUADS);
    glVertex2f(3.0f,-0.4f);
    glVertex2f(2.8f,-0.4f);
    glVertex2f(2.8f,-0.3f);
    glVertex2f(3.0f,-0.3f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(2.9f,-0.5f);
    glVertex2f(2.7f,-0.5f);
    glVertex2f(2.8f,-0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255, 255, 0);
    glVertex2f(2.9f,-0.9f);
    glVertex2f(2.7f,-0.9f);
    glVertex2f(2.8f,-0.5f);
    glEnd();



////
glPushMatrix();
glTranslatef(positionCar2,0.0, 0.0f);



//CAR2
  glBegin(GL_QUADS);
{
    glColor3f(1.0f,0.67f,0.0f);
    glVertex2f(0.3f,-1.2f);
    glVertex2f(0.3f,-1.5f);
    glVertex2f(-0.6f,-1.5f);
    glVertex2f(-0.6f,-1.2f);
    glEnd();
}
  glBegin(GL_QUADS);
{
    glColor3f(0.6f, 0.8f, 1.0f); ///blue glass    (1/255)*X  {if its 153 then (1/255)*153}
    glVertex2f(0.15f,-1.2f);
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.45f,-1.2f);
    glEnd();
}
glLineWidth(1.2);
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.15f,-01.2f);
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.45f,-01.2f);
    glEnd();
}
glBegin(GL_LINE_LOOP);
{
  glColor3f(0.0f,0.0f,0.0f); ///black border around glasses
    glVertex2f(0.0f,-.98f);
    glVertex2f(-0.35f,-.98f);
    glVertex2f(-0.35f,-01.2f);
    glVertex2f(0.0f,-01.2f);
    glEnd();
}

glColor3f(0.0f,0.0f,0.0f);
   GLfloat xbp=0.05f; GLfloat ybp=-1.5f;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radiusb * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radiusb * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
    GLfloat pbp=-0.35f; GLfloat qbp=-1.5f;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radb * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radb * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xbp, ybp);
		for(ib = 0; ib <= triangleAmountb;ib++)
            {
			glVertex2f(
                xbp + (radi * cos(ib *  twicePib / triangleAmountb)),
			    ybp + (radi * sin(ib * twicePib / triangleAmountb))
			          );
            }
	glEnd();


   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(pbp, qbp);
		for(jb = 0; jb <= triangleAmtb;jb++)
            {
			glVertex2f(
                pbp + (radi * cos(jb *  twicepib / triangleAmtb)),
			    qbp + (radi * sin(jb * twicepib / triangleAmtb))
			          );
            }
	glEnd();

glPopMatrix();


glutTimerFunc(2000,displayMorningToNoon,0);
	glFlush();

}




int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(1200,960);
    glutCreateWindow("City View");
    glutDisplayFunc(displayMorning);
   glutTimerFunc(1, updateCloud, 0);
    glutTimerFunc(1, updateCar1, 0);
     glutTimerFunc(1, updateCar2, 0);
     glutTimerFunc(1, updateTrain, 0);
      glutTimerFunc(1, updateBus, 0);
      soundtraffic();
    glutTimerFunc(1, updateNCar1, 0);
    glutTimerFunc(1, updateBoat, 0);
    glutTimerFunc(1, updateBoat1, 0);
    glutTimerFunc(1, updateSun, 0);
    glutTimerFunc(1, updateMoon, 0);
    glutTimerFunc(1, updateRain, 0);
glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}
