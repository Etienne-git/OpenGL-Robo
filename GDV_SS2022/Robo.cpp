// GD-Praktikum:   teil_1_kamera.cpp  (Teil 2: Szenegraph und Animationen)
// Hergenroether / Groch / Froemmer    Last Update: 26.04.2021

#include <iostream> 
#include <GL/freeglut.h>         //ldt alles fr OpenGL

#include "Wuerfel.h"

bool reverse = false;

static int leg1Degree = 45;
static int leg2Degree = -45;

static int shoulder1Degree = 45;
static int shoulder2Degree = -45;

static double arm1Degree = -90;
static int arm2Degree = 0;

void Init()
{
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgefhrt werden mssen	
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
}

void RenderScene() //Zeichenfunktion
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0, 0.0, 1.0, 1.0);
	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen


	// Kameraposition, Blickwinkel und Up-Vector
	gluLookAt(1., 1., 1., 0., 0., 0., 0., 1., 0.); // extrinsische Kameraparameter

	//Torso
	Wuerfel(0.25, 0.5, 0.25);

	//Leg1
	glPushMatrix();
	glTranslatef(0.4, -0.5, 0.0);
	glRotatef(leg1Degree, -0.4, 0.0, 0.0);
	glTranslatef(0.0, -0.3, 0.0);
	Wuerfel(0.25, 0.6, 0.25);
	glPopMatrix();

	//Leg2
	glPushMatrix();
	glTranslatef(-0.4, -0.5, 0.0);
	glRotatef(leg2Degree, -0.4, 0.0, 0.0);
	glTranslatef(0.0, -0.3, 0.0);
	Wuerfel(0.25, 0.6, 0.25);
	glPopMatrix();

	//arm1.1
	glPushMatrix();
	glTranslatef(0.75, 0.5, 0.25);
	glRotatef(shoulder1Degree, -0.75, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	Wuerfel(0.25, 0.3, 0.25);
	//arm1.2
	glTranslatef(0, -0.5, 0.0);
	glRotatef(arm1Degree, 1, 0.0, 0.0);
	glTranslatef(0, -1, 0.0);
	Wuerfel(1, 1.5, 0.5);
	glPopMatrix();

	//arm2.1
	glPushMatrix();
	glTranslatef(-0.75, 0.5, 0.0);
	glRotatef(shoulder2Degree, -0.75, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	Wuerfel(0.25, 0.3, 0.25);
	//arm2.2
	glTranslatef(0, -0.5, 0.0);
	glRotatef(arm2Degree, 1, 0.0, 0.0);
	glTranslatef(0, -1, 0.0);
	Wuerfel(1, 1.5, 0.5);
	glPopMatrix();

	//Head
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	Wuerfel(0.5, 0.5, 0.5);
	glPopMatrix();

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Hier finden die Reaktionen auf eine Vernderung der Gre des 
	// Graphikfensters statt

	 // Matrix fuer Transformation: Frustum -> viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Kamera definieren (intrinsische Kameraparameter)
	//glOrtho(-1., 1., -1., 1., 0., 10.); // orthogonale Kamera
	gluPerspective(45., 1, 0.1, 10.); // perspektivische Kamera
	// Matrix fuer Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);
}

void Animate(int value)
{
	// Hier werden Berechnungen durchgefhrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess luft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	std::cout << "value=" << value << std::endl;

	//leg 1
	if (leg1Degree >= -45 && reverse == false)
	{
		leg1Degree = leg1Degree - 1;
		leg2Degree = leg2Degree + 1;

		shoulder1Degree = shoulder1Degree - 1;
		shoulder2Degree = shoulder2Degree + 1;

		arm1Degree = arm1Degree + 1;
		arm2Degree = arm2Degree - 1;
	}
	else {
		reverse = true;
	}

	if (leg1Degree <= 45 && reverse)
	{
		leg1Degree = leg1Degree + 1;
		leg2Degree = leg2Degree - 1;

		shoulder1Degree = shoulder1Degree + 1;
		shoulder2Degree = shoulder2Degree - 1;

		arm1Degree = arm1Degree - 1;
		arm2Degree = arm2Degree + 1;
	}
	else {
		reverse = false;
	}



	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);         // Fenster-Konfiguration
	glutCreateWindow("Philipp Pulver");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}
