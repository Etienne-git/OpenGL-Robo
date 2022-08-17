// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h> 
#include "Wuerfel.h"//lädt alles für OpenGL

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
}

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   //body
   glPushMatrix();
   glScalef(0.5, 1., 1.);
   Wuerfel(0.8);
   glPopMatrix();
   //right arm
   glPushMatrix();
   glTranslatef(0.3, -0.2, 0.);
   glScalef(0.1, 0.45, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.3, 0.2, 0.);
   glScalef(0.1, 0.45, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   //left arm
   glPushMatrix();
   glTranslatef(-0.3, -0.2, 0.);
   glScalef(0.1, 0.45, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(-0.3, 0.2, 0.);
   glScalef(0.1, 0.45, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   //left leg
   glPushMatrix();
   glTranslatef(-0.1, -0.7, 0.);
   glScalef(0.1, 0.6, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   //right leg
   glPushMatrix();
   glTranslatef(0.1, -0.7, 0.);
   glScalef(0.1, 0.6, 1.);
   Wuerfel(0.8);
   glPopMatrix();
   //head
   glPushMatrix();
   glTranslatef(0., 0.55, 0.);
   glScalef(1., 1., 1.);
   Wuerfel(0.2);
   glPopMatrix();
   

   //Wuerfel(0.5, 1.0, 0.5);
   /*glBegin(GL_POLYGON);
        glColor4f(1.0, 0.0, 0.0, 1.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5,  0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex3f(-0.5, -0.5, -0.5);
   glEnd();
   glBegin(GL_TRIANGLES);
        glColor4f(0.0, 1.0, 0.0, 1.0);
        //E
        glVertex3f(-0.35, -0.35, -0.5);
        glVertex3f(-0.25, -0.35, -0.5);
        glVertex3f(-0.25, 0.35, -0.5);

        glVertex3f(-0.35, -0.35, -0.5);
        glVertex3f(-0.25, 0.35, -0.5);
        glVertex3f(-0.35, 0.35, -0.5);
      
        glVertex3f(0.0, 0.25, -0.5);
        glVertex3f(0.0, 0.35, -0.5);
        glVertex3f(-0.25, 0.35, -0.5);

        glVertex3f(-0.25, 0.25, -0.5);
        glVertex3f(0.0, 0.25, -0.5);
        glVertex3f(-0.25, 0.35, -0.5);

        glVertex3f(0.0, 0.05, -0.5);
        glVertex3f(-0.25, -0.05, -0.5);
        glVertex3f(0.0, -0.05, -0.5);
        
        glVertex3f(-0.25, -0.05, -0.5);
        glVertex3f(0.0, 0.05, -0.5);
        glVertex3f(-0.25, 0.05, -0.5);

        glVertex3f(-0.25, -0.35, -0.5);
        glVertex3f(0.0, -0.35, -0.5);
        glVertex3f(0.0, -0.25, -0.5);

        glVertex3f(-0.25, -0.35, -0.5);
        glVertex3f(0.0, -0.25, -0.5);
        glVertex3f(-0.25, -0.25, -0.5);
        

        //G
        glVertex3f(0.05, 0.35, -0.5);
        glVertex3f(0.35, 0.25, -0.5);
        glVertex3f(0.35, 0.35, -0.5);

        glVertex3f(0.05, 0.35, -0.5);
        glVertex3f(0.05, 0.25, -0.5);
        glVertex3f(0.35, 0.25, -0.5);

        glVertex3f(0.05, 0.25, -0.5);
        glVertex3f(0.15, -0.35, -0.5);
        glVertex3f(0.15, 0.25, -0.5);

        glVertex3f(0.05, -0.35, -0.5);
        glVertex3f(0.15, -0.35, -0.5);
        glVertex3f(0.05, 0.25, -0.5);

        glVertex3f(0.35, -0.25, -0.5);
        glVertex3f(0.05, -0.35, -0.5);
        glVertex3f(0.35, -0.35, -0.5);
       
        glVertex3f(0.05, -0.35, -0.5);
        glVertex3f(0.35, -0.25, -0.5);
        glVertex3f(0.05, -0.25, -0.5);
       
        glVertex3f(0.35, -0.25, -0.5);
        glVertex3f(0.25, -0.05, -0.5);
        glVertex3f(0.25, -0.25, -0.5);

        glVertex3f(0.35, -0.05, -0.5);
        glVertex3f(0.25, -0.05, -0.5);
        glVertex3f(0.35, -0.25, -0.5);

        glVertex3f(0.25, -0.05, -0.5);
        glVertex3f(0.175, -0.05, -0.5);
        glVertex3f(0.25, -0.15, -0.5);

        glVertex3f(0.175, -0.05, -0.5);
        glVertex3f(0.175, -0.15, -0.5);
        glVertex3f(0.25, -0.15, -0.5);
   glEnd();
   */
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
   // Graphikfensters statt
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   std::cout << "value=" << value << std::endl;
   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value); //value der im Konsolenfenster ausgegeben wird
}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren mit command line Argumenten
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB ); //Darstellungsmodus double buffering und RGB Farben
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration mit Größe 600 * 600
   glutCreateWindow( "Etienne_Gotha; Name_2" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );             // Wird aufgerufen(callback), wenn die Fenstergröße mit der Maus angepasst wird,
                                           // dann wird die Reshape Funktion aufgerufen
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);  //Timer, der immer nach 10sec die Animate Funktion aufruft(callback)
   Init(); 
   glutMainLoop(); //Startet den Glut event processing mode, also startet Fenster und Graphiken mit den vorgegebene Einstellungen
   return 0;
}
